#include "shell.h"

/**
 * close_pipes - Closes all pipe file descriptors
 * @pipefd: A two-dimensional array representing the pipe file descriptors
 * @num_commands: The number of commands in the pipeline
 **/

void close_pipes(int pipefd[][2], int num_commands)
{
	int MMi;

	for (MMi = 0; MMi < num_commands - 1; MMi++)
	{
	close(pipefd[MMi][0]);
	close(pipefd[MMi][1]);
	}
}
