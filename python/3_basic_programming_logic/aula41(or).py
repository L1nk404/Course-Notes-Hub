# Operadores lógicos
# and(e) or(ou) not(não)
#or - Qualquer condição verdadeira avalia toda a expressão como 
#verdadeira.
#São considerados Falsy (que você ja viu):
# 0, 0.0, '', False.
# Também existe o tipo None que é usado para representar um não valor.
#-------------------------------------------------------------------

entrada = input('[E]ntrar [S]air: ')
senha_digitada = input('Senha: ')

senha_permitida = '12345'

if (entrada == 'E' or entrada == 'e') and senha_digitada == senha_permitida:
    print('Você entrou no sistema.')
else:
    print('Senha incorreta.')

#Avaliação de curto circuito
print(0 or False or 'abc' or True)  #Retorna o primeiro valor verdadeiro
