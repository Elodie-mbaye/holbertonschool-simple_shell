#include "shell.h"
#include <stdio.h>

/**
 * read_line - read a line from stdlin
 *
 * Return: Pointer that points to a string with a line contents
 *
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t line_length = getline(&line, &bufsize, stdin);

	if (line_length == -1)
	{
		free(line);

		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		perror("getline");
		exit(EXIT_FAILURE);
	}

	if (line[line_length - 1] == '\n')
		line[line_length - 1] = '\0';

	return (line);
}
