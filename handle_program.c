#include "shell.h"

/**
 * ExecuteCmd - Executes a command using execvp.
 * @cmd: The command to execute
 *
 *  Return: 0
 */
void ExecuteCmd(char *cmd)
{
char *arguments[4];

arguments[0] = "sh";
arguments[1] = "-c";
arguments[2] = cmd;
arguments[3] = NULL;

execvp("/bin/sh", arguments);
perror("execvp");
exit(EXIT_FAILURE);
}

/**
 * executeSystemCustom - Executes a custom system command
 * @cmd: The command to execute
 * @inputFd: Input file descriptor
 *
 * Return: The exit status of the executed command
 */
int executeSystemCustom(char *cmd, int inputFd)
{
int exitStatus;
pid_t childPid = createChildProcess(&inputFd);

if (childPid == 0)
{
ExecuteCmd(cmd);
}
exitStatus = waitForChildProcess(childPid);
return (exitStatus);
}
