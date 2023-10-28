import copy

import dados
# podemos usar from dados import produtos


def border():
    print(50*'-')



"""
copy, sorted, produtos.sort
Exercícios
Aumente os preços dos produtos a seguir em 10%
Gere novos_produtos por deep copy (cópia profunda)
"""
# Vamos desempacotar o dicionário usando ** e alterar o preco
novos_produtos = [
    {**produto, 'preco': round(produto['preco'] * 1.1, 2)}  #round arredonda o numero
    for produto in copy.deepcopy(dados.produtos)
    ]

print(*novos_produtos, sep='\n')

border()

"""
Ordene os produtos por nome decrescente (do maior para menor)
Gere produtos_ordenados_por_nome por deep copy (cópia profunda)
"""

produtos_ordenados_por_nome = sorted(
    copy.deepcopy(dados.produtos),
    key=lambda item: item['nome'],
    reverse=True
)

produtos_ordenados_por_nome.sort(key=lambda item: item['nome'], reverse=True)

print(*produtos_ordenados_por_nome, sep='\n')


border()
"""
Ordene os produtos por preco crescente (do menor para maior)
Gere produtos_ordenados_por_preco por deep copy (cópia profunda)
"""

produtos_ordenados_por_preco = sorted(
    copy.deepcopy(dados.produtos),
    key=lambda item:item['preco']
)

# produtos_ordenados_por_preco.sort(key=lambda item:item['preco'])

print(*produtos_ordenados_por_preco, sep='\n')