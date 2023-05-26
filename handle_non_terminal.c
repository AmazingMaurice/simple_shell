#include "shell.h"

/**
 * handleNonTerminalInput - Handles non-terminal input from the user
 */
void handleNonTerminalInput(void)
{
char input[100];
ssize_t charsRead;
int pipeFd[2];

if (pipe(pipeFd) == -1)
{
perror("pipe");
exit(EXIT_FAILURE);
}
while ((charsRead = read(STDIN_FILENO, input, sizeof(input))) > 0)
{
input[strcspn(input, "\n")] = '\0';
if (write(pipeFd[1], input, my_strlen(input)) == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
executeSystemCustom(input, pipeFd[0]);
}
close(pipeFd[1]);
close(pipeFd[0]);
}
