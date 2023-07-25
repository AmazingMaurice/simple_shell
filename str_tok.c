#include "shell.h"
/**
* custom_strtok - separates strings with delimiters
* @line: It's a pointer to the array we recieve in getline.
* @delim: It's a characters we mark off the string in parts.
* Return: A pointer to the created token
*/
char *custom_strtok(char *line, char *delim)
{
int j;
static char *sub_string;
char *cloneString;

if (line != NULL)
sub_string = line;
for  (; *sub_string != '\0'; sub_string++)
{
for  (j = 0; delim[j] != '\0'; j++)
{
if (*sub_string == delim[j])
break;
}
if (delim[j] == '\0')
break;
}
cloneString = sub_string;
if (*cloneString == '\0')
return (NULL);
for (; *sub_string != '\0'; sub_string++)
{
for (j = 0; delim[j] != '\0'; j++)
{
if (*sub_string == delim[j])
{
*sub_string = '\0';
sub_string++;
return (cloneString);
}
}
}
return (cloneString);
}
