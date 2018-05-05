#include "numbertheory.h"

int main(void)
{
    int i, j, multiplier, multiplicand;
	int product = 0;

	for (i = 100; i < 1000; i++)
		for (j = 100; j < 1000; j++)
			if (isPalindrome(i*j) && i*j > product) {
				multiplier = i;
				multiplicand = j;
				product = i*j;
			}
            
	printf("%d and %d are the largest 3-digit numbers whose product is a palindrome: %d\n", multiplier, multiplicand, product);
	return 0;
}