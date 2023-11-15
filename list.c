#include "main.h"

/**
 * add_node - adds a node
 * @head: address of pointer
 * @str: str field of node
 * @num: node index
 *
 * Return: size of list
 */
node_t *add_node(node_t **head, const char *str, int num)
{
	node_t *ne_head;

	if (!head)
		return (NULL);
	ne_head = malloc(sizeof(node_t));
	if (!ne_head)
		return (NULL);
	_memset((void *)ne_head, 0, sizeof(node_t));
	ne_head->num = num;
	if (str)
	{
		ne_head->str = _strdup(str);
		if (!ne_head->str)
		{
			free(ne_head);
			return (NULL);
		}
	}
	ne_head->next = *head;
	*head = ne_head;
	return (ne_head);
}

/**
 * add_node_end - adds a node
 * @head: address of pointer
 * @str: str field
 * @num: node index
 *
 * Return: size of list
 */
node_t *add_node_end(node_t **head, const char *str, int num)
{
	node_t *ne_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	ne_node = malloc(sizeof(node_t));
	if (!ne_node)
		return (NULL);
	_memset((void *)ne_node, 0, sizeof(node_t));
	ne_node->num = num;
	if (str)
	{
		ne_node->str = _strdup(str);
		if (!ne_node->str)
		{
			free(ne_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = ne_node;
	}
	else
		*head = ne_node;
	return (ne_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @hh: pointer
 *
 * Return: size
 */
size_t print_list_str(const node_t *hh)
{
	size_t i = 0;

	while (hh)
	{
		_puts(hh->str ? hh->str : "(nil)");
		_puts("\n");
		hh = hh->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at - deletes node
 * @head: address of pointer
 * @idx: index
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at(node_t **head, unsigned int idx)
{
	node_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!idx)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == idx)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes
 * @head_p: address of p
 *
 * Return: void
 */
void free_list(node_t **head_p)
{
	node_t *node, *next_node, *head;

	if (!head_p || !*head_p)
		return;
	head = *head_p;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_p = NULL;
}


