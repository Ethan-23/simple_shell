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
/**
 *_strcpy - this function copys a string into another string
 *@dest: the destination string
 *@src: the source string
 *Return: returns the pointer value of the destination (aka the copied string)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
#include "shell.h"
/**
 *_strlen - a function that retunrs the length of a string
 *@s: the string that we need to check the length of
 *Return: returns the length of the string once found
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}

	return (i);
}
