#include "shell.h"

/**
 * close_unused_pipes - Closes unused pipe file descriptors
 * @pipefd: A two-dimensional array representing the pipe file descriptors
 * @num_commands: The number of commands in the pipeline
 **/

void close_unused_pipes(int pipefd[][2], int num_commands)
{
	int MMj;

	for (MMj = 0; MMj < num_commands - 1; MMj++)
	{
	close(pipefd[MMj][0]);
	close(pipefd[MMj][1]);
	}
}
