#include "shell.h"
#include <unistd.h>
/**
 * shell_interactive - line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line = NULL;
	char *args[2];
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		
		args[0] = line;
		args[1] = NULL;

		if (execute_args(args) == -1)
			perror("Error");
	}
}
