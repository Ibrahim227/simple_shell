#include "main.h"

/**
* add_env_v - Add a new env
* @head: A pointer to the head
* @name: env name
* @value: env value
* Return: 0
*/
void add_env_v(struct Node **head, const char *name, const char *value)
{
	size_t name1 = _strlen(name);
	size_t value_le = _strlen(value);
	char *new_env_v = malloc(name1 + value_le + 2);
	struct Node *curent = *head;

	if (new_env_v == NULL)
	{
		return;
	}

	_memcpy(new_env_v, (void *)name, name1);
	new_env_v[name1] = '=';
	_memcpy(new_env_v + name1 + 1, (void *)value, value_le);
	new_env_v[name1 + value_le + 1] = '\0';

	while  (curent != NULL)
	{
		if (_strncmp(curent->str, name, name1) == 0 && curent->str[name1] == '=')
		{
			free(curent->str);
			curent->str = new_env_v;
			return;
		}
		curent = curent->next;
	}

	last_node(head, start_node(new_env_v));
}

/**
* update_env - update environ
* @head: the head of the ll
* Return: 0
*/
void update_env(struct Node *head)
{
	size_t cnt = 0;
	size_t i;
	struct Node *curent = head;
	char **new_env;

	while (curent != NULL)
	{
		cnt++;
		curent = curent->next;
	}

	new_env = malloc((cnt + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		return;
	}

	curent = head;
	for (i = 0; i < cnt; i++)
	{
		new_env[i] = curent->str;
		curent = curent->next;
	}
	new_env[cnt] = NULL;

	environ = new_env;
}

