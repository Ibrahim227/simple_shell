#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>


/*Handle Macros*/
#define BUFFER_SIZE 6024
#define MAX_ARGS 2048
#define UNUSED __ATTRIBUTE__((unused))


static char *cmd __attribute__((unused));
extern char **environ;
extern int out_code;

/*Protottype*/
char *_getenv(char *str);
char *_getline(void);
void hash_handler(char *buff);
void *_memcpy(void *src, void *dest, size_t num);
void *_realloc(void *ptr, size_t size);
char *_strdup(char *ss);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *st1, const char *st2, size_t m);
int _strlen(const char *str);
int _strncpy(char *dest, char *src, int size);
int _strcpy(char *dest, char *src);
void _perrore(char *err, int cnt, char *s, char *arg);
int process_cmd(char **argv);
void avoid_segfault(int signumber __attribute__((unused)));
int ver_access(char **arg, char *cmd, char *err, int cnt, char **ev);
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
void token_flag(char *command, char *argv[MAX_ARGS]);
int argnums(char *argv[]);
int _atoi(const char *str);
char *read_cmd(void);
char *which(char *command);
void cd(char *path);
int _putchar(char c);
void rem_tl_space(char *str);
int _lexit(char *status __attribute__((unused)), int cnt, char *s, char **asg);

/**
* struct Node - singly linked listed
* @str: str
* @next: a pointer to the next node
*/
struct Node
{
	char *str;
	struct Node *next;
};


/*static struct Node *start_node(char *str) UNUSED;*/
/**
* start_node - create a new bode
* @str: str to be stored
* Return: 0
*/
static struct Node *start_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);

	node->str = str;
	node->next = NULL;
	return (node);
}

/*static void last_node(struct Node **head, struct Node *node) UNUSED;*/
/**
* last_node - add a node to the end of linked list
* @head: pointer to head
* @node: node to be added
* Return: 0
*/
static void last_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *curent = *head;

		while (curent->next != NULL)
			curent = curent->next;
		curent->next = node;
	}
}

void print_list(struct Node *head);
void free_list(struct Node *head);
int _env(void);
int _setenv(const char *name, const char *value);
void add_env_v(struct Node **head, const char *name, const char *value);
void update_env(struct Node *head);
int _unsetenv(const char *name);
void hand_sigint(int signumber __attribute__((unused)));
void remspace(char *c);
int wspace(char c);
/**
* struct original_s - a struct represent an origin
* @name: alias name
* @value: alias value
* @next: a pointer to the next origin
* Return: origin
*/
typedef struct original_s
{
	char *name;
	char *value;
	struct original_s *next;
} original_t;

void init_original(original_t **origin);
int origin_command(char *argv[MAX_ARGS], int argnum __attribute__((unused)));
void set_original(original_t **origin, char *name, char *value);
void print_original(original_t *org);
void print_all_original(original_t *origin);
char *_strchr(const char *str, int strfi);
void _exec(char **_argnum, char *vv, int cnt);
void _execve(char *cm, char **parg, char **rev);
void _perror(char *err, int cnt, char *cname);
void _print(char *z);
void _pnumber(int m);


#endif /*MAIN_H*/
