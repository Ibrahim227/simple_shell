#include "shellteam.h"

/**
* mytoken - creates
* @scrp: str
* Return:pointer
*/
char **mytoken(char *scrp)
{
	char *token;
	char *mySpace = "\n ";
	int index, count = 10;
	char **strings = NULL;

	strings = malloc(sizeof(char *) * (count + 1));

	if (strings == NULL)
	{
		free(strings);
		exit(EXIT_FAILURE); /* check malloc failure */
	}
	token = strtok(scrp, mySpace);
	index = 0;
	while (token)
	{
		strings[index] = strdup(token);
		token = strtok(NULL, mySpace);
		index++;
	}
	strings[index] = NULL;
	/* print av to standard output */
	return (strings);
}
