#define _CRT_SECURE_NO_DEPRECATE	
#include <stdio.h>


int main()
{
	int value = 0;
	int *address = &value;
	printf("Value \t: %d\n", value);
	printf("Value++ : %d\n\n", ++value);

	printf("Pointer access, only:\n");
	printf("Access value\t: %d\n", *address);
	value = *address + 1;
	printf("Add value 1 \t: %d\n", value);
    printf("Increment \t: %d\n", ++*address);

}
