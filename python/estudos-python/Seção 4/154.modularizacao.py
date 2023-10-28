""" 
Entendendo os seus próprios módulos Python:

O primeiro módulo executado chama-se __main__ (está disponível numa 
variável chamada __name__)
Você pode importar outro módulo ou parte do módulo
O Python conhece a pasta onde o __main__ está e as pastas abaixo dele.
Ele não reconhece pastas e módulos acima do __main__ por padrão.
O Python conhece todos os módulos e pacotes presentes nos caminhos 
sys.path.
"""
import sys

# importante separar minhas importações das importações padrões do python
from modulo_package import aula154_m


print('Este módulo se chama', __name__)
# print(*sys.path, sep='\n')

print(aula154_m.a)

