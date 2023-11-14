#include "main.h"

/**
* rem_tl_space - remove trailing space
* @str: str
* Return: 0
*/
void rem_tl_space(char *str)
{
	size_t length = _strlen(str);
	size_t start = 0;
	size_t i;

	if (length > 0)
	{
		while (length > 0 && str(length - 1) == ' ')
			length--;
		str[length] = '\0';
	}

	while (str[start] == ' ')
		start++;

	if (start > 0)
	{
		i = 0;
		while (str[start + i] != '\0')
		{
			str[i] = str[start + i];
			i++;
		}
		str[i] = '\0';
	}
}

/**
* token_flag - token
* @command: str
* @argv: atrray
* Return: 0
*/
void token_flag(char *command, char *argv[MAX_ARGS])
{
	char *token;
	int j = 0;

	token = _strtok(command, " ");
	while (token != NULL)
	{
		argv[j++] = token;
		token = _strtok(NULL, " ");
	}
	argv[j] = NULL;
}

/**
* argnums - countnumber
* @argv: array
* Return: number of arg
*/
int argnums(char *argv[])
{
	int i  = 0;

	while (argv[i] != NULL)
		i++;
	return (i);
}

/**
* _atoi - convert str to int
* @str: str to convert
* Return: int value
*/
int _atoi(const char *str)
{
	int i, n = 0;
	int sig = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sig = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		else
			break;
	}

	return (n * sig);
}

/**
* _lexit - exit
* @status: status code
* @cnt: count cmd
* @s: name
* @asg: str
* Return: exit code
*/
int _lexit(char *status __attribute__((unused)), int cnt, char *s, char **asg)
{
	int i = out_code;
	int j;

	if (status != NULL)
	{
		j = 0;
		while (status[j])
		{
			if (!(status[j] > 47 && status[j] < 58))
			{
				_perrore(s, cnt, asg[0], asg[1]);
				out_code = 2;
				return (500);
			}
			j++;
		}
		i = _atoi(status);
	}
	return (i);
}

