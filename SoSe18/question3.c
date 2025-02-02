/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Oshini Jayaweera
 * Project: Strings
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.20
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
 /* Function prototypes (provided by examiner) */
char* invertString(const char*);
int countChar(const char*, char);

int main(void)
{
	char string[] = "Welcome to IE-SO1!";
	char* stringReturn;
	char letter = 'e';

	/* Printing the original string */
	printf("Original  : %s\n", string);

	/* Printing the inverted string*/
	stringReturn = invertString(string);
	printf("Inverted  : ");
	for (int i = 0; stringReturn[i] != '\0'; i++)
	{
		printf("%c", stringReturn[i]);
	}
	
	printf("\n");
	free(stringReturn);

	/* function call of count and printing the number of occurances of 'e' */ 
	printf("Count '%c' : %d", letter, countChar(string, letter));
	return 0;
}

char* invertString(const char* string)
{
	char* ptr;
	int size = 18;
	ptr = (char*)malloc((size+1) * sizeof(char));

	if (ptr == NULL)
		exit(EXIT_FAILURE);
	
	for (int i = 0; string[i] != '\0'; i++)
	{
		ptr[i] = string[(size-1) - i];
	}
	ptr[size] = '\0';
	return ptr;
}

int countChar(const char* string, char letter)
{
	int count = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == letter)
			count++;
	}
	
	return count;
}
