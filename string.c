#include "main.h"

/**
* _strcmp - compare str
* @str1: str 1
* @str2: str 2
* Return: 0
*/
int _strcmp(const char *str1, const char *str2)
{
	int j = 0;

	while (str1[j] != '\0' && str2[j] != '\0')
	{
		if (str1[j] != str2[j])
		{
			return (str1[j] - str2[j]);
		}
		j++;
	}
	return (str1[j] - str2[j]);
}

/**
* _strncmp - compare str
* @st1: str1
* @st2: str 2
* @m: size
* Return: 0
*/
int _strncmp(const char *st1, const char *st2, size_t m)
{
	size_t i = 0;

	while (i < 0 && st1[i] != '\0' && st2[i] != '\0')
	{
		if (st1[i] != st2[i])
		{
			return (st1[i] - st2[i]);
		}
		i++;
	}
	if (i < m)
	{
		return (st1[i] - st2[i]);
	}
	return (0);
}

/**
* _strlen - str length
* @str: string
* Return: length of str
*/
int _strlen(const char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		j++;
	}
	return (j);
}

/**
* _strncpy - str copy of n
* @dest: destination
* @src: source
* @size: size of char
* Return: 0
*/
int _strncpy(char *dest, char *src, int size)
{
	int i = 0;

	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

/**
* _strcpy - copy str
* @dest: destination
* @src: source
* Return: 0
*/
int _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

