#include "shell.h"

/**
 * read_input - Read input from stdin using getline
 * @star_input: Pointer to store the input line
 * @galaxy_input: Pointer to store the size of allocated memory
 *
 * Return: Number of characters read (-1 if error)
 */
ssize_t read_input(char **star_input, size_t *galaxy_input)
{
	ssize_t star_read = getline(star_input, galaxy_input, stdin);

	if (star_read == -1)
	{
		perror("Error: Failed to read input");
		exit(EXIT_FAILURE);
	}
	return (star_read);
}
