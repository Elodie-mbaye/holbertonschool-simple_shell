#include "shell.h"

/**
 * shell_no_interactive - Handles the shell in non interactive mode
 *
 * Return: void
 */
void shell_no_interactive(void)
{
	char *line;
	size_t len = 0;

	while (getline(&line, &len, stdin) != -1)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		execute_command(line);
	}

	free(line);
}
