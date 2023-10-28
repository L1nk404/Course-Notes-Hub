import time
import os

# generator = [n 
#              for n in range(1000000)]
# while True:
# i = 0
start_time = time.time()

for i in range(1,1000001):
    print(i)  


os.system('cls')
print("--- %s seconds ---" % (time.time() - start_time))

a = input('')