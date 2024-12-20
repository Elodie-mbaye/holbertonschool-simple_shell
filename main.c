#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		shell_interactive();
	}
	else
	{
		shell_no_interactive();
	}

	return (EXIT_SUCCESS);
}
