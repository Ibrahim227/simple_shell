#include "shellteam.h"

/**
* my_setenv - se an env
* @variable: env variable
* @value: env value
* @overwrite: write to
* Return: env
*/
int my_setenv(const char *variable, const char *value, int overwrite)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "Error: setenv requires non-null arg\n");
		return (-1);
	}

	if (overwrite || getenv(variable) == NULL)
	{
		if (setenv(variable, value, 1) != 0)
		{
			fprintf(stderr, "Error: unable to set env\n");
			return (-1);
		}
	}

	return (0);
}

/**
* my_unsetenv - unset an env
* @variable: env variable
* Return: unset
*/
int my_unsetenv(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "Error unset requires a non-null arg\n");
		return (-1);
	}

	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Error: Unablbe to unset env variable\n");
		return (-1);
	}

	return (0);
}

