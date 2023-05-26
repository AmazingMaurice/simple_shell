#include "shell.h"

/**
 * my_strcpy - cp str
 * @to: the destination
 * @from: the source
 *
 * Return: pointer to destination
 */
char *my_strcpy(char *to, char *from)
{
int MMcounter = 0;

if (to == from || from == 0)

return (to);
while (from[MMcounter])
{
to[MMcounter] = from[MMcounter];
MMcounter++;
}
to[MMcounter] = 0;

return (to);
}
