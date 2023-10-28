"""
Considerando duas listas de inteiros ou floats (lista A e lista B)
Some os valores nas listas retornando uma nova lista com os valores somados:
Se uma lista for maior que a outra, a soma só vai considerar o tamanho da
menor.
Exemplo:
=================== resultado
lista_a     = [1, 2, 3, 4, 5, 6, 7]
lista_b     = [1, 2, 3, 4]
lista_soma  = [2, 4, 6, 8]
"""
import modulo_package

lista_a     = [1, 2, 3, 4, 5, 6, 7]
lista_b     = [1, 2, 3, 4]

@modulo_package.decorator
def zipper_sum(shorter_list, another_list):
    sum_list = [
        x + y
        for x, y in zip(shorter_list, another_list)
    ]
    
    return sum_list

print(zipper_sum(lista_a, lista_b))
