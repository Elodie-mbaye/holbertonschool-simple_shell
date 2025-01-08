#include "shell.h"

/**
 * execute_command - Executes an external command
 *
 * @args: Array of command arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path = find_command_path(args[0]);

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", args[0]);
		return;
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("./hsh not found");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free(path);
}
