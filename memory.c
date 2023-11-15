#include "main.h"

/**
 * bfree - frees a pointer
 * @ptr: address ptr
 *
 * Return: 1 on success, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

