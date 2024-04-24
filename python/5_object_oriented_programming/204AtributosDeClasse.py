# Atributos de classe

class Pessoa:
    ANO_ATUAL = 2022  # Aqui estamos criando um ATRIBUTO da classe,
    # que estára disponível em todas instâncias da classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def get_ano_de_nascimento(self):
        return Pessoa.ANO_ATUAL - self.idade


p1 = Pessoa('João', 35)
p2 = Pessoa('Helena', 12)


print(Pessoa.ANO_ATUAL)  # Posso usar o atributo fora da classe
print(p1.get_ano_de_nascimento())
print(p2.get_ano_de_nascimento())
