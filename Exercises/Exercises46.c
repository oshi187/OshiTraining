#define _CRT_SECURE_NO_DEPRECATE	
#include <stdio.h>
#define ROWS 4

int main()
{
	printf("Source data:\n");
	int a[][4] = { {-4,-3,-2,-1}, {0,1,2,3}, {252, 253, 254, 255}, {256, 257, 258, 259} };

	for (int i=0; i < ROWS; i++) 
	{
		for (int j=0; j < 4; j++) 
	     {
			if (j % 4 == 0)
				printf("\n");
			printf("%3d ", a[i][j]);
	     }
	}

	printf("\n\nClipped to [0, 255]:");

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] < 0)
				a[i][j] = 0;
			if (a[i][j] > 255)
				a[i][j] = 255;
			if (j % 4 == 0)
				printf("\n");
			printf("%3d ", a[i][j]);
		}
	}

	printf("\n");
	return 0;
}
