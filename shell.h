#ifndef SHELL_H
#define SHELL_H

#define TOK_DELIM " \t\r\n\a\""

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *read_line(void);
char **tokensize(char *line);
void free_args(char **args);
void execute_command(char **args);
char *find_command_path(char *command);
void handle_builtin_commands(char **args, char *user_input);
void print_env(void);
void print_prompt(void);
int main(void);
void change_directory(char *path);
char *_getenv(const char *name);
void _signint(int signint);
#endif
