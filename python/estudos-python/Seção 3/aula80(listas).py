'''
Listas em Python
Tipo list - Mutável
Suporta vários valores de qualquer tipo
Conhecimentos reutilizáveis - índices e fatiamento
Métodos úteis: append, insert, pop, dek, clear, extend +
'''
#.........01234
#........-54321
string = 'ABCDE'  # 5 caracteres (len)
lista = [123, True, 'Link', 1.2, []]  #posso colocar vários valores de qualuer tipo

print(bool(lista))  # falsy se vazia
print(lista, type(lista))

#.........0.....1......2.....3....4   (indíces)
#........-5....-4.....-3....-2...-1
lista = [123, True, 'Link', 1.2, []]  #posso colocar vários valores de qualuer tipo
print('item no índice 2: ',lista[2])  #podemos acessar os índices

# podemos também mudar o elemento da lista:
lista [2] = 'Maria'
print('item no índice 2: ',lista[2]) 
