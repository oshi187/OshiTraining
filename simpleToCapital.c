#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using scanf() (concern: buffer overflow)
#include <stdio.h>

char toCapital(char);

int main(void) {
	char letter;

	/* Get user input */
	do
	{
		printf("Enter small letter: ");
		scanf("%c", &letter);
		getchar();
	} while ((letter < 'a') || (letter > 'z'));

	/* Transform to capital letter */
	letter = toCapital(letter);
	printf("Capital letter : %c\n", letter);

	getchar();
	return 0;
}

char toCapital(char letter)
{
	if ((letter >= 'a') && (letter <= 'z'))
		letter += 'A' - 'a';
	    return letter;
}