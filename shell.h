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
int new_process(char **args);
void shell_no_interactive(void);
char *read_stream(void);
void print_env(void);
char *_getenv(const char *env_var);
char *is_a_command(char *args);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);
#endif
