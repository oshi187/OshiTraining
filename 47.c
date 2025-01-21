#define _CRT_SECURE_NO_DEPRECATE	
#include <stdio.h>
#define ROWS 10

int main()
{
	int i = 0;
	int inputDigit = 0;

	int contWires[ROWS][7] = {{1,1,1,1,1,1,0},
							  {0,1,1,0,0,0,0},
							  {1,1,0,1,1,0,1},
		                      {1,1,1,1,0,0,1},
							  {0,1,1,0,0,1,1},
							  {1,0,1,1,0,1,1},
							  {1,0,1,1,1,1,1},
							  {1,1,1,0,0,0,0},
							  {1,1,1,1,1,1,1},
							  {1,1,1,1,0,1,1,}
	                          };
	
	printf("Please enter a digit: ");
	while (scanf("%d", &inputDigit) != 1 || inputDigit > 9 || inputDigit < 0)

	{ 
		printf("Invalid input");
	}
	printf("Control for 7 segment display:\n\n"); 

	i = inputDigit;
	
	printf("|'a'|'b'|'c'|'d'|'e'|'f'|'g'|");
	printf("\n+---+---+---+---+---+---+---+\n");
	
	for (; i < ROWS; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				

				printf("| %d ", contWires[i][j]);
			}
			printf("|\n");
			break;
		}

	getchar();
	return 0;
}