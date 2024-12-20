#include "shell.h"
/**
 * shell_no_interactive - line interpreter
 *
 * Return: void
 *
 */
void shell_no_interactive(void)
{
	char *line;
	char *args[2];
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args[0] = line;
		args[1] = NULL;

		if (execute_args(args) == -1)
			perror("Error");
	}
	free(line);
}
