#include "shell.h"
/**
 * exit_shell - Exit shell
 *
 * @line: string
 * @args: Array of arguments
 *
 * Return: void
 */
void exit_shell(char *line, char **args)
{
	free(line);
	free_array(args);
	exit(EXIT_SUCCESS);
}
