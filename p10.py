'''
Find the sum of all the primes below two million.
'''
from math import floor, sqrt
from num_theory import sieve_of_eratosthenes

n = 2000000
sieve = sieve_of_eratosthenes(n)

sum = 0
for i in range(2, n+1):
    if sieve[i] == True:
        sum += i

print(sum)