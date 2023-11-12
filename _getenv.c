#include "main.h"

/**
* _getenv - getenv()
* @str: str
* Return: path
*/
char *_getenv(char *str)
{
	int i = 0;
	int length = _strlen(str);

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], str, length) == 0 && environ[i][length] == '=')
		{
			return (&(environ[i][length + 1]));
		}
		i++;
	}
	return (NULL);
}

