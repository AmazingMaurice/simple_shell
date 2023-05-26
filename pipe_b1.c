#include "shell.h"

/**
 * create_pipes - Creates multiple pipes for inter-process communication
 * @pipefd: A two-dimensional array representing the pipe file descriptors
 * @num_commands: The number of commands in the pipeline
 **/

void create_pipes(int pipefd[][2], int num_commands)
{
	int MMi;

	for (MMi = 0; MMi < num_commands - 1; MMi++)
	{
	if (pipe(pipefd[MMi]) == -1)
	{
	perror("pipe");
	exit(1);
	}
	}
}
