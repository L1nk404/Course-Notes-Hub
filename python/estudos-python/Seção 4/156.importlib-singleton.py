import importlib

from modulo_package import aula156_m

for i in range(10):
    """ 
    Módulos são singletons, ou seja, só pode existir uma instância 
    no programa inteiro enquanto o programa está executando.
    Caso eu queira recarregar o módulo eu importo importlib e uso .reload
    """
    importlib.reload(aula156_m)
    

