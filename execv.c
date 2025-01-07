#include "shell.h"

/**
 * execute_command - Executes a command using execve
 * @line: Command line entered by the user
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char **argv = split_line(line);
	char *command_path = find_in_path(argv[0]);

	if (!command_path)
	{
		fprintf(stderr, "./shell: %s: command not found\n", argv[0]);
		free(argv);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("fork");
	}

	free(argv);
	free(command_path);
}
