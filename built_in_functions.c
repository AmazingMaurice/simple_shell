#include "shell.h"
int my_env(void);

/**
 * check_build_in_func - Determines if the given
 * command is a built-in function.
 * @cmd: The command to check.
 * @envp: The array of environment variables.
 *
 * Return: 0 if the command is not a built-in, or a specific value for each
 *         built-in command.
 */

int check_build_in_func(char *cmd, char *envp[])
{
	/* List of built-in commands */
	char *builtin_commands[] = {"cd", "exit", "env"};
int num_builtins = sizeof(builtin_commands) / sizeof(builtin_commands[0]);
	int MMi;
	(void)envp;
	/* Iterate through the built-in commands */
	for (MMi = 0; MMi < num_builtins; MMi++)
	{
		/* Check if the command matches a built-in command */
		if (my_strcmp(builtin_commands[MMi], cmd) == 0)
		{
			/* Execute the corresponding action for each built-in command */
			switch (MMi + 1)
			{
				case 1:
					chdir(cmd);
					return (1);

				case 2:
					printf("BYE ;)");
					return (2);

				case 3:
					my_env();
					return (1);

				default:
					return (0);
			}
		}
	}

	return (0); /* Command is not a built-in */
}
