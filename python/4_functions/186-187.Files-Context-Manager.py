""" 
Criando arquivos com Python:

Usamos a função open para abrir um arquivo em Python (ele pode ou não
existir).

# Modos:

r (leitura), w (escrita), x (para criação)
a (escreve ao final), b (binário)
t (modo texto), + (leitura e escrita)

# Context manager - with (abre e fecha)

Métodos úteis:
- write, read (escrever e ler)
- write lines (escrever várias linhas)
- seek (move o cursor)
- readline (ler linhas)

# Módulo os:
- os.rename - troca o nome ou move o arquivo
- os.remove ou unlink - apaga o arquivo

# json:
- json.dump = gera um arquivo json
- json.load

"""

file_path = 'python\\4_functions\\aula186.txt'

# file = open(file_path, 'w')

# file.close()  # Lembre-se de sempre fechar o arquivo!!!

# Podemos usar o Context Manager "with open" para abrir e fechar:

with open(file_path, 'w+') as arquivo:  # w+ para ativar leitura e escrita
    arquivo.write('Linha 1\n')
    arquivo.write('Linha 2\n')
    arquivo.writelines(  # Escreve várias linhas
        ('linha 3\n', 'linha 4\n')
    )
    # Temos que mover o cursos (do python) para o ínicio do arquivo
    # para ele ler o arquivo todo
    arquivo.seek(0, 0)
    print(arquivo.read())
    print('Lendo')
    arquivo.seek(0, 0)
    # Fazemos (end='') isso para evitar quebra de linha do print
    print(arquivo.readline(), end='')
    print(arquivo.readline(), end='')


print()
print(40*'#')
print()
