#include <stdio.h>

int main(void)
{
	int a = 1;
	float b = 1.25;
	/* Integer */
	printf("a : %3d \n", a);
	printf("++a : %d \n", ++a);
	printf("a++ : %d \n", a++);
	printf("--a : %d \n", --a);
	printf("a-- : %d \n", a--);

	printf("\nb : %.2f\n", b);
	printf("++b : %.2f\n", ++b);

	getchar();
	return 0;
}