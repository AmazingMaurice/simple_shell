#include "shell.h"
/**
 * file_check - Check if the command file exists in /bin/
 * @command: Token to check
 *
 * Description:
 * This function checks if the specified,
 * command file exists in the /bin/ directory.
 * It compares the command with the files in,
 * /bin/ and returns the full path to the command
 * if found, or NULL if not found.
 *
 * Return: NULL if not found, otherwise the full path to the command
 */
char *file_check(char *command)
{
	DIR *dir_ptr = opendir("/bin/");

	/* Open the /bin/ directory */
	if (dir_ptr == NULL)
	{
		perror("opendir");
		return (NULL);
	}
	struct dirent *entry;

	while ((entry = readdir(dir_ptr)) != NULL)
	{
		char *file_name = entry->d_name;
		/* Store the name of the directory entry */
		if (strcmp(file_name, command) == 0)
			/* Compare the stored name with the command */
		{
			/* Allocate memory for the full path of the command */
		char *command_path = malloc(my_strlen("/bin/") + my_strlen(command) + 1);
			if (command_path == NULL)
			{
				closedir(dir_ptr);
				perror("malloc");
				return (NULL);
			}
			command_path = strcpy(command_path, "/bin/");
			/* Copy "/bin/" to the command path */
			command_path = my_strcat(command_path, command);
			/* Concatenate the command to the command path */
			closedir(dir_ptr);
			return (command_path);
			/* Return the full path to the command */
		}
	}
	closedir(dir_ptr);
	return (NULL);
	/* Return NULL if the command is not found */
}
