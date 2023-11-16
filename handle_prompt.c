#include "shellteam.h"

/**
* main - entry poin
* @argc: arg
* @argv: arg
* @env: env
* Return: 0
*/
int main(int argc, char **argv, char **env)
{
	char *blink = "$", *box = NULL, **info = NULL;
	size_t shellSize = 0;
	ssize_t readBytes;
	unsigned long int i, exit_status = EXIT_SUCCESS;
	(void) argc, (void) argv, (void) env;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, blink, shell_len(blink));
		readBytes = getline(&box, &shellSize, stdin);
		if (readBytes == -1)
		{
			free(box);
			write(0, "\n", 1);
			exit(exit_status);
		}
		i = 0;
		while (i < shell_len(box) && box[i] != '\0' && (box[i] == ' '))
		{
			i++;
			continue;
		}
		if (*(box + i) == '\n')
		{
			continue;
		}
		info = mytoken(box + i);
		if (compstr(info[0], "exit") == 0)
		{
			free(box);
			free(info[0]);
			free(info);
			exit(exit_status);
		}
		else if (compstr(info[0], "env") == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
			{
				write(1, environ[i], shell_len(environ[i]));
				write(1, "\n", 1);
			}
			exit(EXIT_SUCCESS);
		}
		else if (compstr(info[0], "cd") == 0)
		{
			if (info[1] == NULL)
				perror("cd: missing argument\n");
			else if (chdir(info[1]) != 0)
			{
				perror("cd");
			}
		}
		else if (compstr(info[0], "setenv") == 0)
		{
			if (info[0] != NULL && info[2] != NULL)
			{
				if (setenv(info[1], info[2], 1) != 0)
				{
					perror("setenv");
				}
			}
			else
			{
				fprintf(stderr, "Usage: setenv VARIABLE VAlUE\n");
			}
		}
		else if (compstr(info[0], "unsetenv") == 0)
		{
			if (info[1] != NULL)
			{
				if (unsetenv(info[1]) != 0)
				{
					perror("unsetenv");
				}
			}
			else
			{
				fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			}
		}
		else
		{
			if (execute_file(info) == EXIT_FAILURE)
				exit_status = 127;
			else
				exit_status = EXIT_SUCCESS;
		}


		for (i = 0; info[i] != NULL; i++)
			free(info[i]);
		free(info);
	}
	for (i = 0; info[i] != NULL; i++)
		free(info[i]);
	free(box);
	free(info);

	return (0);
}
