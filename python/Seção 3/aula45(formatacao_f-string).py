"""
Formatação básica de strings
s - string
d - int
f - float
.<número de dígitos>f
x ou X - Hexadecimal
(Caractere)(><^)(quantidade)
> - Esquerda
< - Direita
^ - Centro
= - FOrça o número a aparecer antes dos 0
Sinal - + ou i
Ex.: 0>100,.1f
Conversion flags - !r !s !a
"""
variavel = 'ABC'
print(f'{variavel}')
print(f'{variavel: >10}')#y>n preenche a esquerda n vezes com o caractere y
print(f'{variavel: ^10}')
print('#'*10)

numero = 1231.1765745343423
print(f'{numero:+,.1f}')
print(f'O hexadecimal de 1500 é {1500:08x}')
