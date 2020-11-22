#include "shell.h"
int main(int ac, char **av, char **env)
{
	char **path;
	int i = 0;
	(void)ac;
	(void)av;

	path = get_env(env);
	/*printf("got path ! --- %s", path[0]);*/
	for (i = 0; path[i] != '\0'; i++)
		printf("PATH[%d] = %s\n", i, path[i]);
	free(path[0]);
	free(path);
	return (0);
}
