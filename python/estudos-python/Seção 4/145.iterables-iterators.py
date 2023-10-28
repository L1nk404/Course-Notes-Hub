""" 
Generator expression, Iterables e Iterators em PYthon

Iterables: Tem a responsabilidade de deter os valores
Iterator: Tem a responsabilidade do iterator é te entregar um valor por
          vez , ele não guarda a ordem, ele apenas sabe qual é o 
          próximo valor.
"""
import sys

iterable = ['Eu', 'Tenho', '__iter__']  # se eu crio um método iter no meu objeto ele me retorna um iterator
iterator = iter(iterable) # tem __iter__ e __next__

"""
Generator são funções que sabem pausar, porém não tem tamanho e índice
"""


lista = [
    n
    for n in range(100)
]

# Para escrevermos o generator, usamos parenteses
generator = (n for n in range(10000))  # o generator não salva todos valores na memória e só entrega um valor por vez

print(sys.getsizeof(lista))
print(sys.getsizeof(generator))

print(next(generator))
print(next(generator))

""" 
>>> Conclusão

A vantagem da lista é que posso acessar qualquer elemento a qualquer momento,
por outro lado isso ocupa mais espaço na memória, diferente do Generator.
"""