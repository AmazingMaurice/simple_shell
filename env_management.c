#include "shell.h"

/**
 * get_key_from_env - getsthe value of the environmanet variable
 * @key: the environment variable of the interest.
 * @data: struct of the programs data
 * Return: a pointer to the value of the variable or NULL if it dosent
 * exist
 */
char *get_key_from_env(char *key, ProgramData *data)
{
int j, keyLength = 0;

if (key == NULL || data->env == NULL)
return (NULL);

keyLength = string_length(key);

for (j = 0; data->env[j]; j++)
{
if (string_compare(key, data->env[j], keyLength) &&
data->env[j][keyLength] == '=')
{
return (data->env[j] + keyLength + 1);
}
}
return (NULL);
}

/**
 * set_key_in_env - This function overwrites the value of an environment
 * variable or create it if it dosent exist.
 * @key: The name of the variable to set.
 * @value:the new value to assign to the variable
 * @data: a struct containing the programs data
 * Return: Returns 1 if any of the parameters are NULL, 2 if there is an error,
 * or 0 if the operation is successful.
 */
int set_key_in_env(char *key, char *value, ProgramData *data)
{
int j, keyLength = 0, is_new_key = 1;

if (key == NULL || value == NULL || data->env == NULL)
return (1);

keyLength = string_length(key);

for (j = 0; data->env[j]; j++)
{
if (string_compare(key, data->env[j], keyLength) &&
data->env[j][keyLength] == '=')
{
is_new_key = 0;
free(data->env[j]);
break;
}
}
data->env[j] = string_concat(string_duplicate(key), "=");
data->env[j] = string_concat(data->env[j], value);

if (is_new_key)
{
data->env[j + 1] = NULL;
}
return (0);
}

/**
 * remove_key_from_env - this function removes key from the environment
 * @key: the key to remove
 * @data: the struct containing the datas program
 * Return: Returns 1 if the key was successfully removed,
 * 0 if the does not exist.
 */
int remove_key_from_env(char *key, ProgramData *data)
{
int j, keyLength = 0;

if (key == NULL || data->env == NULL)
return (0);
keyLength = string_length(key);

for (j = 0; data->env[j]; j++)
{
if (string_compare(key, data->env[j], keyLength) &&
data->env[j][keyLength] == '=')
{
free(data->env[j]);
j++;
for (; data->env[j]; j++)
{
data->env[j - 1] = data->env[j];
}
data->env[j - 1] = NULL;
return (1);
}
}
return (0);
}

/**
 * print_environ_data - prints the current environ
 * @data: struct for the programs data
 * Return: nothing
 */
void print_environ_data(ProgramData *data)
{
int j;

for (j = 0; data->env[j]; j++)
{
print_to_stdout(data->env[j]);
print_to_stdout("\n");
}
}
