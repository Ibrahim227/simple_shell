#include "main.h"
#include <string.h>

void avoid_segfault(int signumber __attribute__((unused)));

int out_code = 0;

/**
* main - Main entry point
* @ac: the num of cmd
* @av: an arrayof cmd-line
* Return: command
*/
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *__attribute__((unused)) cmdl, *copy_cmd = NULL;
	char *argv[MAX_ARGS], *ar[MAX_ARGS];

	int __attribute__((unused)) argnum, r, cnt = 0;
	signal(SIGSEGV, avoid_segfault);
	do {
		cnt++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		cmd = read_cmd();
		if (cmd == NULL)
			exit(out_code);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;
		remspace(cmd);
		copy_cmd = strdup(cmd);
		token_flag(copy_cmd, ar);
		token_flag(cmd, argv);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			free(cmd);
			free(copy_cmd);
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			r = _lexit(ar[1], cnt, av[0], argv);
			free(cmd);
			free(copy_cmd);
			if (r == 500)
				continue;
			exit(r);
		}
		if (process_cmd(argv) == 0)
		{
		}
		else
			_exec(argv, av[0], cnt);
		free(cmd);
		free(copy_cmd);
	} while (1);
	return (0);
}

/**
* wspace - check space
* @c: char to check
* Return: 1 on success, 0 otherwixe
*/
int wspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);

	return (0);
}

/**
* remspace - remove white space
* @c: str to check
* Return: void
*/
void remspace(char *c)
{
	int len = _strlen(c);
	int i = 0, j = len - 1, k;
	int l, cnt, m;

	if (c == NULL)
		return;

	while (i < len && wspace(c[i]))
	{
		i++;
	}
	while (j >= i && wspace(c[j]))
	{
		j--;
	}
	k = 0;
	while (i <= j)
	{
		c[k++] = c[i++];
	}
	c[k] = '\0';
	l = 0;
	cnt = 0;
	for (m = 0; m <= j; m++)
	{
		if (c[m] != ' ')
		{
			c[l++] = c[m];
			cnt = 0;
		}
		else if (cnt == 0)
		{
			c[l++] = c[m];
			cnt++;
		}
	}
	c[l] = '\0';
}

/**
* read_cmd - read input from user
*
* Return: pointer
*/
char *read_cmd(void)
{
	char *cmdl = _getline();

	signal(SIGINT, hand_sigint);
	return (cmdl);
}

/**
* hand_sigint - signal handler
* @signumber: signal number
* Return: void
*/
void hand_sigint(int signumber __attribute__((unused)))
{
	write(1, "\n", 1);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	exit(0);
}

