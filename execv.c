#include "shell.h"

/**
 * execute_command - function that executes the received command
 * @args: command received in an array after split_string
 * Return: 1 on success
 */

int execute_command(char **args)
{
    pid_t pid;
    int status;
    char *command_path;

    if (!args || !args[0])
        return (1);

    command_path = get_path(args[0]);

    if (!command_path)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return (1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error fork");
        free(command_path);
        return (1);
    }

    if (pid == 0)
    {
        if (execve(command_path, args, environ) == -1)
        {
            perror("Error execve");
            free(command_path);
            exit(1);
        }
    }
    else
        wait(&status);

    free(command_path);
    return (0);
}
