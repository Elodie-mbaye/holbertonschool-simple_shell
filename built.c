#include "shell.h"
/**
 * built - Gère l'exécution des commandes internes du shell
 * @args: Tableau de chaînes de caractères représentant la commande
 *
 * Return: Null or 1
 */
int built(char **args)
{

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	if (strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exits") == 0)
	{
		free(args);
		exit(0);
	}
	if (strcmp(args[0], "cd") == 0)
	{
		change_directory(args[1]);
		return (1);
	}
	return (0);
}
/**
 * change_directory - change the repertory
 * @path: root repertory
 */
void change_directory(char *path)
{
	if (path == NULL || chdir(path) != 0)
	{
		perror("Error change repertory");
	}
}
