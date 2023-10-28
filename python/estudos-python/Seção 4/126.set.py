"""
Sets - Conjuntos em Python (tipo set)
Conjuntos são ensinados na matemática
https://brasilescola.uol.com.br/matematica/conjunto.htm
Representados graficamente pelo diagrama de Venn
Sets em Python são mutáveis, porém aceitam apenas
tipos imutáveis como valor interno.
"""


# Criando um set
# set(iterável) ou {1, 2, 3}

# s1 = set()  # vazio
# s1 = {'Luiz', 1, 2, 3}  # com dados


"""
Sets são eficientes para remover valores duplicados
de iteráveis.
- Não aceitam valores mutáveis;
- Seus valores serão sempre únicos;
- não tem índexes;
- não garantem ordem;
- são iteráveis (for, in, not in)
"""

# l1 = [1, 2, 3, 3, 3 , 3]
# s1 = {1, 2, 3, 3, 3 , 3}
  
# print(s1)


"""
Métodos úteis:
add, update, clear, discard
"""
# s1 = set()
# s1.add('Luiz')
# # Adciona de forma iterado e usamos tuplas pra mandar a palavara toda
# s1.update(('Olá mundo', 1, 2, 3, 4))  
# s1.discard('Olá mundo')
# print(s1)

"""
Operadores úteis:
união | união (union) - Une
intersecção & (intersection) - Itens presentes em ambos
diferença simétrica ^ - complementar da intersecção dado o 
                        universo igual a união dos conjuntos
diferença - Itens presentes apenas no set da esquerda
"""

s1 = {1, 2, 3}
s2 = {2 ,3 ,4}
union = s1| s2
intersction = s1 & s2
difference = s1 - s2
simetric = s1 ^ s2
print(union)
print(intersction)
print(difference)
print(simetric)