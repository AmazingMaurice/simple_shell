#include "shell.h"

/**
 * execute_commands - Execute a
 * series of command using pipes......
 * @commands: An array of commands to be executed....
 * @num_commands: The number of commands in the array...
 * @pipefd: An array of pipe file descriptors...
 * for inter-process communication..
 * @envp: An array of strings containing the environment variables..
 *
 * This function forks multiple child processes to.
 * execute a series of commands..
 * using pipes for inter-process communication.
 * Each command is executed in a
 * separate child process. The input and output of
 * each command is redirected.
 * using the pipe file descriptors. The function
 * waits for all child processes.
 * to complete before returning.
 */


void execute_commands(char *commands[], int num_commands,
int pipefd[][2], char *envp[])
{
int i;

for (i = 0; i < num_commands; i++)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
handle_error("Failed to create child process.");
exit(1);
}
if (pid == 0)
{
if (i == 0)
{
dup2(pipefd[i][1], STDOUT_FILENO);
}
else if (i == num_commands - 1)
{
dup2(pipefd[i - 1][0], STDIN_FILENO);
}
else
{
dup2(pipefd[i - 1][0], STDIN_FILENO);
dup2(pipefd[i][1], STDOUT_FILENO);
}
close_pipes(pipefd, num_commands - 1);
exit(handle_command(commands[i], envp));
}
}
}
