#ifndef _SHELL_H_
#define _SHELL_H_


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

extern char **environ;
#define PROMPT "$ "
void execute_command(char *line);
char *find_in_path(char *command);
char **split_line(char *line);
void print_env(void);




#endif
