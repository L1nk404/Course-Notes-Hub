"""  
class - Classes são moldes para criar novos objetos
As classes geram novos objetos (instâncias) que podem ter seus próprios
atributos e métodos.
- atributos geralmente são dados dentro da classe
- ações ou funções dentro da classe são méotodos
Os objetos gerados pela calsse podem usar seus dados internos para 
realizar várias ações.
Por convenção, usamos PascalCase para nomes de classes.
"""


string = 'Luiz'  # No caso, a classe str gera minha string 'Luiz'
print(string.upper())  # Método de uma string
print(isinstance(string, str))  # string é uma instância da classe str
