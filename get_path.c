#include "shell.h"
/**
 *num_of_s - will find the total number of string on the command line
 *@line: the commands line input
 *Return: returns the total number of strings on the line
 */
int num_of_s(char *line)
{
	size_t i = 0;
	int delim_count = 0;

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == ':')
			delim_count++;
/*adds two: one for NULL at end*/
/*adds another for the first argument no matter what*/
	return (delim_count + 2);
}
/**
 *rm_path - this function will remove the PATH= from first delimted path
 *@path_zero: the first index of our path array
 *Return: returns the new string back to get_env
 */
char *rm_path(char *path_zero)
{
	int i = 0, j = 0;

	for (i = 5; path_zero[i] != '\0'; i++)
	{
		path_zero[j] = path_zero[i];
		j++;
	}
	path_zero[j] = '\0';
	return (path_zero);
}
/**
 *get_path - this function gets the path from environment
 *@env: The list of all environmental variables
 *Return: returns a list of directories from path
 */
char **get_path(char **env)
{
	char **path;
	char *next = NULL;
	int i = 0, j = 0, hold = 0;

	for (i = 0; env[i] != '\0'; i++)
	{
		next = strtok(env[i], "\n");
		if (_strcmp(next, "PATH") == 0)
		{
			hold = i;
			break;
		}
	}
	path = malloc(sizeof(char *) * num_of_s(env[i]));
	if (path == NULL)
		return (NULL);

	next = strtok(env[hold], ":");
	path[j] = rm_path(next);
	while (next != NULL)
	{
		next = strtok(NULL, ":");
		j++;
		path[j] = next;
	}
	path[j] = NULL;
	return (path);
}
