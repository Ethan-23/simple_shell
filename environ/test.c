#include "shell.h"
char *cool(char *zero)
{
	int lgt = _strlen(zero);
	int i = 0, j = 0;
	char *new;

	new = malloc(sizeof(char) * ((lgt - 5) + 1));
	if (new == NULL)
		return (NULL);

	for (i = 5; zero[i] != '\0'; i++)
	{
		new[j] = zero[i];
		j++;
	}
	new[j + 1] = '\0';
	return (new);

}
int main(int ac __attribute__((unused)), __attribute__((unused))char **av, char **envp)
{
	int i = 0, j = 0, hold = 0;
	char *ar[100];
	char *next = NULL;
        char **env = envp;
	char *other = NULL;
	char *string;

	for (i = 0; env[i] != '\0'; i++)
	{
		next = strtok(env[i], "\n");
		if (_strcmp(next, "PATH") == 0)
		{
			hold = i;
			break;
		}
	}

	other = strtok(envp[hold], ":");
	ar[j] = other;
	while (other != NULL)
	{
		other = strtok(NULL, ":");
		j++;
		ar[j] = other;
	}

	string = cool(ar[0]);
	ar[0] = string;
	free(string);
	printf("ar[0] = %s", ar[0]);

	for (i = 0; ar[i] != '\0'; i++)
		printf("%s\n", ar[i]);
	return (0);
}
