from ex206classPessoa import FILE_PATH, Pessoa
import json


with open(FILE_PATH, 'r', encoding='utf8') as arquivo:
    pessoas = json.load(arquivo)

    # Desempacotando o dict
    p1 = Pessoa(**pessoas[0])
    p2 = Pessoa(**pessoas[1])
    p3 = Pessoa(**pessoas[2])

print(p1.nome, p1.sobrenome, p1.idade)
print(p2.nome, p2.sobrenome, p2.idade)
print(p3.nome, p3.sobrenome, p3.idade)
