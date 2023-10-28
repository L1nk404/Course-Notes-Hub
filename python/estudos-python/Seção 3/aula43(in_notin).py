#Operadores in e not in
#Strings são iteráveis (Pode navegar item por item)
# 0 1 2 3 4 5 (ìndices positivos)
# O t á v i o
#-6-5-4-3-2-1 (índices negativos)
#-----------------------------------------------------
nome = 'Otávio'
print(nome[2])  #estamos acessando o dado de índice 2.
print(nome[-4])  #estamos acessando o dado de índice -4.
print(10*'-')

print('á' in nome) #Checar se uma das letras está na String
print('vio' in nome) 
print('b' not in nome)
print('z' in nome)

print(10*'-')
nome = input('Digite seu nome: ')
encontrar = input('Digite o que quer encontrar: ')

if encontrar in nome:
    print(f'{encontrar} está em {nome}')
else:
    print(f'{encontrar} não está em nome {nome}')
