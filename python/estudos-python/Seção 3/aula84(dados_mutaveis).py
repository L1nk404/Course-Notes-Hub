'''
Cuidados com dados mutáveis
= - copiado o valor (imutáveis)
= - aponta para o mesmo valor na memória (mutável)
'''
lista_a = ['Luiz', 'Maria', 1, True]
lista_b = lista_a
lista_C = lista_a.copy()

lista_a[0] = 'Qualquer coisa'
print(f'{lista_b = }')  #Foi alterado
print(f'{lista_C = }')

# Note que não fizemos uma cópia das listas como seria feito no caso
# das variáveis mutáveis. Para tal, usaremos copy()


