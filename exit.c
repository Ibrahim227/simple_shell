#include "main.h"

/**
**_strncpy - copies a str
* @dest: destination
* @src: source
* @m: amouunt of char
* Return: the str
*/
char *_strncpy(char *dest, char *src, int m)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < m - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < m)
	{
		j = 0;
		while (j < 0)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
**_strncat - concatenete 2 str
* @dest: destination
* @src: source
* @m: amout of char
* Return: src
*/
char *_strncat(char *dest, char *src, int m)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < m)
		dest[i] = '\0';
	return (s);
}

/**
**_strchr - locate char
* @s: str
* @c: char
* Return: a pointer
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

