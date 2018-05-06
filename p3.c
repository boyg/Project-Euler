/* The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */
#include "numbertheory.h"

int main(void)
{
    int i;
	unsigned long long int numToCheck = 600851475143;

	for (i = (int) sqrt(numToCheck); i > 0; i--) // begin scanning from the largest possible number down
		if (numToCheck % i == 0 && isPrime(i))   // if i is a factor and i is prime
			break;

	printf("%d\n", i);
	return 0;
}