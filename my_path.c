#include "shell.h"

/*
 * path_check_function - Check if the command has the path /bin/
 * @final_string: The string token from the input line
 *
 * Description:
 *     This function checks if the specified command has the path "/bin/".
 *     It compares the command with the path "/bin/" and returns 1 if the
 *     path is found, and 0 otherwise.
 *
 * Return: 1 if the path is found, 0 if false
 */
int path_check_function(char *final_string);
{
	char *path_to_compare = "/bin/";
	int counter = 0, index = 0;
	char *comparing_result, *check_command;

	/* Allocate memory for comparing_result */
	comparing_result = malloc((my_strlen(final_string) + 1) * sizeof(char));
	if (comparing_result == NULL)
	{
		perror("Error: Memory allocation failed");
		return (0);
	}

	/* Compare each character of path_to_compare with final_string */
	while (path_to_compare[counter] != '\0')
	{
		if (path_to_compare[counter] != final_string[counter])
		{
			free(comparing_result);
			return (0);
		}
		counter++;
	}

	/* Copy the remaining characters of final_string to comparing_result */
	while (final_string[counter] != '\0')
	{
		comparing_result[index] = final_string[counter];
		index++;
		counter++;
	}
	comparing_result[index] = '\0';

	/* Call file_check function to check if the command exists */
	check_command = file_check(comparing_result);
	if (check_command != NULL)
	{
		free(comparing_result);
		return (PATH_FOUND);
	}

	free(comparing_result);
	return (PATH_NOT_FOUND);
}
