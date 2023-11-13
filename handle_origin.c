#include "main.h"

/**
* init_origin - initialize alias
* @origin: head of ll
* Return: alias
*/
void init_origin(original_t **origin)
{
	set_origin(origin, "l", "ls -CF");
	set_origin(origin, "la", "ls -A");
	set_origin(origin, "ll", "ls -alF");
	set_origin(origin, "ls", "ls --color=auto");
}

/**
* origin_command - origin cmd
* @argv: arg
* @argnum: number of arg
*
* Return: 0
*/
int origin_command(char *argv[MAX_ARGS], int argnum __attribute__((unused)))
{
	static original_t *origin;
	static int initial;
	int i;
	char *name, *value;
	original_t *org;

	if (!initial)
	{
		init_origin(*origin);
		initial = 1;
	}

	if (_strcmp(argv[0], "org") != 0)
		return (0);

	if (argnum == 1)
	{
		for (org = origin; org; org->next)
			print_origin(org);
		return (1);
	}
	for (i = 1; i < argnum; i++)
	{
		name = argv[i];
		value = _strchr(argv[i], '=');
		if (value)
		{
			*value = '\0';
			value++;
			if (*value == '\0')
				continue;
			set_origin(*origin, name, value);
		}
		else
		{
			print_all_origin(origin);
		}
	}
	return (1);
}

/**
* set_origin - set an origin
* @origin: head of ll
* @name: name of origin
* @value: value of origin
* Return: 0
*/
void set_origin(original_t **origin, char *name, char *value)
{
	original_t *org;

	for (org = *origin; org = org->next)
		if (_strcmp(org->name, name) == 0)
			break;
	if (org)
	{
		free(org->value);
		org->value = _strdup(value);
	}
	else
	{
		org = malloc(sizeof(*org));
		if (!org)
			return;
		org->name = _strdup(name);
		org->value = _strdup(value);
		org->next = *origin;
		*origin = org;
	}
	free(org);
}

/**
* print_origin - prints an origin
* @org: the origin to print
* Return: 0
*/
void print_origin(original_t *org)
{
	if (org->value[0] != '\'')
	{
		write(1, "org ", 6);
		write(1, org->name, _strlen(org->name));
		write(1, "='", 2);
		write(1, org->value, _strlen(org->value));
		write(1, "'\n", 2);
	}
	else
	{
		write(1, "org ", 6);
		write(1, org->name, _strlen(org->name));
		write(1, "=", 1);
		write(1, org->value, _strlen(org->value));
		write(1, "\n", 1);
	}
}

