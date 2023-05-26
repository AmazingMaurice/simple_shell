#include "shell.h"

/**
 * fork_execute_function - Execute the program in a child process.
 * @array_string: Array of tokens
 * @env: Parent environmental variables
 *
 * Return:0
 * This function forks a new process and executes the program specified by the
 * first token in the array_string. The child process uses execve to replace
 * its image with the specified program. If the program execution fails, an
 * error message is printed. The parent process waits for the child process
 * to complete.
 */

pid_t fork_execute_function(char **array_string, char *env[])
{
pid_t MMchild_pid;
int MMwait_status = 0;

MMchild_pid = fork();
if (MMchild_pid < 0)
{
perror("Error: Fork failed");
return (-1);
}
else if (MMchild_pid == 0)
{
if (execve(array_string[0], array_string, env) == -1)
{
fprintf(stderr, "./shell: %s: No such file or directory\n", array_string[0]);
_exit(EXIT_FAILURE);
}
}
else
{
if (wait(&MMwait_status) == -1)
{
perror("Error: Wait failed");
}
return (WEXITSTATUS(MMwait_status));
}
return (-1);
}
