import pprint

def p(v):
    pprint.pprint(v, sort_dicts=False, width=40)

border = 50*'-'
"""
O filtro serve como o nome diz para filtrar dados.
Nesse caso, estamos excluindo números maiores que 5:
"""
lista = [n for n in range (10) if n < 5]
print(lista)

produtos = [
    {'nome': 'p1', 'preco': 20, },
    {'nome': 'p2', 'preco': 10, },
    {'nome': 'p3', 'preco': 30, },
]

print(border)

novos_produtos = [
    {**produto, 'preco': produto['preco'] * 1.05}
    # Aqui estamos mundando o preço apenas dos produtos mais caros que 20
    if produto ['preco'] > 20 else {**produto}
    #Colocamos agora a condição para filtrar elementos mais baratos q 10
    for produto in produtos
    if produto['preco'] > 10
]

p(novos_produtos)