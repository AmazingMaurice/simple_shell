#include "shell.h"

/**
 * my_strcpy - cp str
 * @dee: the destination
 * @from: the source
 *
 * Return: pointer to destination
 */
char *my_strcpy(char *dee, char *from)
{
	int indexer = 0;

	if (dee == from || from == 0)
		return (dee);
	while (from[indexer])
	{
		dee[indexer] = from[indexer];
		indexer++;
	}
	dee[indexer] = 0;
}
