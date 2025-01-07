#include "shell.h"
#include <string.h>
#include <sys/wait.h>

/**
 * execute_args - execute a command as a process
 * @args: command and its flags
 *
 * Return: 1 if succefull, 0 otherwise
 */
int execute_args(char **args)
{
	pid_t pid;
	int status;

	char *path = NULL;

	if (!args[0])
		return (1);

	if (strcmp(args[0], "exit") == 0)
		return (0);
	else if (strcmp(args[0], "env") == 0)
		print_env();

	else
	{
		path = is_a_command(args[0]);

		pid = fork();

		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("error during child process");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("error");
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}

		if (path)
			free(path);
	}
	return (1);
}
