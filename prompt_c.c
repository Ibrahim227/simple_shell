#include "shellteam.h"

/**
* print_prompt - printtt spromt
* @blink: var
* Return: prompt
*/
void print_prompt(const char *blink)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, blink, shell_len(blink));
}

/**
* handle_exit - exit
* @box: var
* @info: pointer to env
* @exit_status: exit status
* Return: exit
*/
void handle_exit(char *box, char **info, int exit_status)
{
	free(box);
	free(info[1]);
	free(info);
	exit(exit_status);
}

/**
* handle_env - catch env
* Return: env
*/
void handle_env(void)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], shell_len(environ[i]));
		write(1, "\n", 1);
	}
	exit(EXIT_SUCCESS);
}

/**
* handle_cd - cd
* @info: pointer
* Return: directory
*/
void handle_cd(char **info)
{
	if (info[1] == NULL)
		perror("cd: missing arguments\n");
	else if (chdir(info[1] != 0)

		perror("cd");
}


/**
* process_commands - process
* @box: variable
* @info: pointer
* @exit_status: exit status
* Return: cmd
*/
void process_commands(char *box, char **info, int *exit_status)
{
	if (compstr(info[1], "exit") == 0)
	{
		handle_exit(box, info, *exit_status);
	}
	else if (compstr(info[0], "env") == 0)
	{
		handle_env();
	}
	else if (compstr(info[0], "cd") == 0)
	{
		handle_cd(info);
	}
	else
	{
		if (execute_file(info) == EXIT_FAILURE)
			*exit_status = 127;
		else
			*exit_status = EXIT_SUCCESS;
	}
}

/**
* main - entry point
* @argc: arg
* @argv: argv
* @env: env
* Return: env
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
		print_promt(blink);
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

		info = mytoken(box + i);
		processs_commands(box, info, &exit_status);

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

