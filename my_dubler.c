#include "shell.h"

/**
* duplicate_string  - Duplicates a string.
* @str: The string to be duplicated.
*
* Return: Pointer to the duplicated string.
*/
char *duplicate_string(char *str)
{
	int length = 0; /* Variable to store the length of the string */
	char *duplicated_string; /* Pointer to the duplicated string */

	if (str == NULL)
		return (NULL); /* Return NULL if the input string is NULL */

	while (*str++)
		length++; /* Calculate the length of the string */
	duplicated_string = malloc(sizeof(char) * (length + 1));
	/* Allocate memory for the duplicated string */
	if (!duplicated_string)
	return (NULL); /* Return NULL if memory allocation fails */
	for (length++; length--;)
	duplicated_string[length] = *--str;
	/* Duplicate the string character by character */
	return (duplicated_string);
	/* Return the pointer to the duplicated string */
}
