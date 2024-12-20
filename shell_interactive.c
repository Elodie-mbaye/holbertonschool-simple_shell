#include "shell.h"
/**
 * shell_interactive - line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("simple_shell$");

		line = read_line();
		args = parse_line(line);
		status = execute_args(args);

		free(line);
		free(args);

	} while (status);
}
