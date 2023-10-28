"""
Escopo de funções em Python
Escopo significa o local onde aquele código pode atingir.
Existe o escopo global e local.

O escopo global:
     o escopo onde todos o código é alcançado.

O escopo local:
     é o escopo onde apenas nomes do mesmo local podem ser alcançados.. Ou seja,
     se o escopo está fechado dentro de uma função, significa que o 
     código não vai afetar o que está fora da função.
     O que faço dentro da função, fica na função.

Não temos acesso a nomes de escopos internos nos escopos externos.
A palavra global faz uma variável do escopo externo ser a mesma no
escopo interno.
"""

# Temos o escopo do arquivo (global)
x = 1  # Faz parte do arquivo



def funcao_1():
    # global x 
    '''
    global x faz com que o x externo possa ser manipulado pelo x interno.
    Entretanto usar global é uma má prática de programação.
    '''
    x = 10  #Esse x definido nesse escopo é diferente do x global
    
    def funcao_2():
        x = 3
        y = 2  # Esse 'y' faz parte do escopo local da 'funcao_2'
        print(f'Esse é o {x = } e {y = } do escopo da funcao_2')

    """
    Como a funcao_2 está definida no escopo local da funcao_1, temos    
    que executá-la dentro da funcao_1, pois fora ela não existe.
    """

    funcao_2()
    print(f'Esse é o {x = } do escopo da funcao_1')


# print(f'Esse é o {x = } fora do escopo da funcao_1')
funcao_1()
# print(f'Esse é o {x = } fora do escopo depois de modificado pela funcao_1')
