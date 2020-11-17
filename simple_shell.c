#include "shell.h"
/**
 *main - this is the main file for a simple shell
 *Return: returns 0 on completion
 */
int main(void)
{
	char *line = NULL, **argv;
	int num_char_line, id;
	size_t buf = 0;
	/*int count = 0;*/
	int error_check;

	/*gets line and prints interface*/
	while (1)
	{
		line = NULL;
		write(2, "($)", 3);
		num_char_line = getline(&line, &buf, stdin);
		if (num_char_line == -1)
			return (-1);
		argv = set_argv(line);
		if (strcmp(argv[0], "exit") == 0)
			break;
		/*for (count = 0; argv[count] != '\0'; count++)
		  printf("%s\n", argv[count]);*/
		id = fork();
		if (id == 0)
		{
			error_check = execve(argv[0], argv, NULL);
			if (error_check == -1)
				perror("Error: ");
			_exit(0);
		}
		if (id != 0)
			wait(NULL);
		free(argv);
		free(line);
		fflush(stdout);
	}
	free(argv);
	free(line);
	return (0);
}
