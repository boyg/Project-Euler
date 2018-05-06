'''
What is the 10001st prime number?
'''
from num_theory import sieve_of_eratosthenes
from math import log, ceil

n = 10001

'''
Use the prime number theorem 
to place an upper bound on the nth prime number
'''
upper_bound = int(ceil(n * (log(n) + log(log(n)))))

sieve = sieve_of_eratosthenes(upper_bound)
primes = []

for i in range(2, upper_bound+1):
    if sieve[i] == True:
        primes.append(i)

print(primes[n-1])
