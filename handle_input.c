#include "shell.h"

/**
* handle_input - Handles the user input.
* @input: The input string.
* @envp: The environment variables.
*/
void handle_input(char *input, char *envp[])
{
	if (find_substring(input, "|"))
	{
	/*Handle pipeline command*/
	handle_pipeline(input, envp);
	}
	else
	{
	/* Handle regular command*/
	handle_command(input, envp);
	}
}
