#include "main.h"

/**
 **_memset - fill memory
 *@s: pointer to the mem
 *@ab: byte
 *@nn: bytes
 * Return: pointer
 */
char *_memset(char *s, char ab, unsigned int nn)
{
	unsigned int i;

	for (i = 0; i < nn; i++)
		s[i] = ab;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @ptr: string of strings
 */
void ffree(char **ptr)
{
	char **a = ptr;

	if (!ptr)
		return;
	while (*ptr)
		free(*ptr++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer
 * @old_sz: byte
 * @new_sz: byte size
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_sz, unsigned int new_sz)
{
	char *pp;

	if (!ptr)
		return (malloc(new_sz));
	if (!new_sz)
		return (free(ptr), NULL);
	if (new_sz == old_sz)
		return (ptr);

	pp = malloc(new_sz);
	if (!pp)
		return (NULL);

	old_sz = old_sz < new_sz ? old_sz : new_sz;
	while (old_sz--)
		pp[old_sz] = ((char *)ptr)[old_sz];
	free(ptr);
	return (pp);
}


