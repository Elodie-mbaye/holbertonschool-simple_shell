#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * execute - Execute a command and its arguments in a separate process.
 * @args: Array of strings containing the command and arguments to execute.
 *
 * Return: 0 on success, -1 or 127 on failure.
 */
int execute_args(char **args)
{
	int status;
	char *env[] = {NULL};
	pid_t pid;

	if (args == NULL)
		return (-1);


	pid = fork();

	if (pid == -1)
	{
		free(args);
		perror("Error");
		_exit(-1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			free(args);
			perror("Execution failed");
			_exit(127);
		}
	}

	else
		wait(&status);

	return (0);
}
