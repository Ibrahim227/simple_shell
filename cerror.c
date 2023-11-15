#include "main.h"

/**
* _eputs - prints
* @str: str
* Return: void
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
* _eputchar - writes char to stderr
* @s: char to write
* Return: 1 on succss
*/
int _eputchar(char s)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (s == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (s != BUFFER_FLUSH)
		buf[i++] = s;
	return (1);
}


/**
* _putfd - writes the char c to
* @s: char
* @fd: file decrip
* Return: 1 on succes 0 otherwise
*/
int _putfd(char s, int fd)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (s == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (s != BUFFER_FLUSH)
		buf[i++] = s;
	return (1);
}

/**
* _putsfd - prints an input str
* @str: str   to print
* @fd: file descrip
* Return: number of char
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

