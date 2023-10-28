#Exercício de programação com if e comparação

primeiro_valor = input('Digite um valor: ')
segundo_valor = input('Digite outro valor: ')

if primeiro_valor > segundo_valor:
    print(f'O {primeiro_valor=} é maior que o {segundo_valor=}')
elif primeiro_valor == segundo_valor:
    print(f'O {primeiro_valor=} é igual ao {segundo_valor=}')
else:
    print(f'O {segundo_valor=} é maior que o {primeiro_valor=}')