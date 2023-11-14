#include "main.h"

/**
* which - which func
* @command: command
* Return: path
*/

char *which(char *command)
{
	char *path = _getenv("PATH");
	char *cp_path;
	char *dir;

	if (path == NULL)
	{
		return (NULL);
	}
	cp_path = _strdup(path);
	dir = _strtok(cp_path, ":");

	while (dir != NULL)
	{
		char full_path[1024];

		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(cp_path);
			return (_strdup(full_path));
		}
		dir = _strtok(NULL, ":");
	}
	free(cp_path);
	return (NULL);
}

/**
* print_all_original - print
* @origin: origin
* Return: origin
*/
void print_all_original(original_t *origin)
{
	original_t *org;

	for (org = origin; org; org = org->next)
		print_original(org);
}

