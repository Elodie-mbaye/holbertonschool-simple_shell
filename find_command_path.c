#include "shell.h"

/**
 * find_command_path - Finds the full path of a command
 * @command: The command provided
 *
 * Return: Full path of the command if found, otherwise NULL
 */
char *find_command_path(char *command)
{
	char *path_env;
	char *path;
	char *token;
	char full_path[1024];

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	path_env = _getenv("PATH");

	if (!path_env)
		return (NULL);

	path = strdup(path_env);
	token = strtok(path, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
