#include "shell.h"

/**
 * execute_exit - Exit the program with a specific status code.
 * @data: Pointers to the program's data structure.
 * Return: Zero  on success, or a non zero number if an error
 * occurs or if its declared in the argument.
 */
int execute_exit(ProgramData *data)
{
int  i;

if (data->tokens[1] != NULL)
{
for (i = 0; data->tokens[1][i]; i++)
{
if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
&& data->tokens[1][i] != '+')
{
errno = 2;
return (2);
}
}
errno = _atoi(data->tokens[1]);
}
freeAllData(data);
exit(errno);
}

/**
 * execute_cd - Change the current working directory.
 * @data: pointer to the program's data structure.
 * Return: Zero on succes, or a non-zero number if an error occurs
 * or if its declared in the argument.
 */
int execute_cd(ProgramData *data)
{
char *dir_home = get_key_from_env("HOME", data);
char *dir_old = NULL;
char old_dir[128] = {0};
int error_code = 0;

if (data->tokens[1])
{
if (string_compare(data->tokens[1], "-", 0))
{
dir_old = get_key_from_env("OLDPWD", data);
if (dir_old)
error_code = set_work_directory(data, dir_old);
print_to_stdout(get_key_from_env("PWD", data));
print_to_stdout("\n");
return (error_code);
}
else
{
return (set_work_directory(data, data->tokens[1]));
}
}
else
{
if (!dir_home)
dir_home = getcwd(old_dir, 128);
return (set_work_directory(data, dir_home));
}
return (0);
}

/**
 * set_work_directory - This function setsthe working directory.
 * @data: A pointers to the program's data
 * @new_dir: The path to be set as the working directory.
 *
 * Return: Return zero if the operation is successful, or a non-zero
 * number if specfied in the argument
 */
int set_work_directory(ProgramData *data, char *new_dir)
{
char old_dir[128] = {0};
int err_code = 0;

getcwd(old_dir, 128);

if (!string_compare(old_dir, new_dir, 0))
{
err_code = chdir(new_dir);
if (err_code == -1)
{
errno = 2;
return (3);
}
set_key_in_env("PWD", new_dir, data);
}
set_key_in_env("OLDPWD", old_dir, data);
return (0);
}

/**
 * execute_help - Shows the help message.
 * @data: Pointer to the programs data.
 * Return: Zero on success,
 * or the other number if its declared in the arguments.
 */
int execute_help(ProgramData *data)
{
int i, length = 0;
char *messages[6] = {NULL};

messages[0] = HELP_MSG;

if (data->tokens[1] == NULL)
{
print_to_stdout(messages[0] + 6);
return (1);
}
if (data->tokens[2] != NULL)
{
errno = E2BIG;
perror(data->command_name);
return (5);
}
messages[1] = HELP_EXIT_MSG;
messages[2] = HELP_ENV_MSG;
messages[3] = HELP_SETENV_MSG;
messages[4] = HELP_UNSETENV_MSG;
messages[5] = HELP_CD_MSG;

for (i = 0; messages[i]; i++)
{
length = string_length(data->tokens[1]);
if (string_compare(data->tokens[1], messages[i], length))
{
print_to_stdout(messages[i] + length + 1);
return (1);
}
}
errno = EINVAL;
perror(data->command_name);
return (0);
}

/**
 * execute_alias - Add, removeor show aliases.
 * @data: Pointer to the programs data.
 * Return: Zero on success , or other number if its decleared in the arguments
 */
int execute_alias(ProgramData *data)
{
int i = 0;

if (data->tokens[1] == NULL)
return (display_alias(data, NULL));

while (data->tokens[i++])
{
if (count_characters(data->tokens[i], "="))
set_alias_value(data->tokens[i], data);
else
display_alias(data, data->tokens[i]);
}
return (0);
}
