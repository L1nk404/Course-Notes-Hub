#Operações artiméticas no Python

adicao = 10 + 10
print('Adição: ' , adicao)

subtracao = 10 - 5
print('Subtração: ', subtracao)

#Multiplicações

multiplicao = 10 * 2
print('multiplicação: ', multiplicao)

exponenciao = 10**2
print('Exponenciação: ', exponenciao)

#Divisões: 

divisao = 10 /3  #sempre vai retornar float
print('Divisão: ', divisao)

divisao_inteira = 10 // 3  #ela trunca o número 
print("Divisão inteira: ", divisao_inteira)

modulo = 25 % 2  #resto da  divisão
print('Módulo: ', modulo)


#Concatenaçao (+) e repetição(*)

concatenaçao = 'A' + 'B' + 'C'
print(concatenaçao)

a_dez_vezes = '#' * 10
print(a_dez_vezes)

#Precedência entre os operadores aritméticos:
    #1. (n+n)
    #2. **
    #3. * / // %
    #4. + -