#include "shell.h"

/**
 * show_environment - Display the environment variables
 * present in the shell's execution environment.
 * @data: Pointer to the program's data structure.
 * This function is responsible for showing the environment
 * variables present in the shell's execution environment.
 * It takes a pointer to the data structure (@data) which may
 * be used to access or manipulate the program's data.
 *
 * Return: Zero on success, or a non-zero number if
 * an error occurs or if it's declared in the arguments.
 */
int show_environment(ProgramData *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	if (data->tokens[1] == NULL)
		print_environ_data(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			/*checks for a char '=' */
			if (data->tokens[1][i] == '=')
			{
				var_copy = get_key_from_env(cpname, data);
				if (var_copy != NULL)
				set_key_in_env(cpname, data->tokens[1] + i + 1, data);
			/*display env */
				print_environ_data(data);
				if (get_key_from_env(cpname, data) == NULL)
				{
				print_to_stdout(data->tokens[1]);
				print_to_stdout("\n");
				}
				else
				{
				/*restore varibles old val*/
				set_key_in_env(cpname, var_copy, data);
				free(var_copy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * set_environment_variable - sets an evironment variable.
 * @data: pointer to programs data.
 * Return: Zero id success or other numbers if it is declared in the arguments.
 */
int set_environment_variable(ProgramData *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	set_key_in_env(data->tokens[1], data->tokens[2], data);
	return (0);
}

/**
 * unset_environment_variable - Unsets the environment variables.
 * @data: Pointer to the programs data
 * Return: ..
 */
int unset_environment_variable(ProgramData *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
	errno = E2BIG;
	perror(data->command_name);
	return (5);
	}
	remove_key_from_env(data->tokens[1], data);
	return (0);
}
