# Desempacotamento em chamadas
# de métodos e funções
strings = 'ABCD'
lista = ['Maria', 'Helena', 1, 2, 3, 'Eduarda']
tupla = 'Python', 'é', 'legal'

# p,b, *_, u = lista
# print(p, u)


#podemos desempacotar em chamadas de funções usando end = ' '
for nome in lista:
    print(nome, end =' ')

print() # = print('Maria', 'Helena', 1, 2, 3, 'Eduarda')
#ou ainda:
print(*lista)

# podemos usar o sep para organizar o desempacotamento:

salas = [
    #  0          1
    ['Maria' ,'Helena'], # 0
    #0
    ['Elaine',],  # 1
    # 0         1       2         
    ['Luiz', 'João','Eduarda',  ] # 2
]

print(*salas, sep='\n')