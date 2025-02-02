/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Oshini Jayaweera
 * Project: User input and bit operations
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void)
{
	const int maxExponent = 16;
	int n;

	printf("Calculation of 2^n with n in [0,16]:\n");

	while (1)
	{
		printf("Enter n: ");
		if(scanf("%d", &n) != 1) // checking if input is invalid (should be an integer)
		{
			while (getchar() != '\n') //clear input buffer
				continue;
			break;
		}

		if (n < 0 || n > maxExponent) //chcking if the input is a valid integer
		{
			printf("Incorrect input: Not in [0, %d]\n", maxExponent);
		}	
		else
		{
			printf("2^%d = %d\n", n, (2 << n) >> 1);
		}
	}

	printf("Press any key to quit.\n");
	getchar();
	return 0;
}
