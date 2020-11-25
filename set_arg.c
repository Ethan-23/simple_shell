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
	{
		if (line[i] == ' ')
		{
			if (line[i + 1] == ' ')
				line[i] = '\0';
			else
				delim_count++;
		}
	}
	/*adds two: one for NULL at end*/
	/*adds another for the first argument no matter what*/
	return (delim_count + 2);
}
/**
 *set_argv - this function will take the given command line and turn it
 * into a an array of strings for execve
 *@line: the command line given
 *Return: returns a pointer to the new array of strings to get sent to main
 */
char **set_argv(char *line)
{
	/*next is the next argument in the line using strtok*/
	char *next = NULL;
	/*our argv list*/
	char **argv;
	/*counter variables*/
	int i = 0, j = 0;
	if (line == NULL)
		return (NULL);
	/*mallocs our argv list based on how many args passed to shell*/
	argv = malloc(sizeof(char *) * num_of_strings(line));
	if (argv == NULL)
		return (NULL);
	/*gets the command (first argument in the list)*/
	next = strtok(line, " ");
	argv[i] = next;
	/*finds the rest of the arguments for the list*/
	while (next != NULL)
	{
		next = strtok(NULL, " ");
		i++;
		argv[i] = next;
	}
	/*goes back to last element before NULL assignemnt*/
	i -= 1;
	/*removes the /n and replaces it with new NULL byte*/
	for (j = 0; argv[i][j] != '\0'; j++)
		if (argv[i][j] == '\n')
			argv[i][j] = '\0';
	/*goes back to last index of argv and sets it to NULL*/
	argv[i + 1] = NULL;
	return (argv);
}
