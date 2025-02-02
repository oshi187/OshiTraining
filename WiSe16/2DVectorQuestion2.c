#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using scanf() (concern: buffer overflow)
#include <stdio.h>
#include <math.h>
#define DIM  2

/* Function prototypes */
void scaleVector2D(double a[DIM], double k); //Vector after scaling
void printVector2D(const double *vector); // print a vector to console
double vectorLength(double* vector); //return vector length or magnitude of a vector
double dotProduct2D(const double* a1, const double* a2); //calculting the dot product of two vectors

/* Main function */
int main(void)
{
	double a1[DIM] = { 3., 4. };
	double a2[DIM] = { -2., 6. };

	/* Print vectors to the console */
	printf("Vectors:\na1 = ");
	printVector2D(a1);
	printf("\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector length */
	printf("Vector length:\n|a1| = %.1f\n\n", vectorLength(a1));

	/* Scale vector */
	printf("Scale a2 with 0.5:\na2 = ");
	scaleVector2D(a2, 0.5);
	printVector2D(a2);
	printf("\n\n");

	/* Vector product */
	printf("Dot product:\n<a1, a2> = %.1f\n\n", dotProduct2D(a1, a2));

	return 0;
}

//Vector after scaling
void scaleVector2D(double a[DIM], double k)
{
	*a *= k;
	*(a + 1) *= k;
}

// print a vector to console
void printVector2D(const double *vector)
{
	printf("(%.1f , %.1f)", *vector, *(vector+1));
}

//return vector length or magnitude of a vector
double vectorLength(double* vector)
{
	double length = sqrt(pow(*vector, 2) + pow(*(vector+1), 2));
	return length;
}

//calculting the dot product of two vectors
double dotProduct2D(const double* a1, const double* a2)
{
	double dotProduct = (*a1 * *a2) + (*(a1 + 1) * *(a2 + 1));
	return dotProduct;
}
