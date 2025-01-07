#include "shell.h"
#include <stdlib.h>
/**
 * parse_line - parse a string into multiple strings
 * @line: string to be parsed
 *
 * Return: pointer that points to the new array
 */
char **parse_line(char *line)
{
	int bufsize = 100;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		fprintf(stderr, "allocation error in parse_line: tokens\n");

	token = strtok(line, TOK_DELIM);

	while (token)
	{
		if (i >= bufsize)
		{
			fprintf(stderr, "buffer size exceded\n");
			exit(EXIT_FAILURE);
		}

		tokens[i] = strdup(token);
		i++;

		token = strtok(NULL, TOK_DELIM);
	}

	tokens[i] = NULL;

	return (tokens);
}
