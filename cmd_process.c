#include "main.h"

/**
* process_cmd - execute the command
* @argv: array of str
* Return: 0 on sucess 1 otherwise
*/
int process_cmd(char **argv)
{
	int argnumb = argnum(argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (argnumb >= 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}
	if (_strcmp(argv[0], "setenv") == 0)
	{
		if (argnumb == 3)
		{
			_setenv(argv[1]m argv[2]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argnumb == 2)
		{
			_unsetenv(arg[1]);
			return (0);
		}
	}

	return (1);
}

/**
* _perrore - address error
* @err: error
* @cnt: num count
* @s: nameof cmd
* @argum: cmd arg
*/
void _perrore(char *err, int cnt, char *s, char *argum)
{
	_print(err);
	_print(": ");
	_pnumber(cnt);
	_print(": ");
	_print(s);
	_print(": Wrong umber: ");
	_print(argum);
	_print("\n");
}

