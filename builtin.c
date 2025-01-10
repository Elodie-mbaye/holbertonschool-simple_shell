#include "shell.h"

/**
 * handle_builtin_commands - Handles built-in commands
 * @args: Array of command arguments
 * @user_input: Raw user input
 */
void handle_builtin_commands(char **args, char *user_input)
{
	if (args[0] != NULL)
	{

		if (strncmp(args[0], "exit") == 0)
		{
			free_args(args);
			free(user_input);
			exit(EXIT_SUCCESS);
		}

		if (strncmp(args[0], "env") == 0)
		{
			print_env();
		}
		execute_command(args);
	}
}
