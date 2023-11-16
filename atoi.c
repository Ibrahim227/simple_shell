#include "shellteam.h"

/**
* _atoi - convert str to int
* @c: the str
* Return:int
*/
int _atoi(char *c)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*c == '-')
			sign *= -1;
		else if (*c >= '0' && *c <= '9')
			num = (num * 10) + (*c - '0');
		else if (num > 0)
			break;

	} while (*c++);

	return (num * sign);
}

