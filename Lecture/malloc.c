#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int* ptr;

	printf("Enter a value for n: ");
	scanf("%d", &n);

	ptr = (int*)malloc(n * sizeof(int));
	if (ptr == NULL)
		exit(EXIT_FAILURE); 


	printf("\nEnter the values to be stored: ");

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", ptr+i);
	}

	
	printf("\nThe values: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", *(ptr + i));
	}
	printf("\n");
	
	getchar();
	free(ptr);
}
