#include "shellteam.c"

/**
* main_env - main
* Return: env
*/
int main_env(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}

	return (0);
}

