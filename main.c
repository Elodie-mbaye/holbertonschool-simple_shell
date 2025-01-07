#include "shell.h"

/**
 * main - Entry point of the shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		line[nread - 1] = '\0';
		if (strlen(line) > 0)
		{
			if (strcmp(line, "exit") == 0)
				break;

			if (strcmp(line, "env") == 0)
			{
				print_env();
				continue;
			}

			execute_command(line);
		}
	}

	free(line);
	return (0);
}
