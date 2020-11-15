#include "shell.h"
/**
 *_strcmp - compares two strings
 *@s1:the first string given
 *@s2:the second string given
 *Return: returns if str1 less than, greater than, or equal too str2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
