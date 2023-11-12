#include "main.h"

/**
* print_list - print content
* @head: head of ll
* Return: output
*/
void print_list(struct Node *head)
}
	while (head != NULL)
	{
		write(STDOUT_FILENO, head->str,  _strlen(head->str));
		write(STDOUT_FILENO, "\n", 1);
		head = head->next;
	}
}

/**
* free_list - Free up mem
* @head: head of ll
* Return: 0
*/
void free_list(struct Node *head)
{{
	struct Node *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
* _env - print env variable
* Return: Always 0
*/
int _env(void)
{
	char **env;
	struct Node *head = NULL;

	for (env = environ; *env != NULL; env++)
	{
		end_node(&head, beg_node(*env));
	}

	print_list(head);
	free_list(head);
	return (0);
}

/**
* _setenv - set an env
* @name: env name
* @value: env value
* Return: 0
*/
int _setenv(const char *name, const char *value)
{
	char **env;
	struct Node *head = NULL;

	for (env = environ; *env != NULL; env++)
	{
		end_node(&head, beg_node(*env));
	}

	add_env(&head, name, value);

	update_env(head);
	return (0);
}

/**
* _unsetenv - delete env variable
* @name: env name
* Return: 0
*/
int _unsetenv(const char *name)
{
	char **ee;
	char **env;
	size_t length = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, length) == 0 && (*env)[len] == '=')
		{
			for (e = env; *ee != NULL; ee++)
			{
				*ee = *(ee + 1);
			}
			return (0);
		}
	}

	return (-1);
}

