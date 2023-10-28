'''
Listas em Python
Tipo list - Mutável
Suporta vários valores de qualquer tipo
Conhecimentos reutilizáveis - índices e fatiamento
Métodos úteis: 
    append, insert, pop, dek, clear, extend, +
Create Read Update   Delete (CRUD)
Criar, ler, alterar, apagar = lista[i] 
'''
#........1...2....3....4
lista = [10 ,20 , 30 ,40]

lista[2] = 300  #Update
print(lista)
print(lista[2])

del lista[2]  #apaga o elemento do índice
print(lista)
print(lista[2])

lista.append(50)  #Acrescenta elementos no final da lista.
print(lista)

ultimo_valor = lista.pop()  #Remove o último elemento da lista.
print(lista, 'Removido', ultimo_valor)

lista.clear()  # limpa a lista
print(lista)

lista.insert(0, 5)  #adiciona o 5 no índice 0
print(lista)

print(80*'-')

lista_a = [1, 2, 3 ,4]
lista_b =[4, 5, 6]
lista_c = lista_a + lista_b  # União das listas
lista_a.extend(lista_b)  #Une as listas mas não retorna valor

print(f'{lista_c = }')
print(f'{lista_a = }')