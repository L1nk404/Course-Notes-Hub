

def criar_funcao(func):
    def interna(*args, **kwargs):
        for arg in args:
            e_string(arg)
        resultado = func()
        return func()
    return interna

@criar_funcao
def invert_string(string):
    return string[::-1]

def e_string(param):
    if not isinstance(param, str):
        raise TypeError('param deve ser uma string!')

invertida = invert_string('123')
print(invertida)