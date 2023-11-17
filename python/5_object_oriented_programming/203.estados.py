# Mantendo estados dentros da classe

class Camera:
    def __init__(self, nome, filmando=False):
        self.nome = nome
        self.filmando = filmando

    def filmar(self):
        if self.filmando:
            print(f'{self.nome} ja está filmando ...')
            return

        print(f'{self.nome} está filmando ...')
        self.filmando = True  # Aqui estamos guardando o estado da camera.

    def parar_filmar(self):
        if not self.filmando:
            print(f'{self.nome} não está filmando ...')
            return
        self.filmando = False
        print(f'{self.nome} parou de filmar.')

    def fotografar(self):
        if self.filmando:
            print(f'{self.nome} não pode fotografar no momento.')
            return

        print(f'{self.nome} fotografando...')


c1 = Camera('Canon')
c2 = Camera('Sony')
c1.filmar()
c1.fotografar()
print(c1.filmando)
print(c2.filmando)
