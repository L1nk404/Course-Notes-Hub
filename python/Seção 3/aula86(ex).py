'''
Exercício
Exiba os índices da lista
0 Maria
1 Helena
2 Luiz
'''
lista = ['Maria', 'Helena', 'Luiz', True]

i=0

for valor in lista:
    print(i, lista[i], type(lista[i]))

    i += 1
