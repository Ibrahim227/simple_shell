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

/**
* func_test - test man
* @argc: arg var
* @argv: arg var
* Return: env
*/
int func_test(int argc, char **argv)
{
	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s setenv, VARIABLE VALUE\n", argv[0]);
		fprintf(stderr, "	%s unsetenv VARIABLE \n", argv[0]);
		return (1);
	}

	if (strcmp(argv[1], "setenv") == 0)
	{
		return (my_seten(argv[2], arg[3], 1));
	}
	else if (strcmp(argv[1], "unsetenv") == 0)
	{
		return (my_unsetenv(argv[2]));
	}
	else
	{
		fprintf(stderr, "Error: Invalid cmd\n");
		return (-1);
	}
	return (0);
}

