#include "shell.h"

/**
 * createChildProcess - Creates a child process using fork
 * @inputFd: Pointer to the input file descriptor
 *
 * Return: The process ID of the child process
 */
pid_t createChildProcess(int *inputFd)
{
pid_t childPid;

childPid = fork();
if (childPid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (childPid == 0)
{
if (dup2(*inputFd, STDIN_FILENO) == -1)
{
perror("dup2");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
else
{
return (childPid);
}
}
