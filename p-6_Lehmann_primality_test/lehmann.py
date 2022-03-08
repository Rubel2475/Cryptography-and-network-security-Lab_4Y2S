# from random import random

# def lehman(n, t):
#     a = random.randint(2, n-1)
#     e = (n-1)/2
#     while(t>0):
#         result = int(a**e) % n
        
#         if((result%n) == 1 or (result%n) == -1 or (result%n) == (n-1)):
#             a = random.randint(2, n-1)
#             t -= 1
#         else:
#             return -1
        
#         return 1    


# n = int(input("Enter an odd number: "))
# iter = 5

# if(n == 2):
#     print("prime")

# if((n%2) == 0):
#     print(n, "is composite")

# else:
#     flag = lehman(n, iter)

#     if(flag == 1):
#         print(n, "may be prime")
#     else:
#         print(n, "is comoposite")
    
    
    
from random import random


n=23 
a = random.randinteger(2, 22)  
b = int((n-1)/2)

x = int(a**b % n)

if(x !=1 | x!=-1 | x!=(n-1)):
    print("composite")
else:
    print('may be prime')