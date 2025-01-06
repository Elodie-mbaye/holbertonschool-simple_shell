#include "shell.h"

/**
 * own_env - Prints the current environment variables.
 * @args: Array of arguments (unused).
 *
 * Return: 1 on success, 0 on failure.
 */
int own_env(char **args)
{
	int i = 0;

	(void)args;

	while (environ[i])
	{
		if (write(STDOUT_FILENO, environ[i], strlen(environ[i])) == -1)
		{
			return (0);
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
