""" 
@classmethods + factories methods

Métodos de classes são métodos onde "self" será "cls", ou seja,
ao invés de receber a instância no primeiro parâmentro, rece-
beremos a própria classe.
"""


class Pessoa:
    ano = 2023  # atributo de classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def metodo_de_classe(self):
        print("hey")


print(Pessoa.ano)
