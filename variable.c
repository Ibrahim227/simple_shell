#include "main.h"

/**
 * is_chain - test current char
 * @info: parameter struct
 * @buff: the char buffer
 * @ptr: address
 * Return: 1 if chain, 0 otherwise
 */
int is_chain(alias_t *info, char *buff, size_t *ptr)
{
	size_t j = *ptr;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		info->cmd_buff_type = COMMAND_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;
		j++;
		info->cmd_buff_type = COMMAND_AND;
	}
	else if (buff[j] == ';') /* found end of this command */
	{
		buff[j] = 0; /* replace semicolon with null */
		info->cmd_buff_type = COMMAND_CHAIN;
	}
	else
		return (0);
	*ptr = j;
	return (1);
}


/**
 * ver_chain - checks chain
 * @info: parameter struct
 * @buff: char buffer
 * @ptr: pointer
 * @i: start pos
 * @len: length of buff
 *
 * Return: Void
 */
void ver_chain(alias_t *info, char *buff, size_t *ptr, size_t i, size_t len)
{
	size_t j = *ptr;

	if (info->cmd_buff_type == COMMAND_AND)
	{
		if (info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buff_type == COMMAND_OR)
	{
		if (!info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}

	*ptr = j;
}

/**
 * replace_alias - replaces an alias
 * @info: parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(alias_t *info)
{
	int i;
	node_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_start_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces var
 * @info: parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(alias_t *info)
{
	int i = 0;
	node_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_str(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_str(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_start_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_str(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_str(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_str - replaces string
 * @old_str: old string
 * @new_str: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_str(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}

