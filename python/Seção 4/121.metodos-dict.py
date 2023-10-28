'''
Métodos úteis dos dicionários em Python:

# len - quantas chaves
# keys - iterável com as chaves
# values - iterável com os valores
# items - iterável com chaves e valores
# setdefault - adiciona valor se a chave não existe
# copy - retorna uma cópia rasa (shallow copy)
# get - obtém uma chave
# pop - Apaga um item com a chave especificada (del)
# popitem - Apaga o último item adicionado
# update - Atualiza um dicionário com outro
'''

pessoa = {
    'nome': 'Luiz Otávio',
    'sobrenome': 'Miranda',
}

print(pessoa.keys(), type(pessoa.keys()))  
print(list(pessoa.values()))



for chave, valor in pessoa.items():
    print(chave, valor)  # Similar ao enumerate

# setdefault, se a chave não existe, ela coloca

pessoa.setdefault('idade', 0)
print(pessoa['idade'])

print(20*'-')

print(pessoa.get('nome'))
print(pessoa.get('nao existe'))

nome = pessoa.pop('nome')  #Retorna a chave e elimina ela.

print(pessoa)
pessoa.update({
    'nome': 'novo valor',
    'nova chave': '30',
})

# podemos usar como argumento:
# pessoa.update(nome='novo valor', idade=30)
# ou com tuplas ou lista:
# tupla = (('nome', 'novo valor'), ('idade' 30))
# lista = [['nome', 'novo valor', ['idade', 30]]]
# pessoa.update(tupla)
# pessoa.update(lista)


print(pessoa)





#---------- Shalow copy e deep copy-------------------------#
print('\n', 'shalow copy e deep copy:', '\n')

d1 = {
    'c1': 1,
    'c2': 2,
    'l1': [0, 1, 2]
}

d2 = d1.copy()  # Copia (apenas dados imutaveis) d1 e alterações em d2 não afetam d2

d2['c1'] = 1000

print(d1)
print(d2)

# para copiar todos os dados usamos a deep copy importando copy e usando
# .deepcopy

import copy

d2=copy.deepcopy(d1)

