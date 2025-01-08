#include "shell.h"

/**
 * tokenize - Splits user input into command arguments
 * @line: User input string
 *
 * Return: Array of arguments
 */
char **tokensize(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (!tokens)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * free_args - Frees memory used for command arguments
 * @args: Array of arguments
 */
void free_args(char **args)
{
	int i;

	if (args)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
}

