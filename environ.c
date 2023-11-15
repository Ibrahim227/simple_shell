#include "main.h"

/**
* _myenv - prints the current env
* @info: struct
* Return: 0
*/
int _myenv(alias_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
* _getenv - gets value env
* @info: struct
* @name: stenv name:
* Return: value
*/
char *_getenv(alias_t *info, const char *name)
{
	node_t *node = info->env;
	char *p;

	while (node)
	{
		p = start_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
* _mysetenv - Initialize e new env
* @info: struct
* Return: 0
*/
int _mysetenv(alias_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
* _myunsetenv - remove an env
* @info: struct
* Return: 0
*/
int _myunsetenv(alias_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arg\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[1]);

	return (0);
}

/**
* pop_env_list - pop env list
* @info: struct
* Return: 0
*/
int pop_env_list(alias_t *info)
{
	node_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

