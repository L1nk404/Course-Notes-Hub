""" 
Valores Truthy e Falsy, tipos mutáveis e imutáveis
Mutáveis [] {} set()
Imutáveis () "" 0 0.0 False range (0 10)
Todos os valores abaixo são considerados falsy, logo, o contrário é
truthy
"""
#Mutáveis
lista = []
dicionario = {}
conjunto = set()
tupla = ()
#Imutáveis
string = ''
inteiro = 0
flutuante = 0.0
nada = None
falso = False
intervalo = range(0)


def falsy(valor):
    return 'falsy' if not valor else 'truthy'

print(f'Teste', falsy('TESTE'))
print(f'{lista=}', falsy(lista))
print(f'{dicionario=}', falsy(dicionario))
print(f'{conjunto=}', falsy(conjunto))
print(f'{tupla=}', falsy(tupla))
print(f'{string=}', falsy(string))
print(f'{inteiro=}', falsy(inteiro))
print(f'{flutuante=}', falsy(flutuante))
print(f'{nada=}', falsy(nada))
print(f'{falso=}', falsy(falso))
print(f'{intervalo=}', falsy(intervalo))