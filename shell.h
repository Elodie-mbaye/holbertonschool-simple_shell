#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define TOK_DELIM " \t\r\n\a\""
void  shell_interactive(void);
void  shell_no_interactive(void);
char *read_line(void);
char **parse_line(char *line);
int execute_args(char **args);
int new_process(char **args);
void shell_no_interactive(void);
char *read_stream(void);
#endif
