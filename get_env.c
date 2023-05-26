#include "shell.h"


/**
 * my_env - Print the environmental variables of the shell
 * @envp: Array of environmental variables
 *
 * Return: 1
 *
 * This function prints the values of the environmental variables
 * used in the shell. It iterates through the envp array and prints
 * each variable on a new line. The function returns 1.
 */
extern char **environ;
int my_env(void)
{
int MMcounter = 0;
while (environ[MMcounter] != NULL)
{
printf("%s\n", environ[MMcounter]);
MMcounter++;
}

return (1);
}
