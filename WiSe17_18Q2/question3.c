/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Oshini Jayaweera
 * Project: Divisors and Euclidean algorithm
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.18
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdlib.h>

 /* Function prototypes (provided by examiner) */
void sortDescending(int* a, int* b);
int greatestCommonDivisor(int, int);
int getNumberOfDivisors(int m);
int* newArrayOfDivisors(int m);
void clearInputbuffer(void);

int main()
{
	int m = 0;
	int n = 0;
	int *divisors;
	int gcd = 0;

	printf("Enter two positive integer numbers (comma-seperated): ");
	while ((scanf("%d,%d", &m, &n) != 2 )|| m <= 0 || n <= 0)
	{
		printf("\nInvalid input. Retry: ");
		clearInputbuffer();
	}
	clearInputbuffer();

	divisors = newArrayOfDivisors(m);
	printf("Divisors of %d: ", m);
	for (int i = 0; i < getNumberOfDivisors(m); i++)
	{
		printf("%d ", *(divisors + i));
	}

	gcd = greatestCommonDivisor(m, n);
	printf("\nGreatest common divisor: gcd(%d, %d) = %d\n", m, n, gcd);

	free(divisors);
	sortDescending(&m, &n);
	getchar();
	return 0;
}

void clearInputbuffer(void)
{
	while (getchar() != '\n')
		continue;
}

/*Sorting to get the greatest number out of the two user inputs*/
void sortDescending(int* a, int* b)
{
	int swap = *a;
	if (*b > *a)
	{
		*a = *b;
		*b = swap;
		
	}
}

int greatestCommonDivisor(int m, int n)
{
	int remainder;
	do
	{
		sortDescending(&m, &n);
		m = remainder = m % n;
	} while (remainder != 0);
	return n;
}

int getNumberOfDivisors(int m)
{
	int divisor = 1; //1 is already a divisor

	for (int i = 2; i <= m/2; i++)
	{
		if (m % i == 0)
			divisor++;
	}
	return divisor;
}

int* newArrayOfDivisors(int m)
{
	int* ptr;
	int divisor = getNumberOfDivisors(m);
	
	ptr = (int*)malloc(divisor * sizeof(int));
	if (ptr == NULL)
		exit(EXIT_FAILURE);

	for (int i = 1, count = 0; i <= m / 2; i++)
	{
		if (m % i == 0)
			ptr[count++] = i;
	}
	return ptr;
}


