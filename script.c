#include "shellteam.c"

/**
* scrp_dup - returs a pointer
* @c: str
* Return: ocpy of str
*/
char *scrp_dup(char *c)
{
	int i, j, len = 0;
	char *ptr;

	if (c == NULL)
		return (NULL);

	for (i = 0; c[i]; i++)
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (j = 0; j < len; j++)
		ptr[j] = s[j];
	ptr[len] = '\0';

	return (ptr);
}

