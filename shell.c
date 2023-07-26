#include "shell.h"

/**
 * main - initialize the variables of the program
 * @argc: number of values recieved from the command line
 * @argv: values recieved from the command line
 * @env: enviroment variable recieved from the command line
 * Return: zero on success.
 */
int main(int argc, char *argv[], char *env[])
{
ProgramData data_struct = {NULL}, *data = &data_struct;
char *prompt = "";

initialize_data(data, argc, argv, env);

signal(SIGINT, handle_ctrl_c);

if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
{
/* We are in terminal, interactive mode */
errno = 2;
prompt = PROMPT_MSG;
}
errno = 0;
run_shell(prompt, data);
return (0);
}

/**
 * handle_ctrl_c - print in the new line when the signal
 * SIGINT (ctrl + c) is sent to the program.
 * @UNUSED: option of the prototype
 */
void handle_ctrl_c(int signal UNUSED)
{
	print_to_stdout("\n");
	print_to_stdout(PROMPT_MSG);
}

/**
 * initialize_data - initializes the struct with the info of the program
 * @data: pointer of the structure data
 * @argv: array of arguments passed to the program execution
 * @env: enviroment passed to the program execution
 * @argc: number of values recieved from the command line
 */
void initialize_data(ProgramData *data, int argc, char *argv[], char **env)
{
int i = 0;

data->program_name = argv[0];
data->input_line = NULL;
data->command_name = NULL;
data->exec_counter = 0;
/* define the file descriptor to be read */
if (argc == 1)
data->file_descriptor = STDIN_FILENO;
else
{
data->file_descriptor = open(argv[1], O_RDONLY);
if (data->file_descriptor == -1)
{
print_to_stderr(data->program_name);
print_to_stderr(": 0: can't open ");
print_to_stderr(argv[1]);
print_to_stderr("\n");
exit(127);
}
}
data->tokens = NULL;
data->env = malloc(sizeof(char *) * 50);
if (env)
{
for (; env[i]; i++)
{
data->env[i] = string_duplicate(env[i]);
}
}
data->env[i] = NULL;
env = data->env;
data->alias_list = malloc(sizeof(char *) * 20);
for  (i = 0; i < 20; i++)
{
data->alias_list[i] = NULL;
}
}

/**
 * run_shell - an infinite loop that shows the prompt
 * @prompt: prompt to be printed
 * @data: a pointer to the program's data
 */
void run_shell(char *prompt, ProgramData *data)
{
int error_code = 0, string_len = 0;

while (++(data->exec_counter))
{
print_to_stdout(prompt);
error_code = string_len = read_line(data);
if (error_code == EOF)
{
freeAllData(data);
exit(errno); /* if  EOF is the first character of the string, exit */
}
if (string_len >= 1)
{
expand_alias(data);
expand_vars(data);
custom_tokenize(data);
if (data->tokens[0])
{
error_code = execute_command(data);
if (error_code != 0)
print_error_message(error_code, data);
}
freeRecurrentData(data);
}
}
}
