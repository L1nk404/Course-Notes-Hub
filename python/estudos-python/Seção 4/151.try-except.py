""" 
try, except, else e finally
https://docs.python.org/pt-br/3/library/exceptions.html#built-in-exceptions
"""

try:
    print(1)
    # 8/0
except ZeroDivisionError:
    print('Dividiu por zero')
else:  #será executado caso o código ocorra sem erros
    print('não deu erro')
finally:  #finally sempre vai ser executado, mesmo caso tenha ocorrido erro
    print(2)  # o finally não trata erro!
    