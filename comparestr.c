#include "shellteam.h"

/**
* compstr - compares 2 str
* @s1: str1
* @s2: str2
* Return: 0
*/
int compstr(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}

