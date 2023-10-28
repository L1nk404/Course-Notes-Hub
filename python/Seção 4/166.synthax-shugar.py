""" 
Decoradores no Python são Syntax Sugar, ou seja, a linguagem tem um 
recurso que facilita o uso das funções decoradoras
"""

def criar_funcao(func):  
    def interna(*args, **kwargs):
        print('Vou te decorar')

        for arg in args:
            e_string(arg)
        
        resultado = func(*args, **kwargs)
        print(f'O seu resultado foi {resultado}')
        print('ok, agora você foi decorada')
        return resultado
    return interna


@criar_funcao  # Fazemos com que o Python use criar_funcao na inverte_string
def inverte_string(string):  # inverte_string se torna interna
    print(f'O novo nome dessa função é {inverte_string.__name__}')
    return string[::-1]


def e_string(param):
    if not isinstance(param, str):
        raise TypeError('param deve ser uma string')


"""
O Synthax Sugar faz com que essa linha de comando não seja necessária
#inverte_string_Checando_parametro = criar_funcao(inverte_string)
"""

invertida = inverte_string('123')
print(invertida)