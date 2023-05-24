#include "shell.h"

/**
* get_string_length - Counts the number of characters in a string.
* @str: The string to be checked.
*
* Return: The length of the string.
*/

int get_string_length(char *str)
{
	int length = 0; /* Initialize a variable to store the length */

	if (!str)

		return (0); /* If the string is empty, return 0 */

	while (*str++) /* Increment the pointer until the end of the string */
		length++; /* Increment the length counter */
	return (length); /* Return the final length of the string */
}
