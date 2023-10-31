""" 
Dict comp e set comp
"""

produto = { 
    'nome': 'Caneta azul',
    'preco': 2.5,
    'categoria': 'Escritório'
}

dc = {
    chave: valor
    if isinstance(valor, (int, float)) else valor.upper()  #ternário
    for chave, valor 
    in produto.items()
    if chave != 'categoria'  # filter
}

print(dc)

print()
lista = [
    ('a', 'valor a'),
    ('b', 'valor a'),
    ('c', 'valor a'),
]

# Transformamos uma lista num dict

dc = {
    chave: valor 
    for chave, valor 
    in lista
}

print(dc)
print(50*'-')
# set comp:

s1 = {i ** 2 for i in range(10)}

print(s1)