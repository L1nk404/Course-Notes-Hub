# Manipulando chaves e valores em dicionário    
pessoa = {}

# Usamos variável para criar uma chave dinâmica.
chave = 'nome_completo'


pessoa[chave] = 'Maria'
pessoa['sobrenome'] = 'miranda'
lista = []


print(pessoa)
# Usamos del para apagar uma chave
del pessoa['sobrenome']
print(pessoa)

# Para checarmos se a chave existe usamos .get

if pessoa.get('sobrenome') is None:  # por padrão se não existe, é None
    print('Não existe')
else:
    print(pessoa['sobrenome'])