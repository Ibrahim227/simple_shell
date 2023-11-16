#include "shellteam.h"

/**
* scriptcpy - func
* @dest: dest
* @src: src
* Return: dest
*/
char *scriptcpy(char *dest, char *src)
{
	size_t i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);


	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
