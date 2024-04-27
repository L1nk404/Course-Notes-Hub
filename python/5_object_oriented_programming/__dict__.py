# __dict__ e vars para atributos de instância

class Pessoa:
    ANO_ATUAL = 2022  # Aqui estamos criando um ATRIBUTO da classe,
    # que estára disponível em todas instâncias da classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def get_ano_de_nascimento(self):
        return Pessoa.ANO_ATUAL - self.idade


p1 = Pessoa('João', 35)
