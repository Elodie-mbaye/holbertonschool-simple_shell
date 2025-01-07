#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * get_path_env - Retrieves the value of the PATH environment variable.
 *
 * Return: Pointer to the value of PATH, or NULL if not found.
 */
char *get_path_env(void)
{
	int i = 0;
	char **environ;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			return (environ[i] + 5);
		}
		i++;
	}
	printf("PATH environment variable not found\n");
	return (NULL);
}
/**
 * get_command_path - Searches for an executable file in
 * the directories of PATH.
 * @command: Name of the file or command to search for.
 *
 * Return: Full path to the executable file, or NULL if not found.
 */
char *get_command_path(char *command)
{
	char *path = get_path_env();
	char *token = NULL, *full_path = NULL;
	char *path_copy;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	if (access(command, X_OK) == 0)
	{
		free(path_copy);
		return (strdup(command));
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	printf("%s: not found\n", command);
	return (NULL);
}
