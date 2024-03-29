#include "shell.h"

/**
 * string_length - returns the length of a string.
 * @string: pointer to the string.
 * Return: length of a string.
 */

int string_length(char *string)
{
int length = 0;

if (string == NULL)
return (0);

while (string[length++] != '\0')
{
}
return (--length);
}

/**
 * string_duplicate - duplicates a string
 * @string: string to be copied
 * Return: pointer to the array
 */

char *string_duplicate(char *string)
{
char *result;
int length, i;

if (string == NULL)
return (NULL);

length = string_length(string) + 1;

result = malloc(sizeof(char) * length);

if (result == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
for (i = 0; i < length ; i++)
{
result [i] = string[i];
}

return (result);
}

/**
* string_compare - compare two strings
* @string1: String one, or the shorter
* @string2: string two, or the longer
* @number: number of characters to be compared, 0 if infinite
* Return: 1 if the strings are equal, 0 is the strings are different
*/
int string_compare(char *string1, char *string2, int number)
{
int iterator;

if (string1 == NULL && string2 == NULL)
return (1);

if (string1 == NULL || string2 == NULL)
return (0);

if (number == 0) /* infinite length */
{
if (string_length(string1) != string_length(string2))
return (0);
for (iterator = 0; string1[iterator]; iterator++)
{
if (string1[iterator] != string2[iterator])
return (0);
}
return (1);
}
else /* if there is a number of chars to be compared */
{
for (iterator = 0; iterator < number ; iterator++)
{
if (string1[iterator] != string2[iterator])
return (0);
}
return (1);
}
}

/**
* string_concat - concatenates two strings.
* @string1: string to be concatenated
* @string2: string to be concatenated
*
* Return: pointer to the array
*/

char *string_concat(char *string1, char *string2)
{
char *result;
int length1 = 0, length2 = 0;

if (string1 == NULL)
string1 = "";
length1 = string_length(string1);

if (string2 == NULL)
string2 = "";
length2 = string_length(string2);

result = malloc(sizeof(char) * (length1 + length2 + 1));
if (result == NULL)

{
errno = ENOMEM;
perror("Error");
return (NULL);
}

for (length1 = 0; string1[length1] != '\0'; length1++)
result [length1] = string1[length1];
free(string1);

/** copy of string2 */
for (length2 = 0; string2[length2] != '\0'; length2++)
{
result[length1] = string2[length2];
length1++;
}

result[length1] = '\0';
return (result);
}

/**
 * string_reverse - reverses a string.
 *
 * @string: pointer to a string.
 * Return: void.
 */
void string_reverse(char *string)
{
int i = 0, length = string_length(string) - 1;
char hold;

while (i < length)
{
hold = string[i];
string[i++] = string[length];
string[length--] = hold;
}
}
