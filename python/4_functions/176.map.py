# map para mapear dados

from functools import partial

def print_iter(iterator):
    print(*list(iterator), sep='\n')
    print()

def aumentar_porcentagem(valor, porcentagem):
    return round(valor * porcentagem)

produtos = [
    {'nome': 'Produto 5', 'preco': 10.00},
    {'nome': 'Produto 1', 'preco': 22.32},
    {'nome': 'Produto 3', 'preco': 10.11},
    {'nome': 'Produto 2', 'preco': 105.87},
    {'nome': 'Produto 4', 'preco': 69.90},
]

aumentar_dez_porcento = partial(
    aumentar_porcentagem,
    porcentagem=1.1
)


# novos_produtos = [
#     {**p,  # Duas estrelas para expandir as chaves também
#       'preco': aumentar_porcentagem(
#         valor=p['preco'], porcentagem=1.1)}  # Aqui estamos sobreescrevendo as chaves 'preco' dos produtos
#     for p in produtos 
# ]
""" Em vez disso, podemos usar a função 'map' """

def muda_preco_de_produtos(produto):
    return {
        **produto,
        'preco': aumentar_dez_porcento(
            produto['preco']
        )
    }

novos_produtos = list(map(  # Como map é um iterator, temos que converter como lsita para podermos reutilizar.
    muda_preco_de_produtos,
    produtos
))

print(
    list(map(
    lambda x: x * 3,
    [1,2,3,4]
    ))
)
print()

print_iter(produtos)
print(novos_produtos)
print_iter(novos_produtos)
print('Usando a lista de novo, pois ela não se esgotou devido ao list type convertion')
print_iter(novos_produtos)
