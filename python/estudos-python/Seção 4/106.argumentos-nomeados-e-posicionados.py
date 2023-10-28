"""
Aula 106
Argumentos nomeados e não nomeados em funções Python.
Argumento nomeado tem nome com sinal de igual,
Argumento não nomeado recebe apenas o argumento (valor).
"""


def divisao(x, y, z):
    # Definição da função
    print(f'{x=} {y=} {z=}', '|', '(x*y)/z', (x*z) / y)

# Nesse caso estamos lidando com argumentos posicionais (não nomeados),
# são aqueles que dependem da ordem do argumento.


divisao(1, 2, 3)
divisao(2, y = 2 ,z = 5)

# Podemos nomear os argumentos:

divisao(y = 2,z = 3,  x = 1)