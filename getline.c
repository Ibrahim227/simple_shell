#include "main.h"

/**
* input_buffer - buffers
* @info: struct
* @buff: address buffer
* @length: addess length
* Return: byte
*/
ssize_t input_buffer(alias_t *info, char **buff, size_t *length)
{
	ssize_t r = 0;
	size_t len_ = 0;

	if (!*length)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigint_handler);
#if GRANT_GETLINE
		r = getline(buff, &len_, stdin);
#else
		r = _getline(info, buff, &len_);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0';
				r--;
			}
			info->line_count_flag = 1;
			remove_com(*buff);
			build_hist_list(info, *buff, info->histcount++);
			/* if (_strchr(*buff, ';')) */
			{
				*length = r;
				info->cmd_buff = buf;
			}
		}
	}
	return (r);
}

/**
* get_inputt - gets aline
* @info: struct
* Return: byte
*/
ssize_t get_inputt(alias_t *info)
{
	static char *buff;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buff_pp = &(info->arg), *p;

	_putchar(BUFFER_FLUSH);
	r = input_buffer(info, &buff, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buff + i;

		ver_chain(info, buff, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buff, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buff_type = COMMAND_NORMAL;

		}

		*buff_pp = p;
		return (_strlen(p));
	}

	*buff_pp = buff;
	return (r);
}

/**
* read_buffer - reads buffer
* @info: struc para
* @buff: buffer
* @sz: size
* Return: r
*/
ssize_t read_buffer(alias_t *info, char *buff, size_t *sz)
{
	ssize_t r = 0;

	if (*sz)
		return (0);
	r = read(info->readfd, buff, READ_BUFFER_SIZE);
	if (r >= 0)
		*sz = r;
	return (r);
}

/**
* _getline - get line
* @info: struct
* @ptr: pointer
* @len:  size
* Return: s
*/
int _getline(alias_t *info, char **ptr, size_t *len)
{
	static char buff[READ_BUFFER_SIZE];
	static size_t i, leng;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *n_p = NULL, *c;

	p = *ptr;
	if (p && len)
		s = *len;
	if (i == leng)
		i = leng = 0;

	r = read_buffer(info, buff, &leng);
	if (r == -1 || (r == 0 && leng == 0))
		return (1);

	c = _strchr(buff + i, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : leng;
	n_p = _realloc(p, s, s ? s + k : k + 1);
	if (!n_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(n_p, buff + i, k - i);
	else
		_strncpy(n_p, buff + i, k - i + 1);

	s += k - i;
	i = k;
	p = n_p;

	if (len)
		*len = s;
	*ptr = p;
	return (s);
}

/**
* sigint_handler - blocks
* @signum: signal num
* Return: void
*/
void sigint_handler(__attribute__((unused)) int signum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}

