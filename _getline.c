#include "shell.h"

/**
 * read_line - read one line from the prompt.
 * @data: pointer to the program's data
 *
 * Return: reading count of bytes.
 */
int read_line(ProgramData *data)
{
char buff[BUFFER_SIZE] = {'\0'};
static char *commands_array[10] = {NULL};
static char operators_array[10] = {'\0'};
ssize_t bytes_read;
ssize_t i = 0;

if (!commands_array[0] || (operators_array[0] == '&' && errno != 0) ||
		(operators_array[0] == '|' && errno == 0))
{
for (i = 0; commands_array[i]; i++)
{
free(commands_array[i]);
commands_array[i] = NULL;
}
bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
if (bytes_read == 0)
return (-1);
i = 0;
do {
commands_array[i] = string_duplicate(custom_strtok(i ? NULL : buff, "\n;"));
i = check_logic_operators(commands_array, i, operators_array);
} while (commands_array[i++]);
}
data->input_line = commands_array[0];
for (i = 0; commands_array[i]; i++)
{
commands_array[i] = commands_array[i + 1];
operators_array[i] = operators_array[i + 1];
}
return (string_length(data->input_line));
}

/**
 * check_logic_operators - check and splits for && and ||operators
 * @commands_array: array of commands.
 * @i: index in the commands_array to be checked.
 * @operators_array: array of the logical operators for each previous command
 * Return: index of the last command in the command_array
 */
int check_logic_operators(char *commands_array[], int i,
		char operators_array[])
{
char *temp = NULL;
int j;

for (j = 0; commands_array[i] != NULL && commands_array[i][j]; j++)
{
if (commands_array[i][j] == '&' && commands_array[i][j + 1] == '&')
{
temp = commands_array[i];
commands_array[i][j] = '\0';
commands_array[i] = string_duplicate(commands_array[i]);
commands_array[i + 1] = string_duplicate(temp + j + 2);
i++;
operators_array[i] = '&';
free(temp);
j = 0;
}
if (commands_array[i][j] == '|' && commands_array[i][j + 1] == '|')
{
/*split the line when chars '||' are found */
temp = commands_array[i];
commands_array[i][j] = '\0';
commands_array[i] = string_duplicate(commands_array[i]);
commands_array[i + 1] = string_duplicate(temp + j + 2);
i++;
operators_array[i] = '|';
free(temp);
j = 0;
}
}
return (i);
}
