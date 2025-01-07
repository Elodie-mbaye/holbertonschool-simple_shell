#include "shell.h"

/**
 * find_in_path - Finds a command in the PATH
 * @command: The command to find
 * Return: Full path to the command, or NULL if not found
 */
char *find_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token;
	char full_path[1024];
	struct stat st;

	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
