#include <stdio.h>



int main(void) 
{
	int x1 = 1;
	int x2 = 2;
	int count = 2;
	double average = (x1 + x2) / (float)count;
	printf("Values : %d, %d \n", x1, x2);
	printf("Average: %.1f \n", average);
	return 0;
}