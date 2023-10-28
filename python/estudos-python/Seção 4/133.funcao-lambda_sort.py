"""
Função lambda em Python:

A função lambda é uma função qualquer como qualquer outra em Python. 
Porém, são funções anônimas que contém apenas uma linha. Ou seja, tudo
deve ser contido dentro de uma única expressão.
"""

lista = [
    {'nome': 'Luiz', 'sobrenome': 'miranda'},
    {'nome': 'Maria', 'sobrenome': 'Oliveira'},
    {'nome': 'Daniel', 'sobrenome': 'Silva'},
    {'nome': 'Eduardo', 'sobrenome': 'Moreira'},
    {'nome': 'Aline', 'sobrenome': 'Souza'},
]

# lista = [4, 32, 1, 34, 5, 6, 6, 21, ]
# lista.sort(reverse=True)  #ordena a lista, uso revere para ordenar
#                           # de trás pra frente

"""
O Python não sabe ordernar listas, para isso precisamos ensiná-lo e 
dizer como queremos que seja ordenada. Podemos criar a seguinte função:
"""

# def ordena(item):
#     # Pedimos para o Python organizar por nome
#     return item['nome']

"""
Dada essa função usamos sort e passamos a key, que no caso é uma função
que dirá como será ordenada:
'Em resumo, o parâmetro "key" permite personalizar a ordenação dos 
 elementos com base em uma função de chave'
"""

# lista.sort(key=ordena)

# for item in lista:
#     print(item)

"""
Entretanto, existe uma forma mais prática de fazer a mesma coisa sem 
ter que definir uma função dessa forma.
É ai que entra a função lambda para definir uma função em uma única linha:
"""

lista.sort(key=lambda item: item['nome'])

for item in lista:
    print(item)

print(50*'-')

"""
Em vez de mexermos na lista original, podemos criar uma cópia rasa da 
lista usando sorted:
"""

l1 = sorted(lista, key=lambda item: item['sobrenome'])

for item in l1:
    print(item)