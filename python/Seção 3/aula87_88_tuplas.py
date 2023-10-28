'''
Introdução ao desempacotamento + tuples (tuplas)
'''
#usamos o desempacotamento para nomear algum dos elemtos
_, nome, *_ = ['Maria', 'Helena', 'Link', 'batata'] 
# usamos '_' para sinalizar uma variável q não vamos usar
print(nome)
print(*_)

'''
Tipo tupla - Uma lista imutável
'''

nomes = ('Maria', 'Helena', 'Link')  #Podemos criar uma tupla apenas não colocando []
#podemos converter uma lista usando tuple(nomes)
print(nomes[0])
print(f'{nomes = },', type(nomes))