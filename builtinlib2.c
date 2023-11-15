#include "main.h"

/**
* _myhistory - displays history
* @info: struct
* Return: 0
*/
int _myhistory(alias_t *info)
{
	print_list(info->history);
	return (0);
}

/**
* unset_alias - set alias to str
* @info: struct
* @str: str
* Return: 0
*/
int unset_alias(alias_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
* set_alias - set alias
* @info: struct
* @str: str
* Return: 0
*/
int set_alias(alias_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints alias
* @node: node
* Return: 0
*/
int print_alias(alias_t *node)
{
	char *p = NULL, *c = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (c = node->str; c <= p; c++)
			_putchar(*c);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
* _myalias - my alias
* @info: struct
* Return: 0
*/
int _myalias(alias_t *info)
{
	int i = 0;
	char *p = NULL;
	node_T *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->argv[i], '='));
	}

	return (0);
}


