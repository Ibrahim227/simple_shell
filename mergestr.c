#include "shellteam.h"

/**
* merge_str - ocnc 2 str
* @dest: destination
* @src: source
* Return: dest
*/
char *merge_str(char *dest, char *src)
{
	int i = 0, j = 0, dest_len = 0, src_len = 0;
	char *temp;

	while (dest[i++])
		dest_len++;

	while (src[j++])
		src_len++;

	temp = malloc(dest_len + src_len + 1);

	if (temp == NULL)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}

	scriptcpy(temp, dest);
	strcat(temp, src);

	for (i = 0; i < src_len; i++)
		temp[dest_len++] = src[i];

	temp[dest_len++] = '\0';

	dest = temp;

	return (dest);
}
