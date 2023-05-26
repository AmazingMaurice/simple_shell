#include "shell.h"

/**
 * wait_for_children - Wait for child processes to terminate
 * @num_commands: The number of child processes to wait for
 *
 * Description: This function waits for the
 * specified number of child processes
 * to terminate. It uses the wait() function
 * to suspend the execution of the
 * current process until any child process
 * terminates. By calling wait() in a
 * loop for the given number of child processes,
 * it ensures that all child
 * processes have finished before proceeding.
 */
void wait_for_children(int num_commands)
{
int i;

for (i = 0; i < num_commands; i++)
{
wait(NULL);
}
}
