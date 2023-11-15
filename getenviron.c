#include "main.h"

/**
* get_environ - retrurn str
* @info: structure
* Return: 0
*/
char **get_environ(alias_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_str(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
* _unsetenv - remove an env
* @info: struc
* @va: str env var
* Return: on delete 0 otherwise
*/
int _unsetenv(alias_t *info, char *va)
{
	node_t *node = info->env;
	size_t i = 0;
	char *pp;

	if (!node || !va)
		return (0);

	while (node)
	{
		pp = start_with(node->str, va);
		if (pp && *pp == '=')
		{
			info->env_changed = delete_node_at(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}
/**
* _setenv - initialize env
* @info: structure
* @va: str ev var
* @value: env var
* Return: 0
*/
int _setenv(alias_t *info, char *va, char *value)
{
	char *buf = NULL;
	node_t *node;
	char *pp;

	if (!va || !value)
		return (0);

	buf = malloc(_strlen(va) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, va);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		pp = start_with(node->str, va);
		if (pp && *pp == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed;
	return (0);
}
