#include "shell.h"
/**
 *
 */
void handler(int a)
{
	(void)a;
	write(2, "\n($)", 4);
}
/**
 *print_e - prints current error using perror function
 *@val: the error integer returned by whatever function
 */
void print_e(int val)
{
	if (val == -1)
		perror("error: ");
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
 *Return: returns 0 on completion
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL, **argv;
	int num_char_line, id;
	size_t buf = 0;
	int error_check;
	(void)ac;
	(void)av;
	(void)env;

	signal(SIGINT, handler);
	/*gets line and prints interface*/
	while (1)
	{
		line = NULL;
		/*this may cause memory issued because valgrind doesnt give output for _exit(0)*/
		if (isatty(fileno(stdin)))
			write(2, "($)", 3);
		num_char_line = getline(&line, &buf, stdin);
		if (num_char_line == -1)
		{
			if (isatty(fileno(stdin)))
				_putchar('\n');
		        free(line);
			return (0);
		}

	        argv = set_argv(line);
		if (strcmp(argv[0], "exit") == 0)
			break;
		id = fork();
		if (id == 0)
		{
			error_check = execve(argv[0], argv, NULL);
			print_e(error_check);
			s_free(argv, line);
			_exit(0);
		}
		if (id != 0)
			wait(NULL);
		s_free(argv, line);
		fflush(stdout);
	}
	s_free(argv, line);
	return (0);
}
