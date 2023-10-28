""" 
Funções decoradoras e deciradores.
Decorar = Adicionar / Remover / Restringir / Alterar
Funções decoradoras são usados para fazer o Python usar as funções 
decoradoras em outras funções.
"""

def criar_funcao(func):  
    """ 
    Essa é a função decoradora, seu objetivo é receber uma função, criar
    uma função interna para que eu tenha uma closure e essa função interna
    será retornada sem execução.
    """
    def interna(*args, **kwargs):
        print('Vou te decorar')
        for arg in args:
            e_string(arg)
        
        resultado = func(*args, **kwargs)
        print(f'O seu resultado foi {resultado}')
        print('ok, agora você foi decorada')
        return resultado
    return interna


def inverte_string(string):
    """ 
    A função não deve fazer mais de uma coisa, ela deve ter uma responsabilidade
    única.
    Assim, para tratarmos os dados, vamos usar funções decoradoras.
    """  
    return string[::-1]


def e_string(param):
    if not isinstance(param, str):
        raise TypeError('param deve ser uma string')


inverte_string_Checando_parametro = criar_funcao(inverte_string)
invertida = inverte_string_Checando_parametro('123')
print(invertida)