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
		return (script_dup(strings));

	dupFilePath = script_dup(filepath);
	token = strtok(dupFilePath, delim);
	while (token)
	{
		total_len = shell_length(token) + shell_length(strings) + 2;
		mypath = malloc(total_len);
		if (mypath == NULL)
			break;
		else if (mypath != NULL)
		{
			scriptcpy(mypath, token);
			str_merge(mypath, "/");
			str_merge(mypath, strings);

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
