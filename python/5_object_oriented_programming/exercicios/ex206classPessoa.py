""" 
Exerício - Salve sua classe em JSON.

Salve os dados da sua classe em Json e depois crie novamente as instâncias
da classe com os dados salvos.

Faça em programas separados.
"""

import json

FILE_PATH = 'Course-Notes-Hub\\python\\5_object_oriented_programming\\exercicios\\Pessoas.json'


class Pessoa:
    def __init__(self, nome, sobrenome, idade):
        self.nome = nome
        self.sobrenome = sobrenome
        self.idade = idade


p1 = Pessoa('Link', 'Exe', 26)
p2 = Pessoa('Amanda', 'X', 24)
p3 = Pessoa('Lia', 'Y', 68)

bd = [p1.__dict__, p2.__dict__, p3.__dict__]
# Precisamos chamar __dict__ para que transforme as instâncias em dicts
# Assim, poderemos salvá-las em json.

with open(FILE_PATH, 'w', encoding='utf-8') as class_file:
    # Fazendo apenas o dump
    json.dump(bd, class_file, ensure_ascii=False, indent=2)
