#include "shell.h"

/**
 * display_environment - Function to display environment variables
 * @envp: Array of environment variables
 * check_builtin_command - Function checks if a command,
 * is a built-in command and execute it
 *
 * Return: 1 if the command is built-in, 0 otherwise
 */

/* Function to display environment variables */

int display_environment(char *envp[]);

/* Function to check if a command is a built-in command and execute it */
int check_builtin_command(char *command, char *envp[]);
{
	/* Array of built-in commands */
	char *builtin_commands[] = {"cd", "exit", "env"};

	/* Calculate the number of built-in commands */
	int num_builtins = sizeof(builtin_commands) / sizeof(builtin_commands[0]);

	/* Iterate through the built-in commands array */
	for (int i = 0; i < num_builtins; i++)
	{
		/* Check if the command matches a built-in command */
		if (my_strcmp(builtin_commands[i], command) == 0)
		{
			/* Execute the corresponding built-in command based on the index */
			switch (i + 1)
			{
				case 1:
					/* If the command is "cd", change the directory */
					chdir(command);
					return (1);
				case 2:
					/* If the command is "exit", print a message and exit the program */
					printf("Goodbye!");
					return (2);
				case 3:
					/* If the command is "env", display the environment variables */
			display_environment(envp);
		return (1);

		default:
		/* Return 0 for unrecognized built-in commands */
		return (0);
			}
		}
	}
	/* Return 0 for non-built-in commands */
	return (0);
}

/* Function to display environment variables */
int display_environment(char *envp[])
{
	/* Iterate through the array of environment variables */
	for (int i = 0; envp[i] != NULL; i++)
	{
		/* Print each environment variable */
		printf("%s\n", envp[i]);
	}
	return (1);
}
