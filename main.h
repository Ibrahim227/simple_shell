#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/*Handle Macros*/
#define READ_BUFFER_SIZE 4096
#define WRITE_BUFFER_SIZE 2048
#define BUFF_FLUSH -1


extern char **environ;


/**
* struct nodelist - silngle list
* @num: the num to field
* @str: a str
* @next: points
*/
typedef struct nodelist
{
	int num;
	char *str;
	struct nodelist *next;
} node_t;

/**
* struct information - contains args
* @arg: a str
* @argv: an arrray
* @path: path
* @argc: the arg count
* @line_count: line count
* @line_count_flag: line count flag
* @fname: file name
* @env: env
* @err_num: eror number
* @environ: custom env
* @history: hist
* @alias: alias
* @env_changed: changd env
* @status: status
* @cmd_buff: add pointer
* @cmd_buff_type: cmd type
* @readfd: the fd
* @histcount: count hist num
*/
typedef struct information
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int line_count_flag;
	char *fname;
	node_t *env;
	node_t *history;
	node_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buff;
	int cmd_buff_type;
	int readfd;
	int histcount;
} alias_t;

/**
* struct builtlegacy - contains builtin
* @type: the legacy cmd
* @func: the function
*/
typedef struct builtlegacy
{
	char *type;
	int (*func)(alias_t *);
} builtin_legacy;


/*Prototype */
int interactive(alias_t *info);
int is_delim(char s, char *delim);
int _isalpha(int s);
int _atoi(char *c);

int _myenv(alias_t *info);
char *_getenv(alias_t *info, const char *name);
int _mysetenv(alias_t *info);
int _myunsetenv(alias_t *info);
int pop_env_list(alias_t *info);

int _myexit(alias_t *info);
int _mycd(alias_t *info);
int _myhelp(alias_t *info);

int _myhistory(alias_t *info);
int unset_alias(alias_t *info, char *str);
int set_alias(alias_t *info, char *str);
int print_alias(node_t *node);
int _myalias(alias_t *info);
#endif /*MAIN_H*/
