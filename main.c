#include "shell.h"

int main(void)
{
    char *line = NULL;
    char **args = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int i;

    while (1)
    {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            break;
        }

        line[strcspn(line, "\n")] = '\0';
	
	args = split_line(line);
        if (args[0] == NULL)
        {
            free(args);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            free(args);
            free(line);
            exit(EXIT_SUCCESS);
        }
        if (strcmp(args[0], "env") == 0)
        {
            for (i = 0; environ[i]; i++)
	    {
                printf("%s\n", environ[i]);
	    }
            free(args);
            continue;
        }

        pid = fork();
        if (pid == 0)
        {
            if (execvp(args[0], args) == -1)
                perror("Error");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            perror("Fork failed");
        }

        free(args);
    }

    free(line);
    return 0;
}
