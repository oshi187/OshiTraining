/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Oshini Jayaweera
 * Project: 2D points
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4
#define COLUMNS 3


void transposeMatrix(int *);

int main(void)
{
	int matrix[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	printf("Original matrix\n\n");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			printf("%3d", matrix[i * COLUMNS + j]);
		}
		putchar('\n');
	}

	transposeMatrix(matrix);
	return 0;
}

void transposeMatrix(int* matrix)
{
	int matrixT[ROWS][COLUMNS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			matrixT[i][j] = matrix[i * COLUMNS + j];
		}
	}

	printf("\nTransposed Matrix\n\n");
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			printf("%3d", matrixT[j][i]);
		}
		putchar('\n');
	}
}


