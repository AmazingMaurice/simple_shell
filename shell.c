#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 * @envp: an array of strings containing the environment variables
 * Return: Exit_Success
 **/
int main(int argc, char *argv[], char **envp)
{
	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		char *MMline_input;
		size_t MMsize_input = 0;
		ssize_t MMchar_read;

		while (1)
		{
			printf("$ ");
			MMline_input = NULL;
			MMchar_read = read_input(&MMline_input, &MMsize_input);

			if (MMchar_read < 0)
				break;

			if (*MMline_input != '\n')
			{
				handle_input(MMline_input, envp);
			}

			free(MMline_input);
		}
	}
	else
	{
		char input[100];
		ssize_t MMchar_read;

		while ((MMchar_read = read(STDIN_FILENO, input, sizeof(input))) > 0)
		{
			input[strcspn(input, "\n")] = '\0';
			handle_input(input, envp);
		}
	}
	exit(EXIT_SUCCESS);
}
