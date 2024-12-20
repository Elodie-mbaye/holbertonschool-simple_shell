#include "shell.h"
#include <sys/stat.h>
/**
 * print_env - prints environment variables
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
 * _getenv - retrieves the value of an environment variable
 * @env_var: Name of the variable value
 *
 * Return: variable value or NULL if not found
 */
char *_getenv(const char *env_var)
{
	char **env = environ;
	int i = 0;
	char *key;

	while (env[i])
	{
		key = strtok(env[i], "=");
		if (strcmp(env_var, key) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

/**
 * is_a_command - Checks is a command is executable or finds is way
 * @args:name of the command
 *
 * Return: string of the command or NULL if not found
 */
char *is_a_command(char *args)
{
	char *env = _getenv("PATH"), *token, *tmp;
	struct stat st;

	if (!env)
		return (NULL);
	if (access(args, X_OK) == 0)
		return (strdup(args));

	token = strtok(env, ":");

	while (token)
	{
		tmp = malloc(strlen(token) + strlen(args) + 2);

		if (!tmp)
		{
			perror("Allocation failed");
			return (NULL);
		}

		strcpy(tmp, token);
		strcat(tmp, "/");
		strcat(tmp, args);

		if (stat(tmp, &st) == 0)
			return (tmp);

		free(tmp);

		token = strtok(NULL, ":");
	}

	return (NULL);
}
