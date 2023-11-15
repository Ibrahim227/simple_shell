#include "main.h"

/**
 * _strlen - ret len of a str
 * @c: str
 *
 * Return: int
 */
int _strlen(char *c)
{
	int i = 0;

	if (!c)
		return (0);

	while (*c++)
		i++;
	return (i);
}

/**
 * _strcmp - performs
 * @s1: the first str
 * @s2: the second str
 *
 * Return: neg or pos
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * start_with - checks
 * @has: str to search
 * @nee: the substring to find
 *
 * Return: address of char
 */
char *start_with(const char *has, const char *nee)
{
	while (*nee)
		if (*nee++ != *has++)
			return (NULL);
	return ((char *)has);
}

/**
 * _strcat - concatenates two str
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

