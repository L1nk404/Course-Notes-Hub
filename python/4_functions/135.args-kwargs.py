"""
Empacotamento e desempacotamento de dicionários
"""
separador = f'\n{20*"-"}\n'

pessoa = {
    'nome': 'Aline',
    'sobrenome': 'Souza',
}

dados_pessoa = {
    'idade': 16,
    'altura': 1.6,
}



# Por padrão a iteração do dict entrega as chaves:
a, b = pessoa
print(a,b, end='\n')

# Podemos pedir parar entregar os valores usando .values()
a, b = pessoa.values()
print(a, b, end='\n')

# Ou uma tupla com chave e valor:
a, b = pessoa.items()
print(a, b, end='\n')

# Podemos fazer desempacotamento interno também:
(a1, a2), (b1, b2) = pessoa.items()
print(
    f'\n{a1 = } {a2 = }\n \
      {b1 = } {b2 = }\n'
      )

for chave, valor in pessoa.items():
    print(chave, valor)

print(separador)

"""
Para unir dois dicionários, criamos um terceiro e extraímos os dados
de ambos os dicionários no terceiro usando '**':
"""

pessoa_completa = {**pessoa, **dados_pessoa}

print(pessoa_completa)

print(separador)

""" 
Kwargs - keyword arguments (argumentos nomeados)
kwargs sempre usam 2 asterísticos
"""
print('Kwargs\n')

def mostro_argumentos_nomeados(*args, **kwargs):
    print('NÃO NOMEADOS:', args)

    for chave, valor in kwargs.items():
        print(chave, valor)

# Aqui estamos empacotando os argumentos no kwargs
mostro_argumentos_nomeados(1, 2, nome='Joana', qlq=123)
print()
# Podemos desempacotando o dicionário
mostro_argumentos_nomeados(**pessoa_completa)
print()

configs = {
    'arg1': 1,
    'args2': 2,
    'arg3' : 3,
    'arg4' : 4,
}

mostro_argumentos_nomeados(configs)