from math import gcd, floor, sqrt

def multi_lcm(num_list):
    '''
    num_list: list of integers
    returns: LCM (least common multiple) of the numbers in the list
    '''
    lcm = num_list[0]

    for i in num_list[1:]:
        lcm = (lcm * i) // gcd(lcm, i)
        
    return lcm

def sieve_of_eratosthenes(n):
    '''
    n: finds all primes less than or equal to n
    returns: a list of Booleans, where the ith element
    is true if i is prime and false otherwise
    '''
    numbers = [True if i > 1 else False for i in range(n + 1)]

    for i in range(2, floor(sqrt(n)) + 1):

        if numbers[i] == True:
            j = i**2

            while j <= n:
                numbers[j] = False
                j += i
    
    return numbers