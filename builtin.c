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

		if (strncmp(args[0], "exit", 4) == 0)
		{
			int status = 0;

			if (args[1] != NULL)
				status = atoi(args[1]);

			free_args(args);
			free(user_input);
			exit(status);
		}

		else if (strncmp(args[0], "env", 3) == 0)
		{
			print_env();
		}
		else
		{
			execute_command(args);
		}
	}
}

