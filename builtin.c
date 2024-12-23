#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _myexit - built in command "exit"
 * @args: arguments command
 *
 * Description:
 * exit shell succes
 * if the arguments is numeric exit
 * if the arguments is invalid error
 *
 * Return: -1 or 0
 */
int _myexit(char **args)
{
	int i;

	if (args[1])
	{
		for (i = 0; args[1][i]; i++)
		{
			if (args[1][i] < '0' || args[1][i] > '9')
			{
				printf("exit: %s: numeric argument required\n", args[1]);
				return (0);
			}
		}
		exit(atoi(args[1]));
	}
	exit(0);
}
/**
 * _mycd - command "cd"
 * @args: arguments command
 *
 * Description:
 * change repertory
 * if no arguments, go to the Home repertory
 * if "-", come back to the previous repertory
 *
 * Return: 0 if success, 1 when failure
 */
int _mycd(char **args)
{
	char *dir;

	if (!args[1])
		dir = getenv("HOME");
	else if (strcmp(args[1], "-") == 0)
		dir = getenv("OLDPWD");
	else
		dir = args[1];

	if (dir == NULL || chdir(dir) == -1)
	{
			perror("cd");
			return (1);
	}

			return (0);
}
/**
 * _myhelp - command "help"
 * @args: arguments command
 *
 * Description:
 * print a message help
 * Return: 0
 */
int _myhelp(char **args)
{
(void)args;
printf("simple shell - Built-in commands\n");
printf("exit: Exit the shell\n");
printf("cd: Change directory\n");
printf("help: Display this help message\n");
return (0);
}
