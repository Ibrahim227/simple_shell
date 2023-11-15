#include "main.h"

/**
* interactive - returns true
* @info: struct address
* Return: 1 if interactive 0 otherwise
*/
int interactive(alias_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - checks char delos
* @s: char to check
* @delim: delimiter
* Return: 1if true 0 otherwise
*/
int is_delim(char s, char *delim)
{
	while (*delim)
		if (*delim++ == s)
			return (1);
	return (0);
}

/**
* _isalpha - convert alphabet
* @s: ctr
* Return: converted str
*/
int _isalpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

/**
* _atoi - converts a str to int
* @c: str to convert
* Return: 0 if num is str
*/
int _atoi(char *c)
{
	int i, sig = 1, flag = 0, output;
	unsigned int res = 0;

	for (i = 0; c[i] != '\0' && flag != 2; i++)
	{
		if (c[i] == '-')
		sig *= -1;

		if (c[i] >= '0' && c[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (c[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sig == -1)
		output = -res;
	else
		output = res;

	return (output);
}

