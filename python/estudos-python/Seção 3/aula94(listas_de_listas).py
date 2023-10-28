'''
Listas de listas e seus indices
'''
salas = [
    #  0          1
    ['Maria' ,'Helena'], # 0
    #0
    ['Elaine',],  # 1
    # 0         1       2       3
    #                           0 1 2 3 4
    ['Luiz', 'João','Eduarda', (1,2,3,4,5) ] # 2
]

# print(salas[1][0]) #busacamos o valor 0 da lista de índice 1 de salas
# print(salas[2][3][3])

#Agora se tivermos o mesmo tipo de dados, podemos usar o for. (podemos
# fazer com vários tipos também)

salas = [
    #  0          1
    ['Maria' ,'Helena'], # 0
    #0
    ['Elaine',],  # 1
    # 0         1       2         
    ['Luiz', 'João','Eduarda',  ] # 2
]

for sala in salas:
    print(f'A sala é {sala}')
    for aluno in sala:
        print(aluno)