
capital = ['Salvador', 'Ubatuba', 'Belo Horizonte']
states = ['BA', 'SP', 'MG', 'RJ']


def decorator(func):
    """decorator

    Args:
        shorter_list(list)
    """
    def shorter_list(list1, list2):
        """find the shorter function

        Args:
            list1 (list)
            list2 (list))

        Returns:
            function: function to be decoreted
        """
        if min(list1, list2) == list1:
            return func(list2, list1)
        return func(list1, list2)
    return shorter_list


@decorator
def zipper(shorter_list, list):
    """zipper

    Args:
        shorter_list (list)
        list (list)

    Returns:
        list: list of tuples of the i-st element of each list to be zipped.
    """     
    return [
        (shorter_list[i], list[i]) for i in range(len(shorter_list))
    ]

print(zipper(states, capital))