#include "main.h"

/**
 * is_cmd - determines cmd
 * @info: info struct
 * @path: path
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(alias_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates char
 * @pathstr:  PATH str
 * @start: start index
 * @stop: stop index
 *
 * Return: pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buff[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buff[k++] = pathstr[i];
	buff[k] = 0;
	return (buff);
}

/**
 * find_path - find PATH
 * @info: info struct
 * @pathstr: PATH str
 * @cmd: cmd to find
 *
 * Return: full path of cmd
 */
char *find_path(alias_t *info, char *pathstr, char *cmd)
{
	int i = 0, actual_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && start_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, actual_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			actual_pos = i;
		}
		i++;
	}
	return (NULL);
}


