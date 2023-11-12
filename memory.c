#include "main.h"

/**
* _memcpy - copies from src to dest
* @src: source
* @dest: destinnation
* @num: size of memory
* Return: mem
*/
void *_memcpy(void *src, void *dest, size_t num)
{
	char *sdest = (char *)(dest);
	const char *ssrc = (const char *)(src);
	size_t j = 0;

	while (j < num)
	{
		sdest[j] = ssrc[j];
		j++;
	}
	return (dest);
}

/**
* _realloc - realloc func
* @ptr: pointer
* @size: size
* Return:ptr
*/
void *_realloc(void *ptr, size_t size)
{
	void *a_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	a_ptr = malloc(size);
	if (a_ptr == NULL)
		return (NULL);
	_memcpy(a_ptr, ptr, size);
	free(ptr);
	return (a_ptr);
}

/**
* _strdup - strdup()
* @str: str
* Return: dup of str
*/
char *_strdup(char *str)
{
	size_t length = _strlen(str) + 1;
	char *n_str = malloc(length);

	if (n_str == NULL)
	{
		return (NULL);
	}
	_memcpy(n_str, str, length);

	return (n_str);
}

/**
* _strcat - strcat()
* @dest: destination
* @src: source
* Return: path
*/
char *_strcat(char *dest, const char *src)
{
	char *pp = dest;
	int i, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		pp[i] = src[j];
		i++;
		j++;
	}
	pp[i] = '\0';
	return (pp);
}

/**
* _strchr - implementation of strchr
* @strse: str to search
* @strfi: str to find
* Return: path
*/
char *_strchr(const char *strse, int strfi)
{
	while (*strse)
	{
		if (*strse == strfi)
		{
			return ((char *)strse);
		}
		strse++;
	}
	return (NULL);
}

