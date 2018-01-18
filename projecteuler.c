#include "numbertheory.h"

int problem1(void);
int problem2(void);
int problem3(void);
void problem4(void);

int main(void) {
	system("pause");
	return 0;
}

int problem1(void) {
	int i;
	int count = 0;

	for (i = 0; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0)
			count += i;
	
	return count;
}

int problem2(void) {
	int sum = 0;
	int a = 1;
	int b = 1;

	do {
		a += b;
		if (a % 2 == 0)
			sum += a;
		b += a;
		if (b % 2 == 0)
			sum += b;
	} while ((a < 4000000) && (b < 4000000));

	return sum;
}

int problem3(void) {
	int i;
	unsigned long long int numToCheck = 13195;

	for (i = (int) sqrt(numToCheck); i > 0; i--) // begin scanning from the largest possible number down
		if (numToCheck % i == 0 && isPrime(i)) // if i is a factor and i is prime
			return i;

	return -1;
}

void problem4(void) {
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

	return;
}

/*
int problem5(void) {
	int i, tmp;
	int factors[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; // lower half is redundant
	int size = 10;

	tmp = lcm(factors[0], factors[1]);
	for (i = 2; i < size; i++) // why does size - 1 give the right answer?
		tmp = lcm(tmp, factors[i]);

	return tmp;
}
*/