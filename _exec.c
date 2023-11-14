#include "main.h"

/**
* _exec - execute cmd
* @_argnum: array of arg
* @vv: name of prog
* @cnt: count of cmd
* Return: 0
*/
void _exec(char **_argnum, char *vv, int cnt)
{
	char *cmdl;
	char err[50];
	int status;

	_strcpy(err, vv);
	out_code = 0;
	if (_argnum[0][0] == '/')
	{
		if (ver_access(_argnum, NULL, err, cnt, environ))
			return;
	}
	else
	{
		if (_argnum[0][0] != '.')
		{
			cmdl = which(_argnum[0]);
			if (cmdl == NULL)
			{
				_perror(err, cnt, _argnum[0]);
				return;
			}
			if (ver_access(_argnum, cmdl, err, cnt, environ))
				return;
			free(cmdl);
		}
		else
		{
			cmdl = _argnum[0];
			if (ver_access(_argnum, cmdl, err, cnt, environ))
				return;
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		out_code = (WEXITSTATUS(status));
	}
}

/**
* _execve - runs error code
* @cm: cmd prompt
* @parg: arg to cmd
* @rev: env variable
* Return: 0
*/
void _execve(char *cm, char **parg, char **rev)
{
	if ((execve(cm, parg, rev) == -1))
		out_code = 127;
	out_code = 1;
}

/**
* _perror - print error
* @err: error str
* @cnt: num of cmd
* @cname: name of file
* Return: 0
*/
void _perror(char *err, int cnt, char *cname)
{
	out_code = 127;
	_print(err);
	_print(": ");
	_pnumber(cnt);
	_print(": ");
	_print(cname);
	_print(": not found\n");
}

/**
* _print - prints a char
* @z: str input
* Return: str
*/
void _print(char *z)
{
	int i = 0;

	while (z[i] != '\0')
	{
		_putchar(z[i]);
		i++;
	}
}

/**
* _pnumber - print num
* @m: int
* Return: int
*/
void _pnumber(int m)
{
	int ini = m, cnt = 0, x = 1, i, tmp;

	tmp = m;

	if (m < 0)
	{
		_putchar('-');
		m = (m * -1) - 1;
	}
	while (ini != 0)
	{
		ini = ini / 10;
		cnt++;
	}
	while (x <= cnt)
	{
		ini = m;
		i = x;
		while (i < cnt)
		{
			ini = ini / 10;
			i++;
		}
		if (tmp < 0 && x == cnt)
			_putchar(((ini % 10) + 48) + 1);
		else
			_putchar((ini % 10) + 48);
		x++;
	}
	if (cnt == 0)
		_putchar('0');
}
