'''
count é um iterador sem fim (módulo itertools)
'''
from itertools import count

c1 = count(start=16, step=8)  # começa no 16 com step 8
r1 = range(16, 100, 8)  # começa no 16 e vai até 100 com step 8

print('c1', hasattr(c1, '__iter__'))  # verificando se c1 é um iterável
print('c1', hasattr(c1, '__next__'))  # verificando se c1 é um iterável
print()
print('r1', hasattr(r1, '__iter__'))  # verificando se c1 é um iterável
print('r1', hasattr(r1, '__next__'))  # verificando se c1 é um iterator
print()

for i in c1:
    if i > 100:
        break
    print(c1)

print(3*'\n')

for i in r1:
    print(r1)
