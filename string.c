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
#include "shell.h"
/**
 *_strncat - concatenates two strings using at most n bytes
 *@dest: Destination string
 *@src: Soruce string
 *Return: returns the destination string
 */
char *_strncat(char *dest, char *src)
{
	int length;
	int i;

	length = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[length] = src[i];
		length++;
	}
	dest[length] = '\0';
	return (dest);
}
#include "shell.h"
/**
 * _strnum - Changes numbers to string
 * @givnum: number given
 * Return: string of num
 */
char *_strnum(int givnum)
{
	char *strnum, *final;
	int count = 1, pow = 1, hold, place = 0;

	hold = givnum;
	for (; hold >= 10; count++, hold /= 10, pow *= 10)
	{}
	strnum = malloc((count + 1) * sizeof(int));
	for (; count >= 1; count--)
	{
		if (givnum >= 10)
		{
			strnum[place] = givnum / pow + '0';
			place++;
			givnum = givnum % pow;
		}
		else
		{
			strnum[place] = givnum % 10 + '0';
			place++;
		}
	}
	strnum[place] = '\0';
	final = strnum;
	return (final);
}
