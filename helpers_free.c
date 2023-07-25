#include "shell.h"

/**
 * freeRecurrentData - free the fields needed each loop
 * @data: struct of the program's data
 * Return: Nothing
 */
void freeRecurrentData(ProgramData *data)
{
if (data->tokens)
freeArrayOfPointers(data->tokens);
if (data->input_line)
free(data->input_line);
if (data->command_name)
free(data->command_name);


data->input_line = NULL;
data->command_name = NULL;
data->tokens = NULL;
}

/**
 * freeALLData - free all fields of the data
 * @data: struct of the program's data
 * Return: Nothing
 */
void freeAllData(ProgramData *data)
{
if (data->file_descriptor != 0)
{
if (close(data->file_descriptor))
perror(data->program_name);
}
freeRecurrentData(data);
freeArrayOfPointers(data->env);
freeArrayOfPointers(data->alias_list);
}

/**
 * freeArrayOfPointers - frees each pointer of an array of pointers and the
 * @array: array of pointers
 * Return: nothing
 */
void freeArrayOfPointers(char **array)
{
int i;

if (array != NULL)
{
for  (i = 0; array[i]; i++)
free(array[i]);

free(array);
array = NULL;
}
}
