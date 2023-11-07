# Exercício - Lista de tarefas com desfazer e refazer

# todo = [] -> lista de tarefas
# todo = ['fazer café'] -> Adicionar fazer café
# todo = ['fazer café', 'caminhar'] -> Adicionar caminhar
# desfazer = ['fazer café',] -> Refazer ['caminhar']
# desfazer = [] -> Refazer ['caminhar', 'fazer café']
# refazer = todo ['fazer café']
# refazer = todo ['fazer café', 'caminhar'

import basic_tools


toDoo_list = []


def main_menu():
    MAIN_LOOP = True

    while MAIN_LOOP:
        print("Commands:", " - [U]ndo", " - [R]edo", "[B]ack", sep="\n")
        main_input = input("Insert a task or a command: ")


def toDoo_task_manager():
    ...


main_menu()
