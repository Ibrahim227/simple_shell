#include "main.h"

/**
 * list_len - determines len
 * @hp: pointer
 *
 * Return: size of lis
 */
size_t list_len(const node_t *hp)
{
	size_t i = 0;

	while (hp)
	{
		hp = hp->next;
		i++;
	}
	return (i);
}

/**
 * list_to_str - returns an array
 * @head: pointer to first node
 *
 * Return: array of str
 */
char **list_to_str(node_t *head)
{
	node_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elem
 * @hp: pointer
 *
 * Return: size of list
 */
size_t print_list(const list_t *hp)
{
	size_t i = 0;

	while (hp)
	{
		_puts(convert_number(hp->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hp->str ? hp->str : "(nil)");
		_puts("\n");
		hp = hp->next;
		i++;
	}
	return (i);
}

/**
 * node_start_with - returns node
 * @node: pointer
 * @prefix: str
 * @c: the next char
 *
 * Return: match node or null
 */
node_t *node_start_with(node_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = start_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index
 * @head: pointer
 * @node: pointer
 *
 * Return: index
 */
ssize_t get_node_index(node_t *head, node_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

