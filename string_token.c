#include "shell.h"

/**
 * string_tokenization - tokenize a string into an array of strings
 * @str: input string to tokenize
 * Return: array of tokens
 **/
char **string_tokenization(char *str)
{
	char **MMarray_string;
	char *MMtoken;
	int MMindex = 0;

	MMarray_string = malloc(8 * sizeof(char *));
	if (MMarray_string == NULL)
	{
		perror("Cannot allocate memory");
		exit(1);
	}

	MMtoken = strtok(str, " \t\n");
	while (MMtoken != NULL)
	{
		MMarray_string[MMindex] = strdup(MMtoken);
		if (MMarray_string[MMindex] == NULL)
		{
			perror("Cannot allocate memory");
			exit(1);
		}
		MMindex++;
		MMtoken = strtok(NULL, " \t\n");
	}
	MMarray_string[MMindex] = NULL;

	return (MMarray_string);
}
