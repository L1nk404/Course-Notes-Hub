""" 
Try, except, else e finally (parte 1 e 2)
"""

try:
    a = 18
    b = 0
    c = a / b
except ZeroDivisionError as e:
    print(e.__class__.__name__)
except (NameError, IndexError) as error:
    print('msg do erro', error)
    print('nome', error.__class__.__name__)
except Exception:
    print('Erro desconhecido.') 