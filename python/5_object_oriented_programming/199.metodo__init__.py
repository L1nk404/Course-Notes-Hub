
class Pessoa():
    # Usamos o método __init__ para inicializar os atributos da minha classe.
    # Ele não é a primeira coisa a ser eecutada, mas é uma das primeiras.
    # Note que uma função dentro de uma classe é chamada de método.

    # Todo método que for tratar de uma instância precisa inicializar com o parâmetro "self"
    def __init__(self, nome, sobrenome):
        self.nome = nome
        self.sobrenome = sobrenome


# Note que aqui colocamos apenas nome e sobrenome como param.
p1 = Pessoa('Luiz', 'Otávio')  # Aqui o self é o atributo p1
# p1.nome = 'Luiz'
# p1.sobrenome = 'Otávio'

p2 = Pessoa('Maria', 'Joana')  # Aqui o self é o atributo p2
# p2.nome = 'Maria'
# p2.sobrenome = 'Helena'

print(p1.nome)
print(p1.sobrenome)

print(p2.nome)
print(p2.sobrenome)
