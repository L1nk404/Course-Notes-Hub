"""
Exercício
Crie uma função que encontra o primeiro duplicado considerando o segundo
número como a duplicação. Retorne a duplicação considerada.
Requisitos:
    A ordem do número duplicado é considerada a partir da segunda
    ocorrência do número, ou seja, o número duplicado em si.
    Exemplo:
        [1, 2, 3, ->3<-, 2, 1] -> 1, 2 e 3 são duplicados (retorne 3)
        [1, 2, 3, 4, 5, 6] -> Retorne -1 (não tem duplicados)
        [1, 4, 9, 8, ->9<-, 4, 8] (retorne 9)
    Se não encontrar duplicados na lista, retorne -1
"""

int_lists = [
    [3, 1, 2, 3, 2, 1],  # 0, 3
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],  # 1, -1 
    [9, 1, 8, 9, 9, 7, 2, 1, 6, 8],  # 2, 9
    [1, 3, 2, 2, 8, 6, 5, 9, 6, 7],  # 3, 2
    [3, 8, 2, 8, 6, 7, 7, 3, 1, 9],  # 4, 8
    [4, 8, 8, 8, 5, 1, 10, 3, 1, 7],  # 5, 8
    [1, 3, 7, 2, 2, 1, 5, 1, 9, 9],  #6, 2
    [10, 2, 2, 1, 3, 5, 10, 5, 10, 1],  #7, 2
    [1, 6, 1, 5, 1, 1, 1, 4, 7, 3],  #8, 1
    [1, 3, 7, 1, 10, 5, 9, 2, 5, 7],  #9, 1
    [4, 7, 6, 5, 2, 9, 2, 1, 2, 1],  #10, 2
    [5, 3, 1, 8, 5, 7, 1, 8, 8, 7],  #11, 5
    [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],  #12, -1
]


def print_first_repeated_occurence():
    """return the first occurrence of duplicated number"""
    repeated_values_list = []  

    def repeated_value_finder():
        """find the repeated value finder and return the first
           repeated occurence.

        Returns:
            list: return repeated_value_list
        """
        for j, repeated_value in enumerate(current_list):
            if repeated_value == numero and j < i:
                repeated_values_list.append(numero)
                del current_list[j]

        return repeated_values_list
   
    for i, numero in enumerate(current_list):
        # For each number we'll check if there is another occurrence of these number
        repeated_value_finder()

    try:
       print(current_list_index, '=',  repeated_values_list[0])

    except IndexError:
       # if there's no repeated number
      print(current_list_index, '=', '-1')


for current_list_index, current_list in enumerate(int_lists):
    # We have to iterate the elements of each sub list:
    print_first_repeated_occurence()