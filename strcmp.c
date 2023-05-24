#include "shell.h"
/**
* compare_strings - Compare two strings.
* @str1: The first string to compare.
* @str2: The second string to compare.
* Return: 0 if @str1 and @str2 are equal,
* a negative value if @str1 is less than @str2,
* or a positive value if @str1 is greater than @str2.
*/
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
	str1++;
	str2++;
	}

	return ((int)(*str1) - (*str2));
}
