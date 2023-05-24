#include "shell.h"
/**
 * tokenize_string - tokenize a string into an array of strings
 * @input_str: input string to tokenize
 * Return: array of tokens
 **/
char **tokenize_string(char *input_str)
{
char **token_array;
char *current_token;
int token_index = 0;
token_array = malloc(8 * sizeof(char *));
if (token_array == NULL)
{
perror("Cannot allocate memory");
exit(1);
}
current_token = strtok(input_str, "\t\n");
while (current_token != NULL)
{
token_array[token_index] = strdup(current_token);
if (token_array[token_index] == NULL)
{
perror("Cannot allocate memory");
exit(1);
}
token_index++;
current_token = strtok(NULL, "\t\n");
}
token_array[token_index] = NULL;
return (token_array);
}
