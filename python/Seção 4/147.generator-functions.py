""" 
Introdução às Generators functions em Python
generator = (n for n in range(10000000000))
"""

# # para pausar, usamos yield
# def generator(n=0):
#     yield 1  # pausamos a função aqui
#     print('Continuando...')
#     yield 2  # pausar
#     print('Mais uma vez...')
#     yield 3  # pausar
#     return 'ACABOU'


def generator(n=0 , maximum=10):
    while True:
        yield n
        n += 1

        if n > maximum:
            return

gen = generator(maximum=1000000)

# for n in gen:
#     print(n)


""" 
Yield from
"""

def gen1():
    yield 1
    yield 2
    yield 3
    print('acabou gen1')

def gen3():
    yield 10
    yield 20
    yield 30
    print('acabou gen 3')

def gen2(gen):
    yield from gen()
    yield 4
    yield 5
    yield 6
    yield 7
    print('acabou gen 2')

g1 = gen2(gen1)
g2 = gen2(gen3)
for numero in g1:
    print(numero)

for numero in g2:
    print(numero)