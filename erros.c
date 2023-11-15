#include "main.h"

/**
* _erratoi - converts str to int
* @c: str to convert
* Return: 0 if no num 1 otherwise
*/
int _erratoi(char *c)
{
	int i = 0;
	unsigned long int res = 0;

	if (*c == '+')
		c++;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			res *= 10;
			res += (c[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
* print_error - prints an erro
* @info: the pram
* @erstr: str cpecififc
* Return: 0 if numb -1 on error
*/
void print_error(alias_t *info, char *erstr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(erstr);
}

/**
* print_d - func print decimal
* @tip: input
* @fd: file descrip
* Return: number of char
*/
int print_d(int tip, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, actual;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (tip < 0)
	{
		_abs_ = -tip;
		__putchar('-');
		count++;
	}
	else
		_abs_ = tip;
	actual = _abs_;
	for (i = 100000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + actual / i);
			count++;
		}
		actual %= i;
	}
	__putchar('0' + actual);
	count++;

	return (count);
}

/**
* convert_number -  converts numb
* @num: number
* @base:base
* @flagg: arg flag
* Return: str
*/
char *convert_number(long int num, int base, int flagg)
{
	static char *arr;
	static char buffer[50];
	char sig = 0;
	char *ptr;
	unsigned long m = num;

	if (!(flagg & CON_UNSIGNED) && num < 0)
	{
		m = -num;
		sig = '-';
	}
	arr = flagg & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = arr[m % base];
		m /= base;
	} while (m != 0);

	if (sig)
		*--ptr = sig;
	return (ptr);
}

/**
* remove_com - func to remove
* @buff: add
* Return: 0
*/
void remove_com(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
	}
}

