""" 
Funções recursivas e recursividade:
- Funções que podem se chamar de volta;
- Úteis p/ dividir problemas grandes em partes menores;
Toda função recursiva deve ter:
- Um problema que possa ser dividido em partes menores; 
- Um caso recursivo que resolve o pequeno problema;
- Um caso base que para a recursão;
"""
import sys
sys.setrecursionlimit(2000)  # Aqui escolhemos o limite do stack overflow


def recursiva(inicio=0, fim=1500):
    # Caso base (método de segurança para impedir stack overflow):
    if inicio == fim:
        return fim  # Encerramos a função aqui

    print(inicio, fim)

    # Meu problema grande será contar de um número até o outro
    inicio += 1
    return recursiva(inicio, fim)  # Chamamos a função novamente


# print(recursiva())

def fatorial(n=10):

    if n == 1:
        return 1

    return n * fatorial(n - 1)


print(fatorial(3))
