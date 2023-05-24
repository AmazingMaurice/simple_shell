#include "shell.h"

/**
* concatenate_strings - Concatenates two strings together.
* @str1: The first string.
* @str2: The second string.
*
* Return: Pointer to the concatenated string.
*/

char *concatenate_strings(const char *str1, const char *str2)
{
	size_t length1 = strlen(str1); /* Get the length of str1 */
	size_t length2 = strlen(str2); /* Get the length of str2 */
	char *result = malloc(length1 + length2 + 1);
	/* Allocate memory for the concatenated string */

	if (result == NULL)
	{
		return (NULL); /* Return NULL if memory allocation fails */
	}
	    strcpy(result, str1); /* Copy str1 into the result string */
	    strcpy(result + length1, str2);
	    /* Concatenate str2 to the result string starting from the end of str1 */
return (result); /* Return the pointer to the concatenated string */
}
