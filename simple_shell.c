#include "shell.h"
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
 *@name: name of shell
 *@input: command input
 *@count: count of how many commands have been entered
 */
int print_e(char *input, int count)
{
	char *buf;
	char *num = _strnum(count);
	char delim[3] = ": ", name[6] = "./hsh", er[11] = "not found\n";
	int lgt =_strlen(num);
/*makes space with malloc for a string to print errors*/
	buf = malloc((lgt + _strlen(input) + 23) * sizeof(char));
	_strcpy(buf, name);
	_strncat(buf, delim);
	_strncat(buf, num);
	_strncat(buf, delim);
	_strncat(buf, input);
	_strncat(buf, delim);
	_strncat(buf, er);
	write(STDERR_FILENO, buf, _strlen(buf));
	fflush(stdout);
	free(buf);
	free(num);
	return (127);
}
/**
 *s_free - this function frees our two allocated strings line and free
 *@line: the line taken from stdin
 *@argv: our allocated argument list
 */
void s_free(char **argv, char **path, char *line, char *true_path)
{
	if (true_path != NULL)
		free(true_path);
	if (argv != NULL)
		free(argv);
	if (line != NULL)
		free(line);
	if (path != NULL)
	{
		free(path[0]);
		free(path);
	}
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
	int num_char_line, id = 1, count = 0, error = 0;
	size_t buf = 0;
	(void)ac;
	(void)av;
	/*our signal handler / path retrieving function*/
	signal(SIGINT, handler);
	path = get_path(env);
	while (1)
	{
		count++;
		buf = 0;
		line = NULL;
		/*gets line and stuff*/
		if (isatty(STDIN_FILENO) != 0)
			write(1, "$ ", 2);
		num_char_line = getline(&line, &buf, stdin);
		if (num_char_line == -1)
			ctrl_d_handler(line, path, error);
		/*sets our command argument list*/
		argv = set_argv(line);
		if (_strcmp(argv[0], "exit") == 0)
		{
			s_free(argv, path, line, NULL);
			if (error == 127)
				exit(2);
			exit(2);
		}
		if (_strcmp(argv[0], "env") == 0)
			print_env(env);
		/*gets path with command appened to end of each directory*/
		true_path = handle_path(path, argv);
		/*forks the main proccess*/
		if (true_path != NULL)
			id = fork();
		else
			error = print_e(argv[0], count);
		if (id == -1)
			print_e(line, count);
		if (id == 0)
			execve(true_path, argv, NULL);
		/*waits for child and frees memory for next loop*/
		if (id != 0)
			wait(NULL);
		s_free(argv, NULL, line, true_path);
		fflush(stdout);
	}
	s_free(argv, path, line, NULL);
	return (0);
}
