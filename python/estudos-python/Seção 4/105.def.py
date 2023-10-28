"""
Aula 105
Introdução às funções (def) em Python
Fuções são trechos de código usados para replicar determinada ação ao 
longo do seu código.
Elas podem receber valores para parâmetros (argumentos) e retornar um
valor específico.
Parâmetro é o nome da "variável" dentro dos parênteses, argumento é
o valor passado para o parâmetro no momento da execução da função.
Por padrão, funções Python retornam None (nada).
"""
# para definirmos uma função usamos a função def

def imprimir(a, b, c):  # Dentro dos parêntenses podemos definir os parâmetros.
    print(a, b, c) 

imprimir(4, 2, 1)
imprimir(1, 2 ,3)

def saudacao(nome = 'sem nome'):
    print(f'Olá, {nome}')

nome = input('Digite seu nome: ')

saudacao(nome)
