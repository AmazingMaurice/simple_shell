#include "shell.h"

/**
 * handle_command - Process and execute a user-entered command
 * @command: The command to be handled
 * @envp: An array of strings containing the environment variables
 *
 * Return: Exit_Success
 */
int handle_command(char *command, char *envp[])
{
char **last_string;
int buildin_holder, value_chpt_func, state;
char *worth_chdir;

last_string = string_tokenization(command);

if (last_string[0] == NULL || last_string[0][0] == '\0')
{
free(last_string);
return (0);
}
if (my_strcmp("exit", last_string[0]) == 0)
my_exit(last_string);

buildin_holder = check_build_in_func(last_string[0], envp);
worth_chdir = file_check(last_string[0]);

if (buildin_holder == 0 && worth_chdir != NULL)
last_string[0] = worth_chdir;

value_chpt_func = path_check_function(last_string[0]);
if (value_chpt_func == 1)
{
status = fork_execute_function(last_string, envp);
free(worth_chdir);
free(last_string);
return (state);
}

if (worth_chdir == NULL && value_chpt_func == 0 && buildin_holder == 0)
{
printf("./shell: No such file or directory\n");
}
free(worth_chdir);
free(last_string);
return (127);
}
