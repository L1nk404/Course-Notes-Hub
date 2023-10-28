"""
Aula 107:

Valores padrão para parâmetros
Ao definir uma funlçao, os parêmtros podem ter valores padrão.
Caso o valor não seja enviado para o parâmetro, o valor padrão 
será usado.
Refatorar: editar o seu código.
"""

# Suponha que eu queira refatorar meu código adicionando um 'z' nos 
# parâmetros, para evitar bugs com o programa na qual uso a função e 
# não declarei o 'z', agimos da seguinte forma:

# Definimos 'z' como 'None' e usamos if para confrotar com o boleano
# e evitar futuros bugs.

def soma(x, y, z = None):
    if z is not None:
        print(f'{x=} {y=} {z=}', '|', x + y +z )
    else: 
        print(f'{x=} {y=}', '|', x + y)


soma(1, 2)
soma(3, 5)
soma(100, 200)
soma(1, 2, 0)

