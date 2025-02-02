/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Oshini Jayaweera
 * Project: Array Operations
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

 /* Include files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes (provided by examiner) */
void printArray(const int a[], int size);//Printing an array to console.
int* cloneArray(const int a[], int size);//creating a clone of given array.
void swap(int* a, int* b);// swaping values in the array.
void invertArray(int a[], int size);//inverting array elements.

int main(void)
{
	const int a[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(a) / sizeof(a[0]);
	int* clone;
	
	printf("Input   : [");
	printArray(a, size);

	printf("Clone   : [");
	clone = cloneArray(a, size);
	printArray(clone, size);

	printf("Inverted: [");
	invertArray(clone, size);
	printArray(clone, size);

	free(clone);
	getchar();
	return 0;
}

//Printing an array to console.
void printArray(const int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\b\b]\n");
}

//creating a clone of given array.
int* cloneArray(const int a[], int size)
{
	int* clone;
	if ((clone = (int*)malloc(size * sizeof(int))) == NULL)
		exit(EXIT_FAILURE);

	for (int i = 0; i < size; i++)
	{
		clone[i] = a[i];
	}

	return clone;
}

// swaping values in the array.
void swap(int* a, int* b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

//inverting array elements.
void invertArray(int a[], int size)
{
	for (int i = 0; i < size/2; i++)
	{
		swap(&a[i], &a[(size-1)-i]);
	}
}
