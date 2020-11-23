#include "shell.h"
/**
 *command_path - this function adds path directory to whatever command was givn
 *@com: takes in the given command
 *@path: takes in the given path directory
 *Return: returns a new string to the new command
 */
char *command_path(char *com, char *path)
{
	int lgt = 0, lgt2 = 0;
	int max = 0, hold = 0;
	char *new = NULL;
	int i = 0, j = 0;

	while (com[lgt2] != '\0')
		lgt2++;
	while (path[lgt] != '\0')
		lgt++;
	max = lgt + lgt2 + 2;
	new = malloc(max * sizeof(char));
	if (new == NULL)
		return (NULL);

	for (i = 0; path[i] != '\0'; i++)
		new[i] = path[i];
	hold = i + 1;
	new[hold - 1] = '/';
	for (j = 0; com[j] != '\0'; j++)
	{
		new[hold] = com[j];
		hold++;
	}
	new[hold] = '\0';
	return (new);
}
/**
 *handle_path - this function determines whether the command entered exists
 *@env: our environmental variables
 *@argv: our argument lis (exp.(ls -a -b))
 */
void handle_path(char **env, char **argv)
{
	int i = 0;
	char **path;
	int check;

	path = get_path(env);

	for (i = 0; path[i] != '\0'; i++)
	{
		path[i] = command_path(argv[0], path[i]);
		if ((access(path[i], F_OK)) == 0)
		{
			execve(path[i], argv, NULL);
			check = 1;
			free(path[i]);
			break;
		}
		free(path[i]);
	}

	if (check != 1)
	{
		check = execve(argv[0], argv, NULL);
		perror("Error: ");
	}
	free(path);
}
