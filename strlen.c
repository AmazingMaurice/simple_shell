#include "shell.h"
/**
 * my_strlen - count the num of charater in the str
 * @str: string to be checked
 *
 * Return: length of str
 */

int my_strlen(char *str)
{
int MMmy_counter = 0;

if (!str)
return (0);

while (*str++)
MMmy_counter++;

return (MMmy_counter);
}
