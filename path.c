#include "shell.h"
/**
 * path_check_function - check if the command has the path /bin/
 * @final_string: the string token from the line input
 * Return: 1 if the path is found, 0 if false
 */
int path_check_function(char *final_string)
{
char *MMpath_to_compare = "/bin/";
int MMcounter = 0, MMindex = 0;
char *MMcompareing_result, *MMcheck_command;

MMcompareing_result = malloc((my_strlen(final_string) + 1) * sizeof(char));
if (MMcompareing_result == NULL)
{
perror("Error: Memory allocation failed");
return (0);
}
while (MMpath_to_compare[MMcounter] != '\0')
{
if (MMpath_to_compare[MMcounter] != final_string[MMcounter])
{
free(MMcompareing_result);
return (0);
}
MMcounter++;
}
while (final_string[MMcounter] != '\0')
{
MMcompareing_result[MMindex] = final_string[MMcounter];

MMindex++;
MMcounter++;
}
MMcompareing_result[MMindex] = '\0';
MMcheck_command = file_check(MMcompareing_result);
if (MMcheck_command != NULL)
{
free(MMcompareing_result);
return (PATH_FOUND);
}
free(MMcompareing_result);
return (PATH_NOT_FOUND);
}
