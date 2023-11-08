# Exercício - Lista de tarefas com desfazer e refazer

# todo = [] -> lista de tarefas
# todo = ['fazer café'] -> Adicionar fazer café
# todo = ['fazer café', 'caminhar'] -> Adicionar caminhar
# desfazer = ['fazer café',] -> Refazer ['caminhar']
# desfazer = [] -> Refazer ['caminhar', 'fazer café']
# refazer = todo ['fazer café']
# refazer = todo ['fazer café', 'caminhar'

import sys
from termcolor import cprint, colored

import basic_tools

toDoo_list = []


def main_menu():
    global index_counter
    index_counter = 0

    MAIN_LOOP = True

    while MAIN_LOOP:
        basic_tools.clear.cls()

        print(
            colored("[>>] To doo: ", "light_green"),
            end=2*'\n'
        )

        list_printer(toDoo_list, counter=index_counter)

        print(50*'-', end=2*'\n')

        print(
            colored("Commands:\n", "blue"),
            colored(" - [U]ndo\n - [R]edo\n - [E]xit\n", "cyan"),
            sep="\n"
        )

        main_input = input("Insert a task or a command: ")

        if main_input.capitalize() == "U":
            if index_counter == 0:
                pass
            else:
                index_counter -= 1
        elif main_input.capitalize() == "R":
            if index_counter == len(toDoo_list):
                pass
            else:
                index_counter += 1

        elif main_input.capitalize() == "E":
            sys.exit()  # Close the program.
        else:
            toDoo_list.insert(index_counter, main_input)
            index_counter += 1

        dic = {
            'listar': lambda: toDoo_list
        }


def list_printer(list, counter):
    if not list:  # Guard Clouse
        print("There's no tasks yet.")
        return

    for k in range(counter):
        print(f'{k+1}.', list[k])
    print()


main_menu()
