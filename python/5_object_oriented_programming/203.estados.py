
class Camera:
    def __init__(self, nome, filmando=False):
        self.nome = nome
        self.filmando = filmando  # Aqui estamos colocando uma flag de estado no objeto

    def filmar(self):
        if self.filmando:
            print(f'{self.nome} já está filmando...')
            return

        print(f'{self.nome} está filmando...')
        self.filmando = True  # Aqui mudamos o estamos da câmera

    def parar_filmar(self):
        if not self.filmando:
            print(f'{self.nome} não está filmando.')
            return

        self.filmando = False
        print(f'{self.nome} parou de filmar.')

    def fotografar(self):
        if self.filmando:
            # Usamos o estado filmando para controlar essa ação.
            print(f'{self.nome} não pode fotografar pois está filmando.')
            return

        print(f'{self.nome} está fotografando...')


c1 = Camera('Canon')
c2 = Camera('Sony')

c1.filmar()  # iniciamos o estado de filmar
c1.fotografar()
c1.parar_filmar()
c1.fotografar()
