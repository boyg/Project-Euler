from math import floor, ceil, log, sqrt

n = 10001

'''Using the prime number theorem'''
upper_bound = int(ceil(n * (log(n) + log(log(n)))))

numbers = [True if i > 1 else False for i in range(upper_bound + 1)]
sieve = []

for i in range(2, ceil(sqrt(upper_bound)) + 1):

    if numbers[i] == True:
        j = i**2
        while j <= upper_bound:
            numbers[j] = False
            j += i

for i in range(2, upper_bound+1):
    if numbers[i] == True:
        sieve.append(i)

print(sieve[n-1])
