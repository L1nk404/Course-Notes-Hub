def decorator(func):
    """decorator

    Args:
        func (func): function to be decorated
    """ 
    def shorter_function(list1,list2):
        """find the shorter function

        Args:
            list1 (list)
            list2 (list)

        Returns:
            function: return function to be decorated if (shorter_list,list)
            in param
        """
        len_list_1 = len(list1)
        len_list_2 = len(list2)

        if min(len_list_1, len_list_2) == len_list_1:
            return func(list1, list2)
        
        return func(list2, list1)
    
    return shorter_function

