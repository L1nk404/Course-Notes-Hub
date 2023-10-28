""" 
Mapeamento de dados em list comprehension:
Em resumo mapeamento é o ato de mudar dados de gerar uma lista mudando dados de 
outra mas mantedndo o mesmo tamanho.
"""

produtos = [
    {'nome': 'p1', 'preco': 20, },
    {'nome': 'p2', 'preco': 10, },
    {'nome': 'p3', 'preco': 30, },
]

""" 
Desempacotamos o dicionário e mudamos o valor da chave desejada
"""
novos_produtos = [
    {**produto, 'preco': produto['preco'] * 1.05}
    # Aqui estamos mundando o preço apenas dos produtos mais caros que 20
    if produto ['preco'] > 20 else {**produto}
    for produto in produtos
]

# print(novos_produtos)
print(*novos_produtos, sep='\n')


