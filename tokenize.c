#include "shell.h"

/**
* custom_tokenize - this function separates
* the string using a designed delimiter
* @data: a pointer to the program's data
* Return: an array of the different parts of the string
*/
void custom_tokenize(ProgramData *data)
{
char *delimiter = " \t";
int h, g, count = 2, length;

length = string_length(data->input_line);
if (length)
{
if (data->input_line[length - 1] == '\n')
data->input_line[length - 1] = '\0';
}

for (h = 0; data->input_line[h]; h++)
{
for (g = 0; delimiter[g]; g++)
{
if (data->input_line[h] == delimiter[g])
count++;
}
}

data->tokens = malloc(count *sizeof(char *));
if (data->tokens == NULL)
{
perror(data->program_name);
exit(errno);
}
h = 0;
data->tokens[h] = string_duplicate(custom_strtok(data->input_line,
			delimiter));
data->command_name = string_duplicate(data->tokens[0]);
while (data->tokens[h++])
{
data->tokens[h] = string_duplicate(custom_strtok(NULL, delimiter));
}
}
