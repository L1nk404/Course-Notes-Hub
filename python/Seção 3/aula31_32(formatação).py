#Introdução a f-string

nome = 'Link'
numero = 121312321.6283248923648

linha_1 = f'bom dia,{nome}'  
print(linha_1)
print(f'{numero:.2f}')  #.xf formata o número e x casas decimais
print(f'{numero:,.2f}')  #., separa o número inteiro com ","

print('\n','#'*10,'\n')

#Formatação usando .format

a = 'A'
b = 'B'
c = 1.1
formato = 'a={} b={} c={:.2f}'.format(a, b, c)

#Podemos também escolher os termos pelos índices começando por 0
formato_indexado = 'b={1} a={0} c={2:.2f}'.format(a, b, c)  

#Ou ainda nomear os parâmetros
formato_nomeado = 'a={A} b={nome2} c={nome3}'.format(
A = a, nome2 = b, nome3= c
)  #Note que todo a direita de um parâmetro nomeado, deve ser nomeado !!!


print(formato)
print(formato_indexado)
print(formato_nomeado)