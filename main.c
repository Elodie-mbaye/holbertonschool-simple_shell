#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char **args = NULL;
	char *_input = NULL;

	signal(SIGINT, _signint);

	while (1)
	{
		print_prompt();
		_input = read_line();
		args = tokenize(_input);
		_builtin_commands(args, _input);
		free_args(args);
		free(_input);
	}
	return (0);
}
