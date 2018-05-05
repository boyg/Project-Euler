#include "numbertheory.h"

int main(void)
{
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

	printf("%d\n", sum);
	return 0;
}