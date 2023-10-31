# Reduce faz a a redução de um iterável em um púnico valor
# A função reduce sempre retorna o acmulador e o item que ela está iterando.

from functools import reduce


def funcao_do_reduce(acumulador, produto):
    print('acumulador', acumulador)
    print('produto', produto)
    print()
    return acumulador + produto['preco']  # Aqui estamos somando os preços


produtos = [
    {'nome': 'Produto 5', 'preco': 10.00},
    {'nome': 'Produto 1', 'preco': 22.32},
    {'nome': 'Produto 3', 'preco': 10.11},
    {'nome': 'Produto 2', 'preco': 105.87},
    {'nome': 'Produto 4', 'preco': 69.90},
]


total = reduce(
    funcao_do_reduce,
    produtos,  # iterável
    0  # Valor inicial do acumulador, isso ajuda a delimitar o tipo do dado que estamos trabalhando
)

""" Usando a função lambda fica mais fácil: """

total_lambda = reduce(
    lambda acumulador, p: acumulador + p['preco'],
    produtos,
    0
)

print('Total é', total)
print()
print('Com lambda:', total_lambda)

""" Ou podemos fazer da seguinte forma também: """
# total = 0
# for p in produtos:
#     total += p['preco']

# print(total)
