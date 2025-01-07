#ifndef SHELL_H
#define SHELL_H

#define TOK_DELIM " \t\r\n\a\""

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void  shell_interactive(void);
void  shell_no_interactive(void);
char *read_line(void);
char **parse_line(char *line);
int execute_args(char **args);
void shell_no_interactive(void);
char *read_stream(void);
char *get_command_path(char *command);
char *get_path_env(char **environ);
void free_array(char **array);
#endif
