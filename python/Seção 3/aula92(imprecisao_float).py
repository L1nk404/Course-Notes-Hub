"""
Imprecisão de ponto flutuante
Double-precision floating-point format IEEE 754
https://en.wikipedia.org/wiki/Double-precision_floating-point_format
https://docs.python.org/pt-br/3/tutorial/floatingpoint.html
"""
numero_1 = 0.1
numero_2 = 0.7
numero_3 = numero_1 + numero_2

print(numero_3)

#Podemos contornar a imprecisão usando a seguinte função:

#...........variavel, casas decimais
print(round(numero_3, 3)) 

#podemos usar também o módulo usado decimal:
import decimal

numero_4 = decimal.Decimal(0.1)
numero_5 = decimal.Decimal(0.7)
numero_6 = numero_4 + numero_5
print(round(numero_6, 2))