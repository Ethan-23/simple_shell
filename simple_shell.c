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
 *@name: name of shell
 *@input: command input
 *@count: count of how many commands have been entered
 */
void print_e(char *input, int count)
{
	char *buf;
	char delim[3] = ": ", name[6] = "./hsh", er[11] = "not found";
	int lgt = _strlen(_strnum(count));
/*makes space with malloc for a string to print errors*/
	buf = malloc((lgt + _strlen(input) + 22) * sizeof(char));
	_strcpy(buf, name);
	_strncat(buf, delim);
	_strncat(buf, _strnum(count));
	_strncat(buf, delim);
	_strncat(buf, input);
	_strncat(buf, delim);
	_strncat(buf, er);
	write(STDERR_FILENO, buf, _strlen(buf));
	_putchar('\n');
	fflush(stdout);
	free(buf);
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
		free(path);
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
	int num_char_line, id, count = 0;
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
		/*prints out $ / gets line*/
		if (isatty(fileno(stdin)))
			write(1, "$ ", 2);
		num_char_line = getline(&line, &buf, stdin);
		if (num_char_line == -1)
			ctrl_d_handler(line);
		/*sets our command argument list*/
		argv = set_argv(line);
		/*checks for built ins*/
		if (strcmp(argv[0], "exit") == 0)
			break;
		if (strcmp(argv[0], "env") == 0)
			print_env(env);
		/*gets path with command appened to end of each directory*/
		true_path = handle_path(path, argv);
		/*forks the main proccess*/
		id = fork();
		if (id == -1)
			print_e(line, count);
		if (id == 0)
		{
			/*checks true_path contains a working directory*/
			if (true_path != NULL)
				/*exectues command if true_path is not working*/
				execve(true_path, argv, NULL);
			else
			{
				/*if execve fails beacuse a command isnt found*/
				print_e(argv[0], count);
				s_free(argv, path, line, true_path);
				_exit(0); /*exits the proccess*/
			}
		}
		/*waits for child and frees memory for next loop*/
		if (id != 0)
			wait(NULL);
		s_free(argv, NULL, line, true_path);
		fflush(stdout);
	}
	s_free(argv, path, line, NULL);
	return (0);
}
