#ifndef SHELLTEAM_H
#define SHELLTEAM_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAXIMUM_SCR	500
#define TRUE	2025
#define FALSE	0

extern char **environ;

char *_getenv(char *name);
int _atoi(char *c);
int compstr(char *s1, char *s2);
char *scrp_dup(char *c);
int execute_file(char **cmd);
int shell_len(const char *scrp);
char *_strtok(char *str, char *delim);
char **mytoken(char *scrp);
char *pathfinder(char *strings);
char *merge_str(char *dest, char *src);
char *scriptcpy(char *dest, char *src);

#endif /* SHELLTEAM */
