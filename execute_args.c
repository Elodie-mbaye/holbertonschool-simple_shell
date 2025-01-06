#include "shell.h"

/**
 * execute_args - Executes built-in or external commands.
 * @args: Command and its arguments.
 *
 * Return: 1 to continue, 0 to exit.
 */
int execute_args(char **args)
{
	if (!args || !args[0])
		return (1);

	if (strcmp(args[0], "exit") == 0)
		return (own_exit(args));

	if (strcmp(args[0], "env") == 0)
		return (own_env(args));

	return (new_process(args));
}
