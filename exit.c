#include "shell.h"

/**
 * my_exit - Exit the shell with a given status
 * @argument: The argument array passed to the function
 *
 * Description: This function exits the shell with a given status. If an
 * argument is provided, it is converted
 * to an integer and used as the exit status.
 * The function also frees the memory allocated for the argument array.
 */
void my_exit(char **argument)
{
	int MM_stat = 0, a;

	if (argument[1] != NULL)
	{
		MM_stat = atoi(argument[1]);
	}

	for (a = 0; argument[a] != NULL; a++)
	{
		free(argument[a]);
	}

	free(argument);
	exit(MM_stat);
}
