#incldue "shell.h"

/**
 * path_check_function - Check if a command exists in the path
 * @final_string: The command to be checked
 *
 * Return: PATH_FOUND if the command exists
 * in the path, PATH_NOT_FOUND otherwise
 *
 * Description: This function checks if a command
 * exists in the path by comparing
 * it with the "/bin/" path. If the command is found in the path,
 * it returns PATH_FOUND.
 * Otherwise, it returns PATH_NOT_FOUND. It also frees the memory
 * allocated for the
 * intermediate result and the command to check.
 */
int path_check_function(char *final_string)
{
	char *my_comparing_path = "/bin/";
	int my_counter = 0, my_index = 0;
	char *result_to_cmp, *command_to_check;

	result_to_cmp = malloc((my_strlen(final_string) + 1) * sizeof(char));
	if (result_to_cmp == NULL)
	{
		perror("Error: Memory allocation failed");
		return (0);
	}

	while (my_comparing_path[my_counter] != '\0')
	{
		if (my_comparing_path[my_counter] != final_string[my_counter])
		{
			free(result_to_cmp);
			return (0);
		}
		my_counter++;
	}

	while (final_string[my_counter] != '\0')
	{
		result_to_cmp[my_index] = final_string[my_counter];
		my_index++;
		my_counter++;
	}
	result_to_cmp[my_index] = '\0';
	command_to_check = file_check(result_to_cmp);

	if (command_to_check != NULL)
	{
		free(result_to_cmp);
		return (PATH_FOUND);
	}
	free(result_to_cmp);
	return (PATH_NOT_FOUND);
}
