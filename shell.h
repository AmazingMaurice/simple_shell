#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stst function */
#include <signal.h> /* for signal managment */
#include <fcntl.h> /* for open files */

/************* MACROS **************/

#include "macros.h" /* for msg help and prompt */

/************* STRUCTURES **************/
/**
 * struct info- struct for the program's data
 * @program_name: the name of the exceutable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of executed commands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} ProgramData;

/**
* struct BuiltinCommand - struct for the builtins
* @built_inn: the name of the builtin
* @function: the associated function to be called for each builtin
*/
typedef struct BuiltinCommand
{
	char *built_inn;
	int (*function)(ProgramData *data);
} BuiltinCommand;
/************* MAIN FUNCTIONS *************/


/*======== shell.c ========*/

/* Incialize the struct with the info of the program */
void initialize_data(ProgramData *data, int argc, char *argv[], char **env);

/* Makes the infinite loop that shows the prompt*/
void run_shell(char *prompt, ProgramData *data);

/*====== _getline.c ========*/

/* Read one line of the standard input*/
int read_line(ProgramData *data);

/* split the each line for the logical operators if it exist */
int check_logic_operators(char *commands_array[], int i, char operators_array[]);


/* expand vars */
void expand_vars(ProgramData *data);

/* expand alias */
void expand_alias(ProgramData *data);

/* append the string to the end of the buffer*/
int buffer_append(char *buffer, char *str_to_add);

/*======== str_tok.c ========*/

/* Separate the string in tokens using a designed delimiter */
void tokenize(ProgramData *data);

/* Creates a pointer to a part of a string */
char  *custom_strtok(char *line, char *delim);

/*======== execute.c ========*/

/* Execute a command with its entire path */
int execute_command(ProgramData *data);

/*======== bultins_list.c ========*/

/* If match a builtin, executes it */
int execute_builtins(ProgramData *data);

/*======== find_in_path.c ========*/

/* Creates an array of the path directories */
char **tokenize_path(ProgramData *data);

/* Search for program in path */
int find_program_in_path(ProgramData *data);

/************** HELPERS FOR MEMORY MANAGMENT **************/



/*======== HELPERS_FREE.C ========*/
/* Frees the memory for directories */
void free_array_of_pointers(char **directories);
void freeArrayOfPointers(char **array);

/* Free the fields needed each loop */
void freeRecurrentData(ProgramData *data);

/************** BUILTINS **************/



/*======== builtins_more.c  ========*/

/* Close the shell */
int execute_exit(ProgramData *data);

/*change the current directory */
int execute_cd(ProgramData *data);

/* set the work directory */
int set_work_directory(ProgramData *data, char *new_dir);

/* show help information */
int execute_help(ProgramData *data);

/* set, unset and show alias */
int execute_alias(ProgramData *data);

int  show_environment(ProgramData *data);
void handle_ctrl_c(int opr UNUSED);
void handle_ctrl_c(int signal UNUSED);
/* create or override a variable of enviroment */
int set_environment_variable(ProgramData *data);

/* delete a variable of enviroment */
int unset_environment_variable(ProgramData *data);


/*======== env_management.c ========*/

/* Gets the value of an enviroment variable */
char *get_key_from_env(char *key, ProgramData *data);


/* Overwrite the value of the enviroment variable */
int set_key_in_env(char *key, char *value, ProgramData *data);

/* Remove a key from the enviroment */
int remove_key_from_env(char *key, ProgramData *data);

/* Prints the current environ */
void print_environ_data(ProgramData *data);



/************** HELPERS FOR PRINTING **************/


/*======== helpers_print.c ========*/

/* prints a string in the standard output */
int print_to_stdout(char *string);

/* prints a string in the standard error */
int print_to_stderr(char *string);

/*prints a string in the standard error */
int print_error_message(int error_code, ProgramData *data);

/************** HELPERS FOR STRINGS MANAGMENT **************/



/*======== helpers_string.c ========*/

/* Counts the number of characters of a string */
int string_length(char *string);

/* Duplicates an string */
char *string_duplicate(char *string);

/* Compares two strings */
int string_compare(char *string1, char *string2, int number);

/* concatenates two strings */
char *string_concat(char *string1, char *string2);
int display_alias(ProgramData *data, char *alias_name);
/* Reverse a string */
void string_reverse(char *string);

/*======== helpers_numbers.c ========*/


/* Cast from int to string */
void long_to_string(long number, char *string, int base);

/* Convert an string in to a number */
int _atoi(char *s);

/* count the coincidences of character in string */
int count_characters(char *string, char *character);



/* get the alias name */
char *get_alias_value(ProgramData *data, char *alias_name);

/* set the alias name */
int set_alias_value(char *alias_string, ProgramData *data);
int check_file(char *path);
void custom_tokenize(ProgramData *data);
void freeAllData(ProgramData *data);

#endif /* SHELL_H */
