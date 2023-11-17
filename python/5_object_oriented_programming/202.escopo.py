# Escolo da classe e de métodos da classe
# O self da escopo para qualquer método ou atributo da classe


class Animal:
    def __init__(self, nome):
        self.nome = nome

        variavel = 'valor'

    def comendo(self, alimento):
        # print(variavel)  # variavel não está no escopo da acao (assim como funções)
        return f'{self.nome} está comendo {alimento}'

    def executar(self, *args, **kwargs):
        return self.comendo(*args, **kwargs)


leao = Animal(nome='Leão')
print(leao.nome)
print(leao.executar('feijão'))
