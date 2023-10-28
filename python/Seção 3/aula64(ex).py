"""
Iterando strings com while
"""
#.......012345678910
nome = 'Tiago escreveu certo'  # Iterável
N = 0

nova_string = ''
while N < len(nome):
    caractere = f'*{nome[N]}*'
    nova_string += caractere
    N += 1        
 
print(nova_string)     


# n = int(input(': '))
# N = 0

# mysum = N

# while N < n:
#     N += 1
#     mysum += N

# print(mysum)
