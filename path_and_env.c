#include "shell.h"

/**
 * print_env - print the environment
 *
 * Return: void
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * _getenv - Retrieves the value of an environment variable by its name.
 *
 * @env_var: The name of the environment variable to look for.
 *
 * Return: NULL if no match is found, or a pointer to
 * the value of the variable.
 */
char *_getenv(const char *env_var)
{
	char **env = environ;
	size_t len = strlen(env_var);

	while (*env)
	{
		if (strncmp(*env, env_var, len) == 0 && (*env)[len] == '=')
			return (*env + len + 1);
		env++;
	}
	return (0);
}

/**
 * is_a_command - Checks if the input corresponds to an executable command
 * by using the PATH environment variable and the access function.
 *
 * @args: The command to check, provided as a string.
 *
 * Return: NULL if the command is not found or an error occurs.
 * Otherwise, returns the full path to the executable.
 */
char *is_a_command(char *args)
{
	char *path, *tmp, *directory, *executable_path;
	struct stat st;

	if (access(args, X_OK) == 0)
		return (strdup(args));

	path = _getenv("PATH");
	if (!path)
		return (0);


	tmp = strdup(path);
	if (!tmp)
		return (0);

	executable_path = malloc(4096);
	if (!executable_path)
	{
		free(tmp);
		return (0);
	}


	directory = strtok(tmp, ":");
	while (directory)
	{
		sprintf(executable_path, "%s/%s", directory, args);

		if (stat(executable_path, &st) == 0 && access(executable_path, X_OK) == 0)
		{
			free(tmp);
			return (executable_path);
		}
		directory = strtok(NULL, ":");
	}

	free(executable_path);
	free(tmp);
	return (0);
}
