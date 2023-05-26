#include "shell.h"

/**
 * handle_command - Process and execute a user-entered command
 * @command: The command to be handled
 * @envp: An array of strings containing the environment variables
 *
 * Return: Exit_Success
 */

int handle_command(char *command, char *envp[])
{
	/* Declare tokens variable */
	char **MMtokens;
	int builtin_ret_val, path_check_val;
	char *MMfile_check_val;

	MMtokens = string_tokenization(command);

	if (my_strcmp("exit", MMtokens[0]) == 0)
		exit(EXIT_SUCCESS);

	builtin_ret_val = check_build_in_func(MMtokens[0], envp);
	MMfile_check_val = file_check(MMtokens[0]);

	if (builtin_ret_val == 0 && MMfile_check_val != NULL)
		MMtokens[0] = MMfile_check_val;

	path_check_val = path_check_function(MMtokens[0]);
	if (path_check_val == 1)
		fork_execute_function(MMtokens, envp);

	if (MMfile_check_val == NULL && path_check_val == 0 && builtin_ret_val == 0)
	{
		printf("./shell: No such file or directory\n");
	}

	free(MMfile_check_val);
	free(MMtokens);

	return (0);
}
