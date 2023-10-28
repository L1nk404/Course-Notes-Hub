# Flag (Bandeira) - Marcar um local
# None  = Não Valor 
# is e is not = é (tipo, valor, identidade)
# id = Identidade
#--------------------------------------------------------

# v1 = 'a'
# v2 = 'b'

# print(id(v1))
# print(id(v2))

condicao = True
passou_no_if = None

if condicao:
    passou_no_if = True
    print('Faça algo')
else:
    print('Não faça algo')

print(passou_no_if, passou_no_if is None)  # Não passou no if
print(passou_no_if, passou_no_if is not None)  # Passou no if



if passou_no_if is None:
    print('Não passou no if.')
else:
    print('Não passou no if.')