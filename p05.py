'''
What is the smallest positive number 
that is evenly divisible by all of the numbers from 1 to 20?
'''
from num_theory import multi_lcm

print(multi_lcm([i for i in range(2,21)]))