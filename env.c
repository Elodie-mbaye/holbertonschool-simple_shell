#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * _getenv - gets the value of an environment
 * @name: Name of the environment variable
 * Return: Pointer to the value or Null if not found
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}
	return (NULL);
}
/**
 * print_env - Prints all environment variables
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
