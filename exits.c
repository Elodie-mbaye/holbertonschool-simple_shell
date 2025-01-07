#include "shell.h"
/**
 * free_array - function that frees
 * @array: a array pointer 
 * Return: void
 */
void free_array(char **array)
{
	int i = 0;
	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}
/**
 * exit_shell - Exit shell
 *
 * @line: string
 * @args: Array of arguments
 *
 * Return: void
 */
void exit_shell(char *line)
{
	free(line);
	exit(EXIT_SUCCESS);
}

