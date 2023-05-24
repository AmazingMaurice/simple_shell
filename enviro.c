#include "shell.h"

/**
 * print_environment - Print the environmental variables of the shell
 * @envp: Environmental variables
 *
 * Return: 1
 */
int print_environment(char *envp[])
{
	int index = 0;

	while (envp[index] != NULL)
	{
		printf("%s\n", envp[index]);
		index++;
	}
	return (1);
}
