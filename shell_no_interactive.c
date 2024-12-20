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
	char **args;
	int status = -1;

	do {
		line = read_stream();
		args = parse_line(line);
		status = execute_args(args);

		free(line);
		free(args);
	} while (status);
}
