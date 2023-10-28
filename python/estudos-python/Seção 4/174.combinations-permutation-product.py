'''
Combinations, Permutations e Product - Itertools
Combinação - Ordem não importa - iterável + tamanho do grupo
Permutação - ORdem importa
Produto = Ordem importa e repete valores únicos
'''
def print_iter(iterator):
    print(*list(iterator),sep='\n')
    print()

from itertools import combinations
from itertools import permutations
from itertools import product

pessoas = [
    'João', 'Joana', 'Luiz', 'Letícia'
]
camisetas = [
    ['preta', 'branca'],
    ['p', 'm', 'g'],
    ['masculino', 'feminino'],
    ['listrada', 'lisa']
]

combinacao = combinations(pessoas, 2)  # combinação das pessoas em grupos de 2
# print_iter(combinacao)

permutacao = permutations(pessoas, 2)
# print_iter(permutacao)

produto = product(*camisetas)

print_iter(produto)