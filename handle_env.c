#include "shell.h"
/**
 *print_env - just prints the current environmental variables
 *@env: our environment
 */
void print_env(char **env)
{
	int i = 0;
	int lgt = 0;

	for (i = 0; env[i] != '\0'; i++)
	{
		lgt = _strlen(env[i]);
		write(1, env[i], lgt);
		_putchar('\n');
	}
}
