#include "shell.h"

/**
 * expand_vars - expand the variables.
 * @data: a pointer to the struct of the programs data.
 * Return: nothing, but set errno.
 */
void expand_vars(ProgramData *data)
{
int p, t;
char lane[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

if (data->input_line == NULL)
return;
buffer_append(lane, data->input_line);
for (p = 0; lane[p]; p++)
if (lane[p] == '#')
lane[p--] = '\0';
else if (lane[p] == '$' && lane[p + 1] == '?')
{
lane[p] = '\0';
long_to_string(errno, expansion, 10);
buffer_append(lane, expansion);
buffer_append(lane, data->input_line + p + 2);
}
else if (lane[p] == '$' && lane[p + 1] == '$')
{
lane[p] = '\0';
long_to_string(getpid(), expansion, 10);
buffer_append(lane, expansion);
buffer_append(lane, data->input_line + p + 2);
}
else if (lane[p] == '$' && (lane[p + 1] == ' ' || lane[p + 1] == '\0'))
continue;
else if (lane[p] == '$')
{
for (t = 1; lane[p + t] && lane[p + t] != ' '; t++)
expansion[t - 1] = lane[p + t];
temp = get_key_from_env(expansion, data);
lane[p] = '\0', expansion[0] = '\0';
buffer_append(expansion, lane + p + t);
temp ? buffer_append(lane, temp) : 1;
buffer_append(lane, expansion);
}
if (!string_compare(data->input_line, lane, 0))
{
free(data->input_line);
data->input_line = string_duplicate(lane);
}
}

/**
 * expand_alias - expands aliases
 * @data: a pointer to a struct of the programs data
 * Return: nothing, or sets errno.
 */
void expand_alias(ProgramData *data)
{
int p, t, was_expanded = 0;
char lane[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

if (data->input_line == NULL)
return;

buffer_append(lane, data->input_line);

for (p = 0; lane[p]; p++)
{
for (t = 0; lane[p + t] && lane[p + t] != ' '; t++)
expansion[t] = lane[p + t];
expansion[t] = '\0';

temp = get_alias_value(data, expansion);
if (temp)
{
expansion[0] = '\0';
buffer_append(expansion, lane + p + t);
lane[p] = '\0';
buffer_append(lane, temp);
lane[string_length(lane)] = '\0';
buffer_append(lane, expansion);
was_expanded = 1;
}
break;
}
if (was_expanded)
{
free(data->input_line);
data->input_line = string_duplicate(lane);
}
}

/**
 * buffer_append - append string at the buffer
 * @buffer: buffer to be filled
 * @str_to_add: string to be copied in the buffer
 * Return: nothing, but sets errno
 */
int buffer_append(char *buffer, char *str_to_add)
{
int length, i;

length = string_length(buffer);
for (i = 0; str_to_add[i]; i++)
{
buffer[length + i] = str_to_add[i];
}
buffer[length + i] = '\0';
return (length + i);
}
