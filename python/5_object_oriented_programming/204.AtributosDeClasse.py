
# atributos de classe são atributos criados no escopo da classe


class Pessoa:
    ano_atual = 2022  # Atributo de classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade
        """ 
        Se mudarmos aqui o valor ano atual atrapalharemos a conta, pois
        ele busca primeiro o valor na instância e depois na classe.
        """
        # self.ano_atual = 100

    def get_ano_nascimento(self):
        return Pessoa.ano_atual - self.idade  # Usando o atributo de classe


p1 = Pessoa('João', 35)
p2 = Pessoa('Helena', 12)

print(Pessoa.ano_atual)  # Podemos chamar o atributo fora da classe
# Pessoa.ano_atual = 1 # Note que também podemos mudar o valor do mesmo
print(p1.get_ano_nascimento())
print(p2.get_ano_nascimento())
