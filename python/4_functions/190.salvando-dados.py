import json

file_path = 'aula190.json'

pessoa = {
    'nome': 'Luiz Otávio 2',
    'sobrenome': 'Miranda',
    'enderecos': [
        {'rua': 'R1', 'numero': 32},
        {'rua': 'R2', 'numero': 55},
    ],
    'altura': 1.8,
    'numeros_preferidos': (2, 4, 6, 8, 10),
    'dev': True,
    'nada': None,
}

# Para salvar o dicionário no arquivo fazemos o seguinte:


with open(file_path, 'w', encoding='utf-8') as arquivo:
    # ensure_ascii=False faz ele manter a codificação mas é recomendado manter True para evitar incompatibilidade.
    # Indent=2 faz com que ele deixe o arquivo formatado
    json.dump(pessoa, arquivo, ensure_ascii=False, indent=2)


# Para voltar para o programa basta abrir o arquivo:

with open(file_path, 'r', encoding='utf8') as arquivo:
    pessoa = json.load(arquivo)
    print(pessoa)
