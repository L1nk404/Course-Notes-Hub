'''
split e join com list e str 
split - dividfe uma string
join - une uma string
'''
frase = '      Olha só que         ,  coisa interessante            '
#cria uma listas separando pelos espaços em brancos.
lista_palavra = frase.split()  
#print(lista_palavra)

#no argumento podemos colocar o caractere de divisão.
lista_frase = frase.split(', ')


for i, frase in enumerate(lista_frase):
    print(lista_frase[i].strip())

print(lista_frase)

#strip corta os espaços do começo e do fim. rstrip corta da direita
#e lstrip corta da esquerda.

#Para alterar a lista tirando os espaços fazemos da seguinte forma:
#Suponha o seguinte:

frase = '      Olha só que         ,  coisa interessante            '
lista_frases_cruas = frase.split(',')

# criamos uma nova varíavel:
lista_frases = []

for i, frase in enumerate(lista_frases_cruas):
    lista_frases.append(lista_frases_cruas[i].strip())
    
# print(f'{lista_frases_cruas = }')
# print(f'{lista_frases = }')

#join: une os iteráveis colocados no argumento separados pela str
#colocado antes do método.

frases_unidas = '-'.join(lista_frase)  
#print(f'{frases_unidas = }')