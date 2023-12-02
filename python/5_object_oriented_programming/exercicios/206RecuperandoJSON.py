from ex206classPessoa import FILE_PATH, Pessoa, fazer_dump
import json


with open(FILE_PATH, 'r', encoding='utf8') as arquivo:
    pessoas = json.load(arquivo)

    # Note que dessa forma, se mudarmos os dados na base de dado, teremos
    # transtornos, logo, não é dinâmico.

    # Desempacotando o dict
    p1 = Pessoa(**pessoas[0])
    p2 = Pessoa(**pessoas[1])
    p3 = Pessoa(**pessoas[2])

print(p1.nome, p1.sobrenome, p1.idade)
print(p2.nome, p2.sobrenome, p2.idade)
print(p3.nome, p3.sobrenome, p3.idade)
