#include "shell.h"
/**
 *num_of_strings - will find the total number of string on the command line
 *@line: the commands line input
 *Return: returns the total number of strings on the line
 */
int num_of_strings(char *line)
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
 *
 */
char *rm_path(char *path_zero)
{
	int lgt = _strlen(path_zero);
        int i = 0, j = 0;
        char *new;

        new = malloc(sizeof(char) * ((lgt - 5) + 2));
        if (new == NULL)
                return (NULL);

        for (i = 5; path_zero[i] != '\0'; i++)
        {
                new[j] = path_zero[i];
                j++;
        }
        new[j + 1] = '\0';
        return (new);
}
/**
 *
 */
char **get_env(char **env)
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
	path = malloc(sizeof(char *) * num_of_strings(env[i]));
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

	/*path[0] = rm_path(path[0]);*/
	return (path);
}
