#include "shell.h"

/**
 * main - function of the shell program.
 *
 * param argc: Represent the number of command line arguments.
 * param argv: An array of strings
 * param envp: An array of strings that represents
 * the program's environment variables
 *
 * Return: The exit status of the program.
 */
int main(int argc, char *argv[], char *envp[])
{
	if (isatty(STDIN_FILENO))
	{
		/* Interactive mode */
		char *line_input;	/* Store the input line */
		size_t size_input = 0;	/* Size of allocated memory */
		ssize_t char_read;	/* Number of characters read */

		while (1)
		{
			printf(";) ");	/* Display the prompt */

			line_input = NULL;
			char_read = read_input(&line_input, &size_input);
			/* Read input from stdin */

			if (*line_input != '\n')
				handle_input(line_input, envp);	/* Process the input line */

			free(line_input);	/* Free the allocated memory */
		}
	} else
	{
		/* Non-interactive mode */
		char input[100];	/* Buffer to store input */
		ssize_t char_read;	/* Number of characters read */

		while ((char_read = read(STDIN_FILENO, input, sizeof(input))) > 0)
		{
			input[strcspn(input, "\n")] = '\0';	/* Remove the newline character */
			handle_input(input, envp);	/* Process the input */
		}
	}

	exit(EXIT_SUCCESS);
}
