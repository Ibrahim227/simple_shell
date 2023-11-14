#include "main.h"

/**
* _strtok - strtok imp
* @str: str
* @delim: delimeter
* Return: token
*/
char *_strtok(char *str, char const *delim)
{
	static char *ptr;
	int size = 0;
	char *token;
	int i = 0;

	if (str != NULL)
		ptr = str;
	while (ptr[i] != '\0')
		if (ptr[i] == *delim)
		{
			ptr[i] = '\0';
			token = ptr;
			ptr = &ptr[i + 1];
			return (token);
		}
		else
			i++;
	if (ptr[0] != '\0')
	{
		while (ptr[size] != 0)
			size++;
		token = ptr;
		ptr += size;
		return (token);
	}
	return (NULL);
}

