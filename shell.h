#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void free_argv(char **argv);
char **set_argv(char *line);
char **get_path(char **env);
void *handle_path(char **env, char **argv);
void print_env(char **env);
char *_strncat(char *dest, char *src);
void print_e(char *input, int count);
char *_strnum(int num);
#endif
