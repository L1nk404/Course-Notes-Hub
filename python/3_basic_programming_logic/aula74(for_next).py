'''
Como o for funciona:
Iterável -> str, range, etc (__iter__) é o elemento que tem os elementos.
Iterador -> quem sabe entregar um valor por vez
next -> me entregue o próximo valor (__next__)
iter -> me entregue seu iterador
'''

# texto = iter('Luiz')  #__iter__()

# print(next(texto))
# print(next(texto))
# print(next(texto))
# print(next(texto))


#for letra in texto:  #  Faremos essa mesma função, usando while
texto = 'Luiz'  # iterável
iterator = iter(texto)  # iterator

while True:
    try:
        letra = next(iterator)
        print(letra)
    except  StopIteration:
        break
