#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char **args = NULL;
	char *user_input = NULL;

	signal(SIGINT, _signint);

	while (1)
	{
		print_prompt();
		user_input = read_line();
		args = tokensize(user_input);
		handle_builtin_commands(args, user_input);
		free_args(args);
		free(user_input);
	}
	return (0);
}
