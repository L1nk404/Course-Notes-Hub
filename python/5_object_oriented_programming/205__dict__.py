# __dict__ e vars para atributos de instância

class Pessoa:
    ANO_ATUAL = 2022

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def get_ano_de_nascimento(self):
        return Pessoa.ANO_ATUAL - self.idade


dados = {'nome': "joão", "idade": 35}
p1 = Pessoa(**dados)

# __dict__ mostra o dicionário que retém os valores do objeto
print("__dict__ =", p1.__dict__)
print("vars() = ", vars(p1))  # vars é uma função exatamente igual __dict__
