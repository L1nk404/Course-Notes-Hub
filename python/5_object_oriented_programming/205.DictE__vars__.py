# __dict__ e vars para atributos de instância

class Pessoa:
    ano_atual = 2022  # Atributo de classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def get_ano_nascimento(self):
        return Pessoa.ano_atual - self.idade  # Usando o atributo de classe


p1 = Pessoa('João', 35)
print(p1.__dict__)  # Isso mostra os atributos que estão salvos para p1
print(vars(p1))  # mesmo que __dict__

# Podemos usar o dict para salvar os dados de alguma forma
