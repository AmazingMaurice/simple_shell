#include "shell.h"

/**
 * execute_builtins - search for matching builtin commands and execute it.
 * @data: pointer to program's data structure
 *
 * Return: if a matching builtin command is found and executed succesfully,
 * the functions returns the return value of the executed function, if no match
 * is found, the function returns -1.
 */
int execute_builtins(ProgramData *data)
{
int index;
BuiltinCommand opts[] = {
{"exit", execute_exit},
{"help", execute_help},
{"cd", execute_cd},
{"alias", execute_alias},
{"env", show_environment},
{"setenv", set_environment_variable},
{"unsetenv", unset_environment_variable},
{NULL, NULL}
};

for (index = 0; opts[index].built_inn != NULL; index++)
{
if (string_compare(opts[index].built_inn, data->command_name, 0))
{
return (opts[index].function(data));
}
}
return (-1);
}
