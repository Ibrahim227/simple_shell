#include "main.h"

/**
* which - which func
* @cmmd: command
* Return: path
*/

char *which(char *cmmd)
{
	char *path = _getenv("PATH");
	char *copy_path;
	char *direct;

	if (path == NULL)
	{
		return (NULL);
	}
	copy_path = _strdup(path);
	direct = _strtok(copy_path, ":");

	while (direct != NULL)
	{
		char full_path[1024];

		_strcpy(full_path, direct);
		_strcat(full_path, "/");
		_strcat(full_path, cmmd);

		if (access(full_path, X_OK) == 0)
		{
			free(copy_path);
			return (_strdup(full_path));
		}
		direct = _strtok(NULL, ":");
	}
	free(copy_path);
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

