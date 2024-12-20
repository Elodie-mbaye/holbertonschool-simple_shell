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

	if (args[0] == NULL)
	{
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("error during child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("forking error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
