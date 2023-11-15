#include "main.h"

/**
* _myexit - exits the shell
* @info: struct
* Return: 0
*/
int _myexit(alias_t *info)
{
	int exitver;

	if (info->argv[1])
	{
		exitver = _erratoi(info->argv[1]);
		if (exitver == -1)
		{
			info->status = 2;
			print_error(info, "Illegal Number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
* _mycd - hanges cwd
* @info: struct
* Return: 0
*/
int _mycd(alias_t *info)
{
	char *c, *dir, bufer[1024];
	int chdir_r;

	c = getcwd(buffer, 1024);
	if (!c)
		_puts("TODO: >>Ggetcwd failure emsghere<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_r = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_r = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(c);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_r = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_r = chdir(info->argv[1];

	if (chdir_r == -1)
	{
		print_error(info, "cant cd to ");
		_eputs(info->arv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(bufer, 1024));
	}
	return (0);
}

/**
* _myhelp - chage the cwd
* @info: struct
* Return: 0
*/
int _myhelp(alias_t *info)
{
	char **arg_arrr;

	arg_arr = info->argv;
	_puts("help call works. function not imple;ented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}

