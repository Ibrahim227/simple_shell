#include "main.h"

/**
* clear_infot - initialize alias_t
* @info: struct
* Return: nothing
*/
void clear_infot(alias_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
* set_infot - set ialias_t struct
* @info: struct
* @avv: arg vector
* Return: nothing
*/
void set_infot(alias_t *info, char **avv)
{
	int i = 0;

	info->fname = avv[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
* free_infot - free alias_t
* @info: struct
* @all: 1 if free
* Return: 0
*/
void free_infot(alias_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buff)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ) = NULL;
		bfree((void **)info->cmd_buff);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUFFER_FLUSH);
	}
}


