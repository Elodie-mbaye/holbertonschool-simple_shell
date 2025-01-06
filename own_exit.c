#include "shell.h"

/**
 * own_exit - couses normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int own_exit(char **args)
{
	int status = 0;

	if (args[1])
	{
		status = atoi(args[1]);
		if (status < 0)
		{
			fprintf(stderr, "exit: invalid status: %s\n", args[1]);
			return (1);
		}
	}
	exit(status);
}
