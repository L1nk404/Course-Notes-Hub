ex = input('Bem vindo, digite [1], [2] ou [3] para consultar o ' \
           'exercício respectivo: ')

if ex == '1':  
    # Faça um programa que peça ao usuário para digitar um número inteiro,
    # informe se este número é par ou ímpar. Caso o usuário não digite um 
    # número inteiro, informe que não é um número inteiro.
    # -------------------------------------------------------------------

    Ex_1 = 'Exercício 1' 
    print(f'{Ex_1:-^25}', end=2*'\n')  # Poderia fazer isso sem criar variável?

    num = input('Digite um número inteiro: ')

    try:
        num_int = int(num)
        par = num_int % 2 == 0

        if par:
            print('Este número é par.')
        else:
            print('Este número é ímpar.')

    except:
        print('Você não digitou um número inteiro')

    
    #POderíamos fazer da seguinte maneira também (a primeira que fiz):

    # if num.isdigit():
    #     num_int = int(num)
    #     par = num_int % 2 == 0

    # if num.isdigit() and par:
    #     print('Este número é par.')
    # elif num.isdigit():
    #     print('Este número é ímpar')
    # else:
    #     print('Você não digitou um número inteiro')


elif ex == '2':
    # Faça um programa que pergunte a hora ao usuário e, baseando-se no horário 
    # descrito, exiba a saudação apropriada. Ex. 
    # Bom dia 0-11, Boa tarde 12-17 e Boa noite 18-23.
    #--------------------------------------------------------------------------
    Ex_2 = 'Exercício 2'
    print(f'{Ex_2:-^25}', end=2*'\n')

    hora = input('Digite a hora no formato hh.mm ')

    try: 
        hora_float = float(hora)
        dia = 0 <= hora_float <= 11.59
        tarde = 12 <= hora_float <= 18.59
        noite = 18 <= hora_float <= 23.59
        
        if dia:
            print('Bom dia!')
        elif tarde:
            print('Boa tarde!')
        elif noite:
            print('Boa noite!')

    except:
        print('Você não digitou no formato pedido ou no formato 24h.')
          

elif ex == '3':    
    # Faça um programa que peça o primeiro nome do usuário. Se o nome tiver 4 
    # letras ou menos escreva "Seu nome é curto"; se tiver entre 5 e 6 letras, 
    # escreva "Seu nome é normal"; maior que 6 escreva "Seu nome é muito grande". 
    #---------------------------------------------------------------------------
    Ex_3 = 'Exercício 3'
    print(f'{Ex_3:-^25}', end=2*'\n')

    nome = input('Digite seu nome: ')
    tamanho_nome = len(nome)
   
    if tamanho_nome >=1:
        if tamanho_nome <= 4:
            print('Seu nome é muito curto.')
        elif tamanho_nome <= 6:
            print('Seu nome é normal.')
        else:
            print('Seu nome é muito grande.')
    else:
        print('Digite pelo menos uma letra.')
   
   
    

else:
    print('Exercício não encontrado.')
