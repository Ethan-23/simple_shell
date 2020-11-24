#include "shell.h"
/**
 *ctrl_d_handler - handle the EOF built in
 *@line: takes line so we can free it properly
 */
void ctrl_d_handler(char *line)
{
	if (isatty(fileno(stdin)))
		_putchar('\n');
	free(line);
	exit(0);
}
/**
 *handler - handles out signal for ctrl + c
 *@a: our signal holder value
 */
void handler(int a)
{
	(void)a;
	write(1, "\n$ ", 3);
}
/**
 *print_e - prints current error using perror function (if fork fails)
 *@val: the error integer returned by whatever function
 */
void print_e(int val)
{
	if (val == -1)
	{
		perror("error: ");
		/*exit entire program with failure*/
		exit(1);
	}
}
/**
 *s_free - this function frees our two allocated strings line and free
 *@line: the line taken from stdin
 *@argv: our allocated argument list
 */
void s_free(char **argv, char *line)
{
	free(argv);
	free(line);
}
/**
 *main - this is the main file for a simple shell
 *@ac: argument count (UNUSED)
 *@av: argument list (UNUSED)
 *@env: environment from shell
 *Return: returns 0 on completion
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL, *true_path, **path, **argv;
	int num_char_line, id;
	size_t buf = 0;
	(void)ac;
	(void)av;

	signal(SIGINT, handler);
	path = get_path(env);
	while (1)
	{
		buf = 0;
		line = NULL;
		if (isatty(fileno(stdin)))
			write(1, "$ ", 2);
		num_char_line = getline(&line, &buf, stdin);
		if (num_char_line == -1)
			ctrl_d_handler(line);
		argv = set_argv(line);
		if (strcmp(argv[0], "exit") == 0)
			break;
		if (strcmp(argv[0], "env") == 0)
			print_env(env);
		true_path = handle_path(path, argv);
		id = fork();
		if (id == -1)
			print_e(-1);
		if (id == 0)
		{
			if (true_path != NULL)
				execve(true_path, argv, NULL);
			else
			{
				printf("doesnt exist: %s\n", true_path);
				free(true_path);
				free(path);
				s_free(argv, line);
				_exit(0);
			}
		}
		if (id != 0)
			wait(NULL);
		free(true_path);
		s_free(argv, line);
		fflush(stdout);
	}
	free(path);
	s_free(argv, line);
	return (0);
}
