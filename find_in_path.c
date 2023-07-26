#include "shell.h"


int check_file(char *path);

/**
* find_program_in_path - find a program in the PATH enviroment variable
* @data: a pointer to the program's data
* Return: 0 if success,error code otherwise
*/

int find_program_in_path(ProgramData *data)
{
int f = 0, retCode = 0;
char **array;

if (!data->command_name)
return (2);

/* If it is a full_path or an executablein the same path */
if (data->command_name[0] == '/' || data->command_name[0] == '.')
return (check_file(data->command_name));


free(data->tokens[0]);
data->tokens[0] = string_concat(string_duplicate("/"), data->command_name);
if (!data->tokens[0])
return (2);

array = tokenize_path(data); /* Search in the PATH */

if (!array || !array[0])
{
errno = 127;
return (127);
}
for (f = 0; array[f]; f++)
{ /* Append the command name to each path*/
array[f] = string_concat(array[f], data->tokens[0]);
retCode = check_file(array[f]);
if  (retCode == 0 || retCode == 126)
{ /* The file was not found, is not a directory and has execute permissions */
errno = 0;
free(data->tokens[0]);
data->tokens[0] = string_duplicate(array[f]);
freeArrayOfPointers(array);
return (retCode);
}
}
free(data->tokens[0]);
data->tokens[0] = NULL;
freeArrayOfPointers(array);
return (retCode);
}

/**
 * tokenize_path - tokenize the PATH enviroment variable into directories
 * @data: a pointer to the program's data
 * Return: array of path directories
 */
char **tokenize_path(ProgramData *data)
{
int f = 0;
int num_directories = 2;
char **tokens = NULL;
char *path;
/* Get the PATH value */
path = get_key_from_env("PATH", data);
if ((path == NULL) || path [0] == '\0')
{ /* PATH not found */
return (NULL);
}


path = string_duplicate(path);

/* Find the number of directories in the PATH */
for (f = 0; path [f]; f++)
{
if (path[f] == ':')
num_directories++;
}


/* Reserve space for the array of pointers */
tokens = malloc(sizeof(char *) * num_directories);

/* Tokenize and duplicate each token of the path */
f = 0;
tokens[f] = string_duplicate(custom_strtok(path, ":"));
while (tokens[f++])
{
tokens[f] = string_duplicate(custom_strtok(NULL, ":"));
}

free(path);
path = NULL;
return (tokens);
}

/**
 * check_file - checks if a file exists, if it is not a directory, and
 * if it has execution permissions.
 * @full_path: pointer to the file name
 * Return: 0 on success, or an error code if it doesn't exist.
 */

int check_file(char *full_path)
{
struct stat sb;

if (stat(full_path, &sb) != -1)
{
if (S_ISDIR(sb.st_mode) || access(full_path, X_OK))
{
errno = 126;
return (126);
}
return (0);
}
/* If the file does not exist */
errno = 127;
return (127);
}
