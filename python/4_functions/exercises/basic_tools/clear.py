import os


def cls():
    """ Clear the terminal."""
    os.system('cls' if os.name == 'nt' else 'clear')  # clear multiplataform
