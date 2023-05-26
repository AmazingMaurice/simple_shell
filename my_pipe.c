#include "shell.h"

/**
 * my_pipline_handler - Handles and execute the comands
 * @pipeline: Line inpur from user
 * @envp: An array of parameter variable
 *
 * Return: Return 0 on success
 **/

int my_pipline_handler(char *pipeline, char *envp[])
{
int MMnum_commands = 0;
int MMpipefd[MAX_COMMANDS - 1][2];
char *MMcommands[PIPELINE_MAX_COMMANDS];
char *MMtoken;

MMtoken = strtok(pipeline, "|");
while (MMtoken != NULL && MMnum_commands < PIPELINE_MAX_COMMANDS)
{
MMcommands[MMnum_commands++] = MMtoken;
MMtoken = strtok(NULL, "|");
}
if (MMnum_commands < 2)
{
fprintf(stderr, "Invalid pipeline command\n");
return (1);
}
create_pipes(MMpipefd, MMnum_commands);

execute_commands(MMcommands, MMpipefd, MMnum_commands, envp);

close_pipes(MMpipefd, MMnum_commands);

wait_for_command(MMnum_commands);


return (0);
}
