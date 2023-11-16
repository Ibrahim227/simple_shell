#include "shellteam.h"

/**
* _strtok - a custom func
* @str: str
* @delim: delimiter
* Return: pointer
*/
char *_strtok(char *str, char *delim)
{
	static char *cutt;
	int idx;
	char *tok;

	if (str != NULL)
		cutt = strdup(str);

	if (cutt == NULL || *cutt == '\0')
		return (NULL);

	idx = strcspn(cutt, delim);

	tok = cutt;
	cutt += idx;

	if (*cutt != '\0')
	{
		*cutt = '\0';
		cutt++;
	}
	else
		cutt = NULL;

	return (tok);
}

