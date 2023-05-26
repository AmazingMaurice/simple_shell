#include "shell.h"

/**
 * my_substr - Find the first occurrence of a word
 * in a sentence and return the substring starting from that position
 * @sentence: the sentence to search within
 * @word: the word to find
 * Return: a pointer to the substring starting
 * from the first occurrence of the word, or NULL if the word is not found
**/

char *my_substr(char *sentence, char *word)
{
int MMs;

for (MMs = 0; sentence[MMs] != '\0'; MMs++)
{
if (sentence[MMs] == word[0])
{
int MMw;

for (MMw = 0; word[MMw] != '\0'; MMw++)
{
if (sentence[MMs + MMw] != word[MMw])
{
break;
}
}

if (word[MMw] == '\0')
{
return (&sentence[MMs]);
}
}
}
return (NULL);
}
