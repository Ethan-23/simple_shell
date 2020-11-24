#include "shell.h"
/**
 *ctrl_d_handler - handle the EOF built in
 *@line: takes line so we can free it properly
 */
void ctrl_d_handler(char *line, char **path, int error)
{
        if (isatty(STDIN_FILENO) != 0)
                _putchar('\n');
        free(path[0]);
        free(path);
        free(line);
        if (error == 2)
                exit(2);
        else
                exit(0);
}
