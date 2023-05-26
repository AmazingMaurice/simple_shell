#include "shell.h"

/**
 * handle_error - Prints an error message to stderr
 * @message: The error message to be printed
 *
 * Description: This function prints the given error message to the standard
 * error stream (stderr).
 */

void handle_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
}
