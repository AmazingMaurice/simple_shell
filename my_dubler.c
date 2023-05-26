#include "shell.h"
/**
 * my_dubler - duplicates a string
 * @str: the string which we will dublicate
 *
 * Return: pointer to string to be dub
 */
char *my_dubler(char *str)
{
int MMstr_length = 0;
char *MMdub;

if (str == NULL)
return (NULL);

while (*str++)
MMstr_length++;
MMdub = malloc(sizeof(char) * (MMstr_length + 1));
if (!MMdub)
return (NULL);
for (MMstr_length++; MMstr_length--;)
MMdub[MMstr_length] = *--str;

return (MMdub);
}
