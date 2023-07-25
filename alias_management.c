#include "shell.h"

/**
 * display_alias - Display aliases or a specific alias.
 * @data: Pointer to the program's data.
 * @alias_name: Name of the alias to be displayed.
 * Return: Zero on success, or a non-zero number if an error occurs or if it's
 * declared in the arguments.
 */
int display_alias(ProgramData *data, char *alias_name)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
	alias_length = string_length(alias_name);
for (i = 0; data->alias_list[i]; i++)
	{
if (!alias_name || (string_compare(data->alias_list[i], alias_name,
				alias_length) && data->alias_list[i][alias_length] == '='))
	{
	for (j = 0; data->alias_list[i][j]; j++)
	{
	buffer[j] = data->alias_list[i][j];
	if (data->alias_list[i][j] == '=')
	break;
	}
	buffer[j + 1] = '\0';
	buffer_append(buffer, "'");
	buffer_append(buffer, data->alias_list[i] + j + 1);
	buffer_append(buffer, "'\n");
	print_to_stdout(buffer);
	}
	}
	}
	return (0);
}
/**
 * get_alias_value - Get the value of an alias.
 * @data: Pointer to the program's data structure.
 * @alias_name: Name of the requested alias.
 *
 * Return: If the alias is found, the function returns
 * a pointer to the alias value.
 * Otherwise, it returns NULL.
 */
char *get_alias_value(ProgramData *data, char *alias_name)
{
	int i, alias_length;

	if (alias_name == NULL || data->alias_list == NULL)
		return (NULL);
	alias_length = string_length(alias_name);
for (i = 0; data->alias_list[i]; i++)
	{
if (string_compare(alias_name, data->alias_list[i], alias_length)
		&& data->alias_list[i][alias_length] == '=')
	{
	return (data->alias_list[i] + alias_length + 1);
	}
	}
	return (NULL);
}

/**
 * set_alias_value - Add or override an alias.
 * @alias_string: The alias to be set in the form (name='value').
 * @data: Pointer to the program's data structure.
 * @alias_string: The string representing the alias to be added or updated.
 * @data: Pointer to the program's data structure that will store the aliases.
 *
 * Return: Zero on success, or a non-zero number if an error occurs
 * or if it's declared in the arguments.
 */
int set_alias_value(char *alias_string, ProgramData *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	/*argument validation*/
	if (alias_string == NULL || data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
	{
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = get_alias_value(data, alias_string + i + 1);
			break;
		}
	}
	for (j = 0; data->alias_list[j]; j++)
	{
		if (string_compare(buffer, data->alias_list[j], i) &&
		data->alias_list[j][i] == '=')
		{
		free(data->alias_list[j]);
		break;
		}
	}
		if (temp)
		{
		buffer_append(buffer, "=");
		buffer_append(buffer, temp);
		data->alias_list[j] = string_duplicate(buffer);
		}
		else
		{
		data->alias_list[j] = string_duplicate(alias_string);
		}
		return (0);
}
