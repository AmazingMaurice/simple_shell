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
int MMi, MMj;

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

for (MMi = 0; MMi < MMnum_commands - 1; MMi++)
{
if (pipe(MMpipefd[MMi]) == -1)
{
perror("pipe");
return (1);
}
}
for (MMi = 0; MMi < MMnum_commands; MMi++)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
if (pid == 0)
{
if (MMi == 0)
{
dup2(MMpipefd[MMi][1], STDOUT_FILENO);
}
else if (MMi == MMnum_commands - 1)
{
dup2(MMpipefd[MMi - 1][0], STDIN_FILENO);
}
else
{
dup2(MMpipefd[MMi - 1][0], STDIN_FILENO);
dup2(MMpipefd[MMi][1], STDOUT_FILENO);
}
for (MMj = 0; MMj < MMnum_commands - 1; MMj++)
{
close(MMpipefd[MMj][0]);
close(MMpipefd[MMj][1]);
}
return (handle_command(MMcommands[MMi], envp));
}
}
for (MMi = 0; MMi < MMnum_commands - 1; MMi++)
{
close(MMpipefd[MMi][0]);
close(MMpipefd[MMi][1]);
}
for (MMi = 0; MMi < MMnum_commands; MMi++)
{
wait(NULL);
}
return (0);
}
