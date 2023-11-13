#ifndef MAIN_H
#define MAIN_H

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/resource.h>
#include<sys/time.h>

/*Handle Macros*/
#define BUFFER_SIZE 6024
#define MAX_ARGS 2048

extern char **environ;
extern int out_code;

/*Protottype*/
char *_getenv(char *str);
char *_getline(void);
void hash_handler(char *buff);
void *_memcpy(void *src, void *dest, size_t num);
void *_realloc(void *ptr, size_t size);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char str2);
int _strncmp(const char *st1, const char *st2, size_t m);
int _strlen(const char *str);
int _strncpy(char *dest, char *src, int size);
int _strcpy(char *dest, char *src);
void cd(char *path);


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

/**
* beg_node - create a new bode
* @str: str to be stored
* Return: 0
*/
static void Node *beg_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);

	node->str = str
	node->next = NULL;
	return (node);
}
/**
* end_node - add a node to the end of linked list
* @head: pointer to head
* @node: node to be added
* Return: 0
*/
static void end_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node curent = *head;

		while (curent->next != NULL)
			curent = curent->next;
		curent->next = node;
	}
}
int _env(void);
int _setenv(const char *name, const char *value);
void add_env_v(struct Node **head, const char *name, const char *value);
void update_env(struct Node *head);
int _unsetenv(const char *name);
void free_list(struct Node *head);
void print_list(struct Node *head);

/**
* struct original_s - a struct represent an alias
* @name: alias name
* @value: alias value
* @next: a pointer to the next alias
* Return: alias
*/
typedef struct original_s
{
	char *name;
	char *value;
	struct original_s *next;
} original_t;
void init_origin(original_t **origin)
int origin_command(char *argv[MAX_ARGS], int argnum __attribute__((unused)));
void set_origin(original_t **origin, char *name, char *value);
void print_origin(original_t *org);
void print_all_origin(original_t *origin);
char *_strchr(const char *strse, int strfi);
void _exec(char **_argnum, char *vv, int cnt);
void _execve(char *cm, char **parg, char **rev);
void _perror(char *err, int cnt, char *cname);
void _print(char *z);
void _pnumber(int m);


#endif /*MAIN_H*/
