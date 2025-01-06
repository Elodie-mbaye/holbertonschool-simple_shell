#include "shell.h"

/**
 * own_env - function that prints enviroment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int own_env(char **args)
{
	int i = 0;

	(void)args;

	while (environ[i])
	{
		if (write(STDOUT_FILENO, environ[i], strlen(environ[i])) == -1)
		{
			perror("env");
			return (0);
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
