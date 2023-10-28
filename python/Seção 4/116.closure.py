""" 
Closure e funções que retornam outras funções
"""

# def criar_saudacao(saudacao,nome):

#     def saudar():
#         return f'{saudacao}, {nome}'
#     # Para atrasar a execução dessa função, tiramos os parênteses.
#     return saudar()


def criar_saudacao(saudacao):
    """
    Com o closure eu só mantenho a saudação como parâmetro em criar_saudacao
    e passo o parâmetro nome para saudar.
    """
    def saudar(nome):
        return f'{saudacao}, {nome}'
    # Para atrasar a execução dessa função, tiramos os parênteses.
    return saudar

# s1 = criar_saudacao('Bom dia', 'Luiz')
# s2 = criar_saudacao('Boa noite', 'Luiz')

'''
Note que como retornamos apenas a função 'saudar' e não a executamos
a função ainda foi resolvida, assim a função foi salva.
'''
# print(s1)
# print(s2) 

'''
Assim agora podemos usar o closure executando a função.
Isso permite que possamos colocar parâmetros na função "guardada".
'''
falar_bom_dia = criar_saudacao('Bom dia')
falar_boa_noite = criar_saudacao('Boa noite')

for nome in ['maria', 'Luiz', 'rebebca']:
    print(falar_bom_dia(nome))
    print(falar_boa_noite(nome))