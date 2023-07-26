#include "shell.h"

/**
 * execute_command - execute a command with its complete path variable.
 * @data: a pointer to the programs data.
 * Return: if successful return zero , otherwise return -1.
 */
int execute_command(ProgramData *data)
{
int retval = 0, status;
pid_t pidd;

retval = execute_builtins(data);
if (retval != -1)
return (retval);

retval = find_program_in_path(data);
if (retval)
{
return (retval);
}
else
{
pidd = fork();
if (pidd == -1)
{
perror(data->command_name);
exit(EXIT_FAILURE);
}
if (pidd == 0)
{
retval = execve(data->tokens[0], data->tokens, data->env);
if (retval == -1)
perror(data->command_name), exit(EXIT_FAILURE);
}
else
{
wait(&status);
if (WIFEXITED(status))
errno = WEXITSTATUS(status);
else if (WIFSIGNALED(status))
errno = 128 + WTERMSIG(status);
}
}
return (0);
}
