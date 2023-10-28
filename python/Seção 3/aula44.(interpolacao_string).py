#Interpolação básica de strings
#s - string
#d e i int
#f - float
#x e X - Hexadecimal (ABCDEF01233456789)
#----------------------------------------------------
nome = 'Luiz'
preco = 1000.89827398
variavel = '%s, o preço é RS%.2f' % (nome, preco)
print(variavel)
print('O hexadecimal de %d é %04X'% (15, 151231))