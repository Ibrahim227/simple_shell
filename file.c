#include "main.h"

/**
* ver_access - check file access
* @arg: cmd arg
* @cmd: cmd arg
* @err: err str
* @cnt: count cmt
* @ev: env variable
* Return: 0
*/
int ver_access(char *arg, char *cmd, char *err, int cnt, char **ev)
{
	pid_t verid;
	char *p = NULL;

	p = (cmd == NULL) ? arg[0] : cmd;

	if (access(p, X_OK) == 0)
	{
		verid = fork();
		if (verid == 0)
		{
			_execve(p, arg, ev);
		}
		return (0);
	}
	else
	{
		_perror(err, cnt, p);
		return (1);
	}
}

/**
* _putchar - writes char
* @c: char to print
* Return: 1 on Succes
*/
int _putchar(char c)
{
	return (write(2, &c, 1));
}

