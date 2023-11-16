#include "shellteam.h"

/**
* pathfinder - finds path
* @strings: cmd
* Return: pointer
*/
char *pathfinder(char *strings)
{
	char *filepath = _getenv("PATH"), *dupFilePath;
	char *token;
	size_t total_len = 0;
	struct stat cmd;
	char *mypath;
	char *delim = ":";

	if (strings == NULL)
	{
		perror("NULL input received");
		return (NULL);
	}
	if (stat(strings, &cmd) == 0)
		return (scrp_dup(strings));

	dupFilePath = scrp_dup(filepath);
	token = strtok(dupFilePath, delim);
	while (token)
	{
		total_len = shell_len(token) + shell_len(strings) + 2;
		mypath = malloc(total_len);
		if (mypath == NULL)
			break;
		else if (mypath != NULL)
		{
			scriptcpy(mypath, token);
			merge_str(mypath, "/");
			merge_str(mypath, strings);

			if (stat(mypath, &cmd) == 0)
			{
				free(dupFilePath);
				return (mypath);
			}
		}
		free(mypath);
		token = strtok(NULL, delim);
	}
	free(dupFilePath);
	return (NULL);
}
