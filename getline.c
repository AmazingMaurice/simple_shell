#include "shell.h"

/**
 * read_input - Read input from stdin using getline.
 *
 * @line_input: Pointer to store the input line.
 * @size_input: Pointer to store the size of allocated memory.
 * Return: Number of characters read (-1 if error).
 */
ssize_t read_input(char **line_input, size_t *size_input)
{
	ssize_t MMchar_read = getline(line_input, size_input, stdin);

	if (MMchar_read == -1)
	{
	perror("Error: Failed to read input");
	exit(EXIT_FAILURE);
	}
	return (MMchar_read);
}
