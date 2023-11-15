#include "main.h"

/**
 * main - entry
 * @ac: arg c
 * @av: arg v
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	alias_t info[] = { ENTRY_INITIALYZER };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	pop_env_list(info);
	read_hist(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

