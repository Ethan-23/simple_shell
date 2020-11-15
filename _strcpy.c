#include "shell.h"
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
