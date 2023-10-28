def fabrica_de_decoradores(a=None, b=None, c=None):  #serve pra pegar os parametros
    def fabrica_de_funcoes(func):  # o decorador tem que receber uma função
        print('Decoradora 1')

        def aninhada(*args, **kwargs):
            print('Parametros do decorador',  a, b, c)
            print('Aninhada')
            res = func(*args, **kwargs)  
            return res  # retorna o resultado da função q está sendo decorada

        return aninhada 
    return fabrica_de_funcoes



@fabrica_de_decoradores(1, 2, 3)
def soma(x, y):
    return x + y


'''
podemos fazer as duas linhas abaixo em uma linha só apenas juntando elas em uma linha
da seguinte maneira:
# multiplica = fabrica_de_decoradores()(lambda x, y:  x * y) 
'''
decoradora = fabrica_de_decoradores()
multiplica = (lambda x, y:  x * y) 

dez_vezes_cinco = multiplica(10, 5)
dez_mais_cinco = soma(10, 5)

print(dez_mais_cinco)
print(dez_vezes_cinco)