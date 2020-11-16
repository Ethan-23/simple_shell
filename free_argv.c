#include "shell.h"
/**
 *free_argv - will free an array of strings
 *@argv: the array of strings to be freed
 */
void free_argv(char **argv)
{
	int i = 0;

	for (i = 0; argv[i] != '\0'; i++)
		free(argv[i]);
	free(argv);
}
