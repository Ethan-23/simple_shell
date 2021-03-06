#include "shell.h"
/**
 *ctrl_d_handler - handle the EOF built in
 *@line: takes line so we can free it properly
 *@error: error
 *@path: path
 * Return: 0
 */
void ctrl_d_handler(char *line, char **path, int error)
{
	if (isatty(STDIN_FILENO) != 0)
		_putchar('\n');
	free(path[0]);
	free(path);
	free(line);
	if (error == 127)
		exit(error);
	else
		exit(0);
}
