"""
args - Argumentos não nomeados
* - *args (empacotmaneto e desempacotamento)
"""
# Lembre-te de desempacotamento

def soma(*args):  # note que args são tuplas
    total = 0
    for numero in args:
        total += numero        
    return total
    
     
soma_1_2_3 = soma(1, 2, 3)
# print(soma_1_2_3)

# print(sum((1, 2, 3)))  #Entretanto existe uma função pronta com o mesmo fim

'''
Podemos criar uma variável como uma tupla para por no argumento, 
entretanto, *args está empacotando os argumentos, dessa forma precisamos
colocar a tupla na forma desempacotada usando '*' antes da variável:
'''

numeros = 1, 2, 15,3 ,4, 5, 6, 10, 20
print(numeros)
print(*numeros)
print(soma(*numeros))
