#include "main.h"

/**
 * _strcpy - copies a str
 * @dest: destination
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}


/**
 * _strdup - duplicates a str
 * @str: str to _stdup
 *
 * Return: pointer _strdup
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}


/**
 *_puts - prints an input str
 *@str: str to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the char c to stdout
 * @c: The char to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	static int i;
	static char buff[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buff[i++] = c;
	return (1);
}

