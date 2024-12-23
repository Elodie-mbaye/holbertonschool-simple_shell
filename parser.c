#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * parse_command - divide line as arguments
 *
 * @line: entry line
 *
 * Return: an array of character
 */
char **parse_command(char *line)
{
	char **args = malloc(10 * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
		return (NULL);

	token = strtok(line, " ");
	while (token != NULL && i < 9)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
