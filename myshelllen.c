#include "shellteam.h"

/**
* shell_len - gets len of str
* @scrp: str
* Return: count
*/
int shell_len(const char *scrp)
{
	int index, count_up = 0;

	for (index = 0; scrp[index]; index++)
		count_up++;

	return (count_up);
}

