def border():
    print(50*'-')



lista = []
for x in range(3):
    for y in range(3):
        lista.append((x,y))

print(lista)

border()

lista = [
    (x, y)
    for x in range(3)
    for y in range(3)   
]

print(lista)

border()

lista = [
    [(x, letra) for letra in 'Luiz']
    for x in range (3)
]

print(lista)