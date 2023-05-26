#include "shell.h"

/**
* handle_command - Process and execute a user-entered command
* @command: The command to be handled
* @envp: An array of strings containing the environment variables
* Return: The exit status of the
*/
int handle_command(char *command, char *envp[])
{
char **tokens;
int is_builtin, is_in_path, exec_status;
char *file_path;

tokens = string_tokenization(command);
if (tokens[0] == NULL || tokens[0][0] == '\0')
{
free(tokens);
return (0);
}
if (my_strcmp("exit", tokens[0]) == 0)
my_exit(tokens);
is_builtin = check_build_in_func(tokens[0], envp);
file_path = file_check(tokens[0]);
if (is_builtin == 0 && file_path != NULL)
tokens[0] = file_path;
is_in_path = path_check_function(tokens[0]);
if (is_in_path == 1)
{
exec_status = fork_execute_function(tokens, envp);
free(file_path);
free(tokens);
return (exec_status);
}
if (file_path == NULL && is_in_path == 0 && is_builtin == 0)
{
printf("./shell: No such file or directory\n");
}
free(file_path);
free(tokens);
return (127);
}
