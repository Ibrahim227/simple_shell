#include "shellteam.h"

/**
* _exit - exit prog
* @argc: arg
* @argv: argv
* Return: exit
*/
int _exit(int argc, char *argv[])
{
	int exit_status = 0;

	if (argc > 1)
	{
		exit_status = atoi(argv[1]);

		if (exit_status == 0 && argv[1][0] != '0')
		{
			fprintf(stderr, "Invalid exit status: %s\n", argv[1]);
		}
	}

	exit(exit_status);
}

