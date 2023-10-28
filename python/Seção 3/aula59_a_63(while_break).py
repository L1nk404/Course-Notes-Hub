'''
Repetições
While (enquanto)
Executa uma ação enquanto uma condição for verdadeira
Podemos usar Operadores de atribuição para escrever (1) de 
forma mais simples
 = += *= /= //= **= %=

'''

# contador = 1

# while contador <= 100:
#     contador += 1  #Faz o papel de contador + 1
#     print(contador)

#     if contador == 40:
#         print(f'{contador}')
#         continue  #Faz retornar diretamente para o comando While acima.
       
#     if contador == 40:
#         break  # Faz parar o while

# print('Acabou')

#-------------------------------------------------------------------
#Laços internos: 

qtd_linhas = 100
qtd_colunas = 100

linha = 1
while linha <= qtd_linhas:
    coluna = 1
    print(linha)

    while coluna <= qtd_colunas:
        print(f'{linha=}, {coluna=}')
        coluna += 1        
    linha += 1

print('Acabou')