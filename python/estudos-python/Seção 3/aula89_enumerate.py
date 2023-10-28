'''
enumarate = enumere iteráveis (indices)
'''
lista = ['Maria', 'Helena', 'Luiz','batata' ,'abacaxi']
lista.append('João')


# Enumerate é um Iterator , para
lista_enumarada = enumerate(lista)  
print(lista_enumarada, type(lista_enumarada),end=2*'\n')
#podemos usar o for para o enumrate
for item in lista_enumarada:
    print(item)

print(20*'-')
print(list(lista_enumarada), end=2*'\n')  
# Note que o 'for' zerou os itens da lista

#Para contornar o seguinte problema não colocaremos o enumerate numa
#variável. Em vez disso escrevemos direto na função:

for item in enumerate(lista):
    print('for 1', item)
    
print()

for item in enumerate(lista):
    print('for 2', item)

#Se quisermos printar, podemos fazer type conversion:

print(list(enumerate(lista, 19)),2*'\n')  #coloca o primeiro índice para ser o 19

#podemos fazer desempacotamento também:

# for tupla_enumerada in enumerate(lista):
#     print('For da tupla: ')
#     for valor in tupla_enumerada:
#         print(valor)

for indice, nome in enumerate(lista):
    print(indice, nome)