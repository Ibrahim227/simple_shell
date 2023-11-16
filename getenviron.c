#include "shellteam.h"

/**
* _getenv - gets the env
* @name: name of the env
* Return: ppointer to env
*/
char *_getenv(char *name)
{
	char *tok_flag;
	int i;
	char **ptr = environ;

	for (i = 0; ptr[i] != NULL; i++)
	{
		tok_flag = strtok(ptr[i], "=");
		while (tok_flag)
		{
			if (compstr(tok_flag, name) == 0)
			{
				return (ptr[i] + shell_len(name) + 1);
			}
			tok_flag = strtok(NULL, "=");
		}
	}
	return (NULL);
}

