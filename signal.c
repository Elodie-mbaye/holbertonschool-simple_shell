#include "shell.h"

/**
 * _signint - handles signal interreption
 * @signint : signal received (not used)
 */
void _signint(int signint)
{
	(void)signint;
	write(STDOUT_FILENO, "\n$ ", 3);
}
