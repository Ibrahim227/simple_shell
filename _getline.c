#include "main.h"

/**
* _getline - read the input
*
* Return: Input
*/
char *_getline(void)
{
	int i = 0;
	ssize_t rread;
	char c = 0, *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		return (NULL);
	}
	while (c != EOF && c != '\n')
	{
		rread = read(STDIN_FILENO, &c, 1);
		if (rread == 0 || rread == -1)
		{
			free(buffer);
			if (rread == 0)
				exit(out_code);
			if (rread == -1)
				perror("Error: ");
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (i + 1 >= BUFFER_SIZE)
		{
			buffer = _realloc(buffer, i + 1);
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		i++;
	}
	buffer[i - 1] = '\0';
	remspace(buffer);
	hash_handler(buffer);
	return (buffer);
}

/**
* hash_handler - handle has character
* @buff: input bufer
* Return: 0
*/
void hash_handler(char *buff)
{
	int j = 0;

	while (buff[j] != '\0')
	{
		if (buff[j] == '#')
			buff[j] = '\0';
		j++;
	}
}

