#include "shell.h"

/**
 * my_atoi - Converts a string to an integer...
 * @my_string: The string to convert...
 *
 * Return: The converted integer value.
 */
int my_atoi(char *my_string)
{
	int MMz, MMpos_neg;
	unsigned int MMcont;

	MMz = 0;
	MMpos_neg = 1;
	MMcont = 0;

	while (my_string[MMz] != '\0')
	{
		/* Check if the character is a minus sign */
		if (my_string[MMz] == '-')

			MMpos_neg *= -1;
		/* Check if the character is a digit */
		else if (my_string[MMz] >= '0' && my_string[MMz] <= '9')
			MMcont = (MMcont * 10) + (my_string[MMz] - '0');
		/* Break the loop if the character is neither a minus sign nor a digit */
		else
			break;
		MMz++;
	}
	return (MMcont * MMpos_neg);
}
