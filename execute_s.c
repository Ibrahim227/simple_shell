#include "shellteam.c"

/**
* execute_file - executes file
* @cmd: command
* Return: nothing on success
*/
int execute_file(char **cmd)
{
	pid_t processid;
	int i, status, execreturn;
	char *fullpath;

	fullpath = pathfinder(cmd[0]);
	if (fullpath == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", cmd[0]);
		return (EXIT_FAILURE);
	}
	processid = fork();

	if (processid == -1)
	{
		perror("Error creating process");
		exit(EXIT_FAILURE);
	}
	else if (processid == 0)
	{
		execreturn = execve(fullpath, cmd, environ);
		if (execreturn == -1)
		{
			perror("Failed to execute program");
			free(fullpath);
			for (i = 0; cmd[i] != NULL; i++)
				free(cmd[i]);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(fullpath);
	return (EXIT_SUCCESS);
}

