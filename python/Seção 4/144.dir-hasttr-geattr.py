""" 
dir , hasatrr e geattr em Python

dir: Checa o nome dos metodos do objeto
hasatrr: checa dinamicamente se o objeto tem um atributo
getattr: 
"""
string = 'Luiz'
metodo = 'upper'

if hasattr(string, 'upper'):
    print('Existe upper')
    print(string.upper())

print()

if hasattr(string, metodo):
    print('Existe metodo')
    print(getattr(string, metodo)())
    print(string)

