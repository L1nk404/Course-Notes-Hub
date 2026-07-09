Guia de referência com comandos e ferramentas para investigar e liberar espaço em disco via terminal.
## Índice

- [[#Diagnóstico rápido]]
- [[#du - Uso de disco por pasta]]
- [[#df - Uso de disco por partição]]
- [[#ncdu - Navegador visual de espaço]]
- [[#Btrfs - Comandos específicos]]
- [[#Snapper - Gerenciamento de snapshots]]
- [[#Armadilhas comuns]]
- [[#Limpeza geral do sistema]]
- [[#Checklist de investigação]]

---
## Diagnóstico rápido

Ordem recomendada quando o disco está cheio:

1. `df -h` → confirmar qual partição está cheia
2. `du`/`ncdu` → tentar achar pastas grandes
3. Se o sistema for **Btrfs** → não confiar cegamente no `du`/`ncdu` (ver seção própria)
4. Verificar journal, cache de pacotes, containers/VMs
5. Verificar arquivos deletados ainda abertos por processos

---
## `du` - Uso de disco por pasta

```bash
# Tamanho total de uma pasta específica
du -sh /caminho/da/pasta

# Tamanho de cada subpasta de primeiro nível
du -h --max-depth=1 /caminho

# Ordenado do maior para o menor
du -h --max-depth=1 /caminho | sort -rh

# Não atravessar para outros filesystems/mount points (evita contar snaps, /proc, etc)
du -h -x --max-depth=1 /
```

> [!warning] Cuidado com `-x` em sistemas com bind mounts Se `/home`, `/var`, `/opt` etc. forem **mount points separados** da mesma partição (comum em instalações com subvolumes), o `-x` vai _pular_ essas pastas e mascarar onde está o uso real. Nesse caso, rode o `du` **sem `-x`**, pasta por pasta, especificamente nesses mount points.

---
## `df` - Uso de disco por partição

```bash
# Visão geral, formato legível
df -h

# Ver tipo de sistema de arquivos (ext4, xfs, btrfs...)
df -hT

# Ver inodes (quando "sem espaço" mas du/df mostram espaço livre)
df -i
```

|Coluna|Significado|
|---|---|
|Size|Tamanho total|
|Used|Espaço usado|
|Avail|Espaço disponível|
|Use%|Porcentagem usada|
|Mounted on|Ponto de montagem|

> [!tip] `du` vs `df` `du` mede pastas/arquivos. `df` mede a partição/disco inteiro. Quando os dois **não batem** (df mostra muito mais usado que a soma do du), é sinal de: arquivo deletado ainda aberto por um processo, ou peculiaridade do sistema de arquivos (ex: Btrfs com snapshots).

---
## `ncdu` - Navegador visual de espaço

Interface interativa em modo texto, navegação com setas — muito mais rápido que rodar `du` repetidamente.

```bash
# Instalar
sudo apt install ncdu        # Debian/Ubuntu
sudo zypper install ncdu     # openSUSE

# Rodar (sempre com sudo para ver tudo corretamente)
sudo ncdu -x /
```

> [!warning] Rodar sem `sudo` mascara resultados Pastas do sistema sem permissão de leitura aparecem com erro (`!` ou `e` na interface) e são subcontadas ou ignoradas — sempre rode com `sudo` para um diagnóstico confiável.

> [!danger] ncdu e Btrfs não se misturam bem Em sistemas Btrfs com snapshots, o `ncdu` conta o tamanho **aparente** de cada arquivo em cada snapshot, sem saber que várias snapshots compartilham os mesmos blocos físicos (CoW). Isso pode fazer `/.snapshots` aparecer com **terabytes**, mesmo que o disco inteiro tenha poucos GB reais ocupados por elas. Ver seção Btrfs abaixo.

---
## Btrfs - Comandos específicos

Sistemas com Btrfs (padrão no openSUSE, comum no Fedora) usam **Copy-on-Write (CoW)**: snapshots não duplicam dados, apenas referenciam os mesmos blocos físicos. Isso quebra a lógica de ferramentas tradicionais como `du`.

### Ver uso real do filesystem

```bash
sudo btrfs filesystem usage /
```

Campos importantes:

- **Device allocated**: espaço que o btrfs reservou (pode ser maior que o usado)
- **Used**: espaço realmente ocupado por dados
- **Unallocated**: espaço livre não reservado ainda

### Ver tamanho exclusivo vs compartilhado de snapshots

```bash
sudo btrfs filesystem du -s /.snapshots/*/snapshot
```

- **Total**: tamanho aparente (inclui blocos compartilhados com outras snapshots)
- **Exclusive**: espaço que seria **realmente liberado** se aquela snapshot fosse apagada
- **Set shared**: blocos compartilhados com outras snapshots/subvolumes

> [!tip] O que realmente importa Para decidir o que apagar, olhe a coluna **Exclusive**, não a Total. Uma snapshot pode aparecer com "11GB total" mas ter "0B exclusive" — ou seja, apagá-la não libera nada, porque os dados ainda existem em outras snapshots.
### Ver todos os subvolumes (montados ou não)

```bash
sudo btrfs subvolume list -a /
```

Útil para achar subvolumes "órfãos" criados por Docker, libvirt, Distrobox, etc, que não aparecem na árvore normal de pastas.
### Ver subvolumes marcados para deleção (limpeza pendente)

```bash
sudo btrfs subvolume list -d /
```

Se vier vazio, não há limpeza pendente. Se vier com entradas, o kernel ainda está processando a exclusão de snapshots em segundo plano — isso pode levar minutos a horas.
### Qgroups (uso exclusivo detalhado, requer quotas ativadas)

```bash
sudo btrfs quota enable /
sudo btrfs qgroup show -pc / | sort -k3 -rh | head -20
```
### Balance (consolidar blocos vazios e liberar espaço alocado)

```bash
# Rebalanceia apenas blocos de dados 100% vazios (seguro e rápido)
sudo btrfs balance start -dusage=0 /

# Ver progresso
sudo btrfs balance status /

# Cancelar se necessário
sudo btrfs balance cancel /
```

> [!note] Por que o espaço não aparece na hora Deletar uma snapshot (`snapper delete`) não libera espaço instantaneamente. O kernel processa a remoção dos blocos em segundo plano (**cleaner thread**). Em sistemas com muitas snapshots acumuladas (meses de updates), isso pode demorar bastante. Rodar `sync` ou reiniciar o sistema costuma forçar a finalização.

---
## Snapper - Gerenciamento de snapshots

Ferramenta padrão no openSUSE (e disponível em outras distros) para gerenciar snapshots Btrfs, geralmente criadas automaticamente antes/depois de cada atualização (`zypper`).

```bash
# Listar todas as snapshots
sudo snapper list

# Apagar uma snapshot específica
sudo snapper delete <numero>

# Apagar um intervalo
sudo snapper delete <inicio>-<fim>

# Ver configurações existentes
sudo snapper list-configs
```

> [!warning] Não é possível apagar a snapshot 0 (current) A snapshot `0` representa o sistema atual em execução — não pode ser deletada.
### Configurar retenção automática (evitar acúmulo futuro)

Edite `/etc/snapper/configs/root` e ajuste:

```
NUMBER_LIMIT="10"
NUMBER_LIMIT_IMPORTANT="10"
TIMELINE_LIMIT_HOURLY="5"
TIMELINE_LIMIT_DAILY="7"
TIMELINE_LIMIT_MONTHLY="3"
TIMELINE_LIMIT_YEARLY="0"
```

Depois, force a limpeza baseada nas regras:

```bash
sudo snapper cleanup number
sudo snapper cleanup timeline
```

---
## Armadilhas comuns

### Arquivo deletado, mas espaço não liberado

Acontece quando um processo ainda tem o arquivo aberto (file handle), mesmo após ele ser removido do sistema de arquivos. O espaço só é liberado quando o processo fecha ou é reiniciado.

```bash
# Localizar arquivos deletados ainda abertos por processos
sudo find /proc/*/fd -ls 2>/dev/null | grep '(deleted)' | sort -rn -k7 | head -10
```

> [!tip] `memfd` não conta Entradas como `/memfd:algo (deleted)` são segmentos de memória compartilhada (RAM), não arquivos em disco — podem ser ignoradas nesse contexto.

### `df` mostra disco cheio, mas `du` não acha nada

Possíveis causas, em ordem de probabilidade:

1. Snapshots do Btrfs ainda sendo processadas (cleaner)
2. Arquivo grande deletado mas ainda aberto por processo
3. Subvolume existente mas não montado na árvore atual (containers/VMs)
4. `du` rodado sem permissão suficiente (sempre use `sudo`)

---
## Limpeza geral do sistema

```bash
# Cache de pacotes (apt)
sudo du -sh /var/cache/apt/archives
sudo apt clean

# Cache de pacotes (zypper)
sudo du -sh /var/cache/zypp
sudo zypper clean

# Logs do systemd journal
journalctl --disk-usage
sudo journalctl --vacuum-size=500M    # limita o tamanho total
sudo journalctl --vacuum-time=2weeks  # limita por idade

# Revisões antigas de pacotes Snap
snap list --all | awk '/disabled/{print $1, $3}' | \
    while read snapname revision; do
        sudo snap remove "$snapname" --revision="$revision"
    done

# Limitar snap a manter só as 2 últimas revisões
sudo snap set system refresh.retain=2

# Docker (imagens, containers e volumes não usados)
docker system df
docker system prune -a

# Cache do usuário e lixeira
du -sh ~/.cache ~/.local/share/Trash 2>/dev/null
rm -rf ~/.local/share/Trash/*
```

---
## Checklist de investigação

- [ ] `df -h` — identificar a partição cheia
- [ ] Confirmar se há mount points/bind mounts na mesma partição (ex: `/home`, `/var`, `/opt` todos no mesmo device)
- [ ] `sudo ncdu -x /` — navegar visualmente (sempre com sudo)
- [ ] Se for Btrfs: `sudo btrfs filesystem usage /` para ver uso real
- [ ] Se for Btrfs: checar snapshots com `snapper list` e `btrfs filesystem du -s`
- [ ] Checar `journalctl --disk-usage`
- [ ] Checar cache de pacotes (`apt`/`zypper`)
- [ ] Checar containers/VMs (Docker, libvirt, Distrobox)
- [ ] Checar arquivos deletados ainda abertos (`find /proc/*/fd`)
- [ ] Depois de qualquer limpeza pesada: `sync` ou reiniciar para garantir que o espaço foi realmente devolvido

---

_Criado a partir de uma sessão de troubleshooting real em openSUSE Tumbleweed (Btrfs + Snapper)._