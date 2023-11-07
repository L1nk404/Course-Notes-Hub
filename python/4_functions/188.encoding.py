""" 
# Modos:

r (leitura), w (escrita), x (para criação)
a (escreve ao final), b (binário)
t (modo texto), + (leitura e escrita)

"""

file_path = 'python\\4_functions\\aula188.txt'

with open(file_path, 'w+', encoding='utf-8') as arquivo:
    # Usamos o enconding para codificar os caracteres do arquivo:
    arquivo.write('Atenção\n')
