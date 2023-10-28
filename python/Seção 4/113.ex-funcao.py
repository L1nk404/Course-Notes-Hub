import os


def cls():
    """limpa o programa
    """
    
    os.system('cls' if os.name == 'nt' else 'clear')  #clear multiplataforma


# 1-Crie uma função que multiplica todos os argumentos
#   não nomeados recebidos
#   Retorne o total para uma variável e mostre o valor
#   da variável.    

def func_produto(*args):

    """Multiplicação dos elementos da lista_numeros.

    Returns:
    float: retorna o produto dos elementos da lista.
    """

    produto = 1
    for numero in args:
        produto *= numero
    return produto

# 2-Crie uma função fala se um número é par ou ímpar.
#   Retorne se o número é par ou ímpar.

def par(x):
    """Função que retorna se x é par ou ímpar

    Args:
        x (float): Número racional

    Returns:
        Str: Diz se é par ou ímpar
    """

    if float(x) % 2 == 0:
        return f'{x} é um número par.'
    
    return f'{x} é um número ímpar'
    

loop_principal = True  # Controla o loop principal

while loop_principal:
    """Aqui temos o menu principal que permite que o usuário escolha o 
       programa que deseja usar.
    """

    entrada = input('Bem vindo, digite [1] ou [2] para consultar o ' \
           'respectivo exercício. Ou qualquer outra tecla para sair: ')

    if entrada == '1':
        cls()  # Exercício 1
        loop_input_ex1 = True  # Variável que controla o while do input no ex 1.
        lista_numeros = []

        while loop_input_ex1:
            input_ex1 = input('Digite os valores e [c] para confirmar ou [s] para sair: ')

            try:
                lista_numeros.append(float(input_ex1))  # Adiciona elementos a lista.            
            
            except:
                if input_ex1 == 's' or input_ex1 == 'S':
                    cls()
                    loop_input_ex1 = False  # Quebra o loop interno e retorna para entrada 

                elif input_ex1 == 'c' or input_ex1 == 'C':  #Confirma o valor
                    cls()
                    print(f'O produto dos termos {lista_numeros} é igual a'/
                          ' : {func_produto(*lista_numeros)}''\n'
                          )                    
                    lista_numeros.clear()  # Zeramos a lista para novas consultas
                    continue
                else:
                    print('Por favor, digite apenas números, [c] ou [s].')


    elif entrada == '2':  # Exercício 2
        cls()
        loop_input_ex2 = True  # Variável que controla o while do input no ex 2.

        input_ex2 = input('Digite um número ou [s] para sair: ')

        try:
            par(input_ex2)
        except:
            if input_ex2 == 's' or input_ex2 == 'S':
                cls()
                loop_input_ex2 = False  # Quebra o loop interno e retorna para entrada 
            else:
                print('Por favor, digite apenas números ou [s].')  

    else:  # Saída
        cls()
        confirmar_sair = input('Deseja realmente sair? Digite "sair" para confirmar ou qualquer outra'\
                               ' tecla para voltar.')

        if confirmar_sair == 'sair' or confirmar_sair == 'SAIR':
            break
        else:
            continue
