/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Symbolic constants */
#define TRUE 1
#define FALSE 0
#define ERROR -1

/* Function prototypes */
int isPrime(int num);
int numDigits(int num);
int Npower(int base, int exp);
int isPalindrome(int num);

/* Determines whether or not a number is prime
 * PARAM: num is a natural number
 * RETURN: TRUE if the number is prime, FALSE if it is not, and ERROR if the number is out of bounds */
int isPrime(int num) {
	int i;

	if (num <= 1)
		return ERROR;

	for (i = 2; i*i <= num; i++)
		if (num % i == 0)
			return FALSE;

	return TRUE;
}

/* Recursively determines the number of digits in a number
 * PARAM: num is an integer
 * RETURN: the number of digits in num */
int numDigits(int num) {
	if (num < 0)
		return numDigits(abs(num));
	else if (num < 10)
		return 1;
	else
		return 1 + numDigits(num / 10);
}

/* Recursively calculates (base)^exp
 * PARAM: base is an integer
 * PARAM: exp is an integer
 * RETURN: the result of base to the power exp */
int Npower(int base, int exp) {
	if (exp == 0)
		return 1;
	else if (exp == 1)
		return base;
	else
		return base * Npower(base, exp - 1);
}

/* Determines if a number is a palindrome number by converting
 * it to a string and iteratively checking each char
 * PARAM: num is an integer
 * RETURN: TRUE if the number is a palindrome and FALSE otherwise */
int isPalindrome(int num) {
	int len = numDigits(num);

	if (len == 1)
		return TRUE;

	/* Dynamically allocate an array to convert num to a string */
	char* numStr = malloc((len + 1) * sizeof(char));
	snprintf(numStr, len + 1, "%d", num);

	int i = 0;
	int j = len - 1;
	while (i < j) {
		if (numStr[i] != numStr[j]) {
			free(numStr);
			return FALSE;
		}
		i++;
		j--;
	}
	free(numStr);
	return TRUE;
}