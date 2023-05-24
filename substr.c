#include "shell.h"

/**
* find_substring - Searches for a substring within a sentence.
* @sentence: The sentence to search within.
* @target: The substring to search for.
*
* Return: Pointer to the first occurrence of the substring within the sentence,
* or NULL if the substring is not found.
*/
char *find_substring(char *sentence, char *target)
{
	int sentence_index;

	for (sentence_index = 0; sentence[sentence_index] != '\0'; sentence_index++)
	{
	if (sentence[sentence_index] == target[0])
		{
		int target_index;

			for (target_index = 0; target[target_index] != '\0'; target_index++)
				{
			if (sentence[sentence_index + target_index] != target[target_index])
			{
				break;
				}
			}
			if (target[target_index] == '\0')
			{
				return (&sentence[sentence_index]);
			}
		}
	}
	return (NULL);
}
