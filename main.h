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
#define WRITE_BUFFER_SIZE 4096
#define BUFFER_FLUSH -1

#define LOWERCASE 1
#define CON_UNSIGNED 2

#define GRANT_GETLINE 0
#define GRANT_STRTOK 0

#define GRANT_HIST_FILE ".main_shell_history"
#define GRANT_HISTORY_MAX 5024

#define COMMAND_NORMAL 0

char **environ;


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

void _eputs(char *str);
int _eputchar(char s);
int _putfd(char s, int fd);
int _putsfd(char *str, int fd);
int _putchar(char c);

int _erratoi(char *c);
void print_error(alias_t *info, char *erstr);
int print_d(int tip, int fd);
char *convert_number(long int num, int base, int flagg);
void remove_com(char *buff);

char *_strncpy(char *dest, char *src, int m);
char *_strncat(char *dest, char *src, int m);
char *_strchr(char *s, char c);

char **get_environ(alias_t *info);
int _unsetenv(alias_t *info, char *va);
int _setenv(alias_t *info, char *va, char *value);

void clear_infot(alias_t *info);
void set_infot(alias_t *info, char **avv);
void free_infot(alias_t *info, int all);

ssize_t input_buffer(alias_t *info, char **buff, size_t *length);
ssize_t get_inputt(alias_t *info);
ssize_t read_buffer(alias_t *info, char *buff, size_t *sz);
int _getline(alias_t *info, char **ptr, size_t *len);
void sigint_handler(__attribute__((unused)) int signum);

char *get_hist_file(alias_t *info);
int write_hist(alias_t *info);
int read_hist(alias_t *info);
int build_hist_list(alias_t *info, char *buff, int linecount);
int renum_hist(alias_t *info);

node_t *add_node(node_t **head, const char *str, int num);
node_t *add_node_end(node_t **head, const char *str, int num);
size_t print_list_str(const node_t *hh);
int delete_node_at(node_t **head, unsigned int idx);
void free_list(node_t **head_p);

#endif /*MAIN_H*/
