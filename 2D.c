#include <stdio.h>

int main(void) {
	int n[2][3] = {{81,75,94},{64,49,26}};
	int* ptr = n;
	printf("%p\n", (ptr + 1));//prints the address of n[0][1]
	printf("%p\n", *(n + 1));//prints the adress of n[1][0]
	printf("%p\n", (ptr + 3));//prints the address of n[1][0] *(n + 1)=(ptr + 3)
	printf("%p\n", *(n));//prints the address of n[0][0]
	printf("%p\n", (*n+1));// prints the address of n[0][1]
	printf("%d\n",*(ptr+1));//prints the value at n[0][1]=75
	printf("%d\n", (*ptr + 1));//prints n[0][0]+1= 81+1=82
	printf("%d\n", (*(ptr+1) + 1));//prints n[0][1]+1=75+1=76
	
}
