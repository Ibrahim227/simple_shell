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
#define COMMAND_OR 1
#define COMMAND_AND 2
#define COMMAND_CHAIN 3

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

#define ENTRY_INITIALYZER \
    { \
        NULL,    /* member1 */ \
        NULL,    /* member2 */ \
        NULL,    /* member3 */ \
        0,       /* member4 */ \
        0,       /* member5 */ \
        0,       /* member6 */ \
        0,       /* member7 */ \
        NULL,    /* member8 */ \
        NULL,    /* member9 */ \
        NULL,    /* member10 */ \
        NULL,    /* member11 */ \
        NULL,    /* member12 */ \
        0,       /* member13 */ \
        0,       /* member14 */ \
        NULL,    /* member15 */ \
        0,       /* member16 */ \
        0,       /* member17 */ \
        0        /* member18 */ \
    }


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

size_t list_len(const node_t *hp);
char **list_to_str(node_t *head);
size_t print_list(const node_t *hp);
node_t *node_start_with(node_t *node, char *prefix, char c);
ssize_t get_node_index(node_t *head, node_t *node);

int main(int ac, char **av);

int bfree(void **ptr);

int is_cmd(alias_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(alias_t *info, char *pathstr, char *cmd);

char *_memset(char *s, char ab, unsigned int nn);
void ffree(char **ptr);
void *_realloc(void *ptr, unsigned int old_sz, unsigned int new_sz);

int hsh(alias_t *info, char **av);
int find_builtin(alias_t *info);
void find_cmd(alias_t *info);
void fork_cmd(alias_t *info);


int _strlen(char *c);
int _strcmp(char *s1, char *s2);
char *start_with(const char *has, const char *nee);
char *_strcat(char *dest, char *src);

char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

char **strtow(char *str, char *dem);
char **strtow2(char *str, char dem);

int is_chain(alias_t *info, char *buff, size_t *ptr);
void ver_chain(alias_t *info, char *buff, size_t *ptr, size_t i, size_t len);
int replace_alias(alias_t *info);
int replace_vars(alias_t *info);
int replace_str(char **old_str, char *new_str);


#endif /*MAIN_H*/
