#include "shell.h"

/**
 * handle_command - Handle the command entered by the user
 * @command: The command to handle
 * @envp: The environment variables
 * Return: 0 on success
 */
int handle_command(char *command, char *envp[])
{
	char **tokens; /* Declare tokens variable */
	int builtin_ret, path_check;
	char *file_check_val;

	tokens = tokenize_string(command); /* Tokenize the command string */

	if (my_strcmp("exit", tokens[0]) == 0)
		exit(EXIT_SUCCESS); /* Check if the command is "exit" and exit if true */

	builtin_ret = check_builtin_func(tokens[0], envp);
	/* Check if the command is a built-in function */
	file_check_val = file_check(tokens[0]);
	/* Check if the command corresponds to a file */

	if (builtin_ret == 0 && file_check_val != NULL)
		tokens[0] = file_check_val;
	/* Replace the command with the file path if it exists */

	path_check = path_check_function(tokens[0]);
/* Check if the command corresponds to a valid executable in the system PATH */

	if (path_check == 1)
		fork_execute_function(tokens, envp);
	/* Fork and execute the command if it is a valid executable */

	if (file_check_val == NULL && path_check == 0 && builtin_ret == 0)
		printf("./shell: No such file or directory\n");
	/* Print error message if command is neither a file nor a built-in function */

	free(file_check_val);
	free(tokens); /* Free allocated memory for file_check_val and tokens */

	return (0);
}

