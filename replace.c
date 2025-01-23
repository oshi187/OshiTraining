#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void) {

	char string[] = { "Laaking aut af the windaw" };
	int size = sizeof string / sizeof(char);

	printf("The current string: %s\n", string);

	for (int i = 0; i < size - 1; i++)
	{
		if (string[i] == 'a')
			string[i] = 'o';
		else
			continue;
	}

	printf("The new string: %s\n", string);

	return 0;
}

