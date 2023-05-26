#include "shell.h"
/**
 * my_strcat - function concatenate two strings togwther
 * @str1: string one
 * @str2: string two
 * Return: pointer to variable
 */

char *my_strcat(const char *str1, const char *str2)
{
size_t MMlen1 = strlen(str1);
size_t MMlen2 = strlen(str2);
char *MMresult = malloc(MMlen1 + MMlen2 + 1);

if (MMresult == NULL)
{
return (NULL);
}

strcpy(MMresult, str1);
strcpy(MMresult + MMlen1, str2);

return (MMresult);
}
