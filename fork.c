#include "shell.h"

/**
 * execute_program - Execute the program in a child process
 * @tokens: The tokens in array
 * @environment: Parent's environmental variables
 *
 * Return: void
 */
void execute_program(char **tokens, char *environment[])
{
	pid_t child_pid;
	int status;

	/* Fork a child process */
	child_pid = fork();
	if (child_pid < 0)
	{
		/* Forking failed */
		perror("Error: Fork failed");
		return;
	}
	if (child_pid == 0)
	{
		/* Child process */
		/* Execute the program */
		if (execve(tokens[0], tokens, environment) == -1)
		{
			/* Execve failed, print error message and exit child process */
			fprintf(stderr, "./shell: %s: No such file or directory\n", tokens[0]);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */

		/* Wait for the child process to complete */
		if (wait(&status) == -1)
		{
			/* Waiting failed */
			perror("Error: Wait failed");
		}
	}
}
