''' Calculadora com While '''

while True:
    
    print('', 'Para sair digite [s] no lugar do número.', '', sep=' \n')
   
    num_1 = input('Digite um número: ')
    
    if num_1 == 's' and 'S':  #Saída 
        sair = input('Quer sair? [s]im: ').lower().startswith('s')
        despedida = 'Até mais'
        print(f'{despedida:-^20}')
        break            
       
    num_2 = input('Digite outro número: ')
    op = input('Digite a operação [+] [-] [*] [/]: ')

    if len(op) > 1:  # verifica se apenas um operador foi digitado
        print('Digite apenas um operador.')
        continue   

    print('')  #Pulando linha

    
    try:
        num_1_float = float(num_1)
        num_2_float = float(num_2)
        texto = f'{num_1_float} {op} {num_2_float} ='

        if op == '+':
            print(texto, num_1_float + num_2_float)
        elif op == '-':
            print(texto, num_1_float - num_2_float)
        elif op == '*':
            print(texto, num_1_float * num_2_float)   
        elif op == '/':
            print(texto, num_1_float / num_2_float)
        else:
            print('Operador desconhecido.')

    except:
        print('Dados invalídos.')

    
        


        

    


    
 