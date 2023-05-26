#include "shell.h"

/**
 * waitForChildProcess - Waits for the completion of a child process
 * @childPid: The process ID of the child process
 *
 * Return: The exit status of the child process
 */
int waitForChildProcess(pid_t childPid)
{
int status;

if (waitpid(childPid, &status, 0) == -1)
{
perror("wait");
exit(EXIT_FAILURE);
}

if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
else if (WIFSIGNALED(status))
{
fprintf(stderr, "Error with child process\n");
exit(EXIT_FAILURE);
}
return (-1);
}
