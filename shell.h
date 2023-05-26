#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

void execute_commands(char *commands[], int num_commands,
		int pipefd[][2], char *envp[]);
char **string_tokenization(char *str);
void create_pipes(int pipefd[][2], int num_commands);
void close_unused_pipes(int pipefd[][2], int num_commands);
void close_pipes(int pipefd[][2], int num_commands);
int my_strcmp(const char *string1, const char *string2);
int executeSystemCustom(char *cmd, int inputFd);
char *my_dubler(char *str);
void handle_error(const char *message);
void my_exit(char **argument);
void wait_for_children(int num_commands);
int my_strlen(char *str);

int sum(int a, int b);

void ExecuteCmd(char *cmd);

pid_t createChildProcess(int *inputFd);

int waitForChildProcess(pid_t childPid);

void handleNonTerminalInput(void);

pid_t fork_execute_function(char **array_string, char *env[]);

int handle_command(char *command, char *envp[]);

void handle_input(char *input, char *envp[]);

int my_pipline_handler(char *pipeline, char *envp[]);

ssize_t read_input(char **line_input, size_t *size_input);

char *my_strcpy(char *to, char *from);
int check_build_in_func(char *final_string, char *envp[]);

int path_check_function(char *final_string);

char *file_check(char *final_string);

char *my_substr(char *sentence, char *word);

char *my_strcat(const char *str1, const char *str2);
char *my_dubler(char *str);

int my_strlen(char *str);
char **string_tokenization(char *str);

int my_strcmp(const char *string1, const char *string2);

char *my_dubler(char *str);

int my_strlen(char *str);

char **string_tokenization(char *str);

int my_strcmp(const char *string1, const char *string2);




#define MAX_COMMANDS 10
#define PATH_FOUND 1
#define PIPELINE_MAX_COMMANDS 2
#define PATH_NOT_FOUND 0

#ifndef SHELL_H
#define SELL_H

int my_env(void);

#endif

#endif
