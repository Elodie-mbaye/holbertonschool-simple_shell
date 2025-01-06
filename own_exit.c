#include "shell.h"
#include <ctype.h>

/**
 * own_exit - Handles the "exit" built-in command to terminate the shell.
 * @args: Array of arguments. Optionally includes an exit status as args[1].
 *
 * Return: Does not return, the process is terminated.
 */
int own_exit(char **args)
{
	int status = 0;
	int i;

	if (args[1])
	{
		for (i = 0; args[1][i]; i++)
		{
			if (!isdigit(args[1][i]))
			{
				write(STDERR_FILENO, "exit: numeric argument required\n", 32);
				return (1);
			}
		}
		status = atoi(args[1]);
	}
	exit(status);
}
