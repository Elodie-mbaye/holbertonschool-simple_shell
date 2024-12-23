#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main shell
 *
 * Return: 0
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
printf("welcome to the shell! Type a command:\n");

while (1)
{
printf("$");

if (getline(&line, &len, stdin) == -1)
{
perror("getline failed");
free(line);
break;
}
printf("You entered:%s", line);
}
free(line);
return (0);
}
