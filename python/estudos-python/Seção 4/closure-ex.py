# def counter():
#     count = 0
    
#     def increment():
#         nonlocal count
#         count += 1
#         return count
    
#     return increment

# # Test the closure function
# c = counter()
# print(c())  # Output: 1
# print(c())  # Output: 2
# print(c())  # Output: 3

""" 
Exercise 2:
Write a closure function called multiplier that takes a number as input and returns a nested function. 
The nested function should multiply the input number by a factor each time it is called. 
The outer function should initialize the factor to 1 and return the nested function.
"""


def multiplier():
   x = 2
   
   def factor_product(factor):  
        return factor * x
   
   return factor_product
      
m = multiplier()

print(m(1))
print(m(2))
print(m(3))
print(m(4))