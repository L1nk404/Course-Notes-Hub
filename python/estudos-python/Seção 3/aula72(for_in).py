'''
O while é mais comumente usado quando não asbemos o número de repetições
que nosso código terá 
'''

# senha_salva = '12345'
# senha_digitada = ''
# repeticoes = 0

# while senha_salva != senha_digitada:
#     senha_digitada = input(f'Sua senha ({repeticoes}x): ')

#     repeticoes += 1

# print(repeticoes)

texto = 'Python'

nova_string = ''

for letra in texto:
    nova_string += (f'-{letra}')

print(nova_string + '-')