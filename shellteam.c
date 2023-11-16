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


char *_getenv(char *name);
int _atoi(char *c);
int compstr(char *s1, char *s2);
char *scrp_dup(char *c);
int execute_file(char **cmd);

#endif /* SHELLTEAM */
