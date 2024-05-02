"""  
Exercício - Salve sua classe em JSON

Salve os dados da sua classe em JSON e depois crie novamente as 
instâncias da classe com os dados salvos.
Faça isso em arquivos separados.
"""

import os
import json

# Get the directory of the current script
main_file_dir = os.path.dirname(os.path.abspath(__file__))


class Pessoa:
    def __init__(self, nome, idade, cidade):
        self.nome = nome
        self.idade = idade
        self.cidade = cidade


p1 = Pessoa("joão", 35, "São paulo")
p2 = Pessoa("Helena", 22, "Fortaleza")
p3 = Pessoa("Isa", 76, "Manaus")

# Criamos um iterável para salvar mais de 1 pessoa
banco_de_dados = [p1.__dict__, p2.__dict__, p3.__dict__]


if __name__ == '__main__':
    # Aqui garantimos que a função dump seja exexutada exclusivamente nesse
    # arquivo e não em uma importação
    def dump():
        with open(f"{main_file_dir}/pessoa.json", "w") as file:
            json.dump(banco_de_dados, file, ensure_ascii=False, indent=2)
