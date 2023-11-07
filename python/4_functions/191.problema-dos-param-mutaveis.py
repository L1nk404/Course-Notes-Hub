# Problema dos parâmetros mutáveis em funções Python

# O ideal é não usar parâmetro padrão para parâmetros mutáveis. Sendo assim, podemos
# deixar lista=None e caso o usuário não tenha escolhido, criamos uma nova lista.
def adiciona_clientes(nome, lista=None):
    if lista is None:
        lista = []
    lista.append(nome)
    return lista


# Devemos passar o parametro lista para que o Python não use a mesma lista para todas
# vezes que a função for chamada caso o parametro mutável esteja definido por padrão.

cliente1 = adiciona_clientes('luiz')
adiciona_clientes('Joana', cliente1)

cliente2 = adiciona_clientes('maria')
adiciona_clientes('helena', cliente2)

print(cliente1)
print(cliente2)
