#include "shell.h"

/**
* print_to_stdout - writes an array of characters to the standard output
* @string: pointer to the array of characters
* Return: the number of bytes written or -1 on error.
* On error, -1 is returned, and errno is set appropriately.
*/
int print_to_stdout(char *string)
{
return (write(STDOUT_FILENO, string, string_length(string)));
}


/**
 * print_to_stderr - writes an array of characters to the standard error
 * @string: pointer to the array of characters
 * Return: the number of bytes written or -1 on error.
 * On error, -1 is returned, and errno is set appropriately.
 */

int print_to_stderr(char *string)
{
return (write(STDERR_FILENO, string, string_length(string)));
}
/**
* print_error_message - writes an array of characters to the standard error
* @data: a pointer to the program's data
* @error_code: error code to print
* Return: the number of bytes written or -1 on error.
* On error: -1 is returned, and errno is set appropriately.
*/
int print_error_message(int error_code, ProgramData *data)
{
char v_as_string[10] = {'\0'};

long_to_string((long)data->exec_counter, v_as_string, 10);

if (error_code == 2 || error_code == 3)
{
print_to_stderr(data->program_name);
print_to_stderr(": ");
print_to_stderr(v_as_string);
print_to_stderr(": ");
print_to_stderr(data->tokens[0]);
if (error_code == 2)
print_to_stderr(": Illegal number: ");
else
print_to_stderr(":can't cd to ");
print_to_stderr(data->tokens[1]);
print_to_stderr("\n");
}
else if (error_code == 127)
{
print_to_stderr(data->program_name);
print_to_stderr(": ");
print_to_stderr(v_as_string);
print_to_stderr(": ");
print_to_stderr(data->command_name);
print_to_stderr(": not found\n");
}
else if (error_code == 126)
{
print_to_stderr(data->program_name);
print_to_stderr(": ");
print_to_stderr(v_as_string);
print_to_stderr(": ");
print_to_stderr(data->command_name);
print_to_stderr(": permission denied\n");
}
return (0);
}
