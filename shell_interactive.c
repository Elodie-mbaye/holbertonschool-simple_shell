#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		if (getline(&line, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		execute_command(line);
	}
	free(line);
}
