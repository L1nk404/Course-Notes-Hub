frase = 'O Python é uma linguagem de programação '\
    'multiparadigma.' \
    'Python foi criado por Guido Van Rossum.'

#print(frase.count('5'))

# i = 0 
# n = 0  # quantidade de vezes que a letra apareceu.
# letra = ''  #letra apareceu mais vezes


# while i < len(frase): 
#     letra_atual = frase[i]  # Iteração
#     n_atual = frase.count(letra_atual)
    
#     if letra_atual == ' ':
#         i += 1
#         continue
   
    
#     if n < n_atual:
#         n = n_atual
#         letra = letra_atual

#     i += 1

# print(f'A letra que apareceu mais vezes foi: "{letra}", {n} vezes')
   
i = 0

string = ''
for letra_atual in frase:
    if letra_atual == frase[i]:
        string += letra_atual
        print(string)
        i += 1
    