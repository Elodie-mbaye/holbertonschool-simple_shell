#include "shell.h"
/**
 * print_prompt - Displays the shell prompt
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
/**
 * read_command - Reads a command from the user
 *
 * Return: Pointer to the command string, or NULL on EOF
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	return (line);
}
/**
 * execute_command - Executes a command in a child process
 * @line: The command to execute
 */
void execute_command(char *line)
{
	int status;
	char *args[2];
	pid_t pid;

	args[0] = line;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
