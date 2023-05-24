#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
char *my_substr(char *sentence, char *word);
int my_pipline_handler(char *pipeline, char *envp[]);
char **string_tokenization(char *str);
int my_env(char *envp[]);
void fork_execute_function(char **array_string, char *env[]);
char *my_dubler(char *str);
int my_strcmp(const char *string1, const char *string2);
char *my_strcat(const char *str1, const char *str2);
int handle_command(char *command, char *envp[]);
int path_check_function(char *final_string);
void handle_input(char *input, char *envp[]);
char *my_strcpy(char *to, char *from);
int my_strlen(char *str);
ssize_t read_input(char **line_input, size_t *size_input);
char *file_check(char *final_string);
#define PIPELINE_MAX_COMMANDS 2
#define PATH_FOUND 1
#define PATH_NOT_FOUND 0
int sum(int a, int b);
int check_build_in_func(char *final_string, char *envp[]);
#endif
