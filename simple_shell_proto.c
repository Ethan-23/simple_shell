#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 *bin - this function adds /bin/ to whatever command was given
 *@src: takes in the given command
 *Return: returns a new string to the new command
 */
char *bin(char *src)
{
	char *dest = "/bin/";
	int lgt = 0;
	int lgt2 = 0;
	int max = 0;
	char *new;
	int i = 0;
	int j = 0;
	int hold = 0;

	while (src[lgt2] != '\0')
		lgt2++;
	while (dest[lgt] != '\0')
		lgt++;
	max = lgt + lgt2 + 1;
	new = malloc(max * sizeof(char));
	if (new == NULL)
	{
		printf("sent NULL");
		return (NULL);
	}

	for (i = 0; dest[i] != '\0'; i++)
		new[i] = dest[i];
	hold = i;
	for (j = 0; src[j] != '\0'; j++)
	{
		new[hold] = src[j];
		hold++;
	}
	new[hold] = '\0';
	return (new);
}
/**
 *_strstr - Write a function that locates a substring within a parent string
 *@haystack: the parent string
 *@needle: the substring we are searching for
 *Return: returns null if not found/parent string
 * or returns pointer to the found substring
 */
int main(void)
{
	const char *delim = " ";
	char *line = NULL;
	size_t buf = 0;
	int error;
	char *next = NULL;
	char *argv[100];
	int count = 0;
	int j = 0;
	char *hold;

	printf("($)");
	error = getline(&line, &buf, stdin);
	if (error == -1)
		printf("error");
	next = strtok(line, delim);
	argv[count] = next;

	while(next != NULL)
	{
		next = strtok(NULL, delim);
		count++;
		argv[count] = next;
	}
	/*removes the new line from the last index of argv so it doesnt print one*/
	count -= 1;
	for (j = 0; argv[count][j] != '\0'; j++)
		if (argv[count][j] == '\n')
			argv[count][j] = '\0';

	/*prints out the contents of argv[][]*/
	for (count = 0; argv[count] != '\0'; count++)
		printf("%s\n", argv[count]);
	argv[count + 1] = NULL;

	/*hold will "hold" the string memory from the function so we can free it later*/
	hold = bin(argv[0]);
	argv[0] = hold;
	printf("argv[0]: %s\n", argv[0]);
	/*cannot use valgrind when calling this function so valgrind before hand*/
	execve(argv[0], argv, NULL);
	free(hold);
	free(line);
	return (0);
}
