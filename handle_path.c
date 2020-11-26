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

	lgt2 = _strlen(com);
	lgt = _strlen(path);
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
 * handle_path - this function determines whether the command entered exists
 *@path: our environmental variables
 *@argv: our argument lis (exp.(ls -a -b))
 *Return: 0
 */
void *handle_path(char **path, char **argv)
{
	int i = 0, j = 0, lgt = 0;
	char *true_p, **copy;

	if (access(argv[0], F_OK) == 0)
	{
		true_p = malloc((_strlen(argv[0]) + 1) * sizeof(char));
		if (true_p == NULL)
			return (NULL);
		_strcpy(true_p, argv[0]);
		return (true_p);
	}
	for (j = 0; path[j] != '\0'; j++)
		lgt++;
	copy = malloc((lgt + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	for (j = 0; path[j] != '\0'; j++)
		copy[j] = path[j];
	copy[j] = NULL;
	for (i = 0; copy[i] != '\0'; i++)
	{
		copy[i] = command_path(argv[0], copy[i]);
		if ((access(copy[i], F_OK)) == 0)
		{
			true_p = malloc((_strlen(copy[i]) + 1) * sizeof(char));
			if (true_p == NULL)
				return (NULL);
			_strcpy(true_p, copy[i]);
			free(copy[i]);
			free(copy);
			return (true_p);
		}
		free(copy[i]);
	}
	free(copy);
	return (NULL);
}
