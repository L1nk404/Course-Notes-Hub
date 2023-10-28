"""
Introdução ist comprehension em Python
List comprehension é uma forma rápida de criar listas a partir de 
iteráveis
"""

# print(list(range(10)))
""" 
Suponha que queremos gerar a lista acima:
"""

lista = []
for numero in range(10):
    lista.append(numero)
# print(lista)

"""
Podemos usar list comprehension para fazer o mesmo que essas 4 linhas de 
código:
Colocamos o que nós queremos que o 'for' adicione a lista
"""

lista = [
    numero * 2
    for numero in range(10)
    ]

print(lista)




