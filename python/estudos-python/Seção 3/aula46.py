"""
Fatiamento de strings

 012345678
 Olá mundo
-987654321

Fatiamento [i:f:p] [::]
Obs.: a função len retorna a qtd de caracteres da str
"""
variavel = 'Olá mundo'
print(variavel[4:7])  #pega uma fatia da variavel começando no indice 4 e terminando em 7+1
print(variavel[4:]) #posso omitir o final
print(variavel[0:5])
print(variavel[0:9:2])  #O passo (p) dita de qnts em qnts casas o interpretador pulará
print(variavel[-1:-9:-1])  #Posso colocar o passo negativo, mas ele contará pra trás

print(10*'#')

print(len(variavel)) #conta o número de caracteres
print(len(variavel[0:2]))
