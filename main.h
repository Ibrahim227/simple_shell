#ifndef __MAIN_H__
#define __MAIN_H__

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

int access(const char *pathname, int mode);
int chdir(const char *path);
int close(int fd);
int closedir(DIR *dirp);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void exit(int status);
void _exit(int status);
int fflush(FILE *stream);
pid_t fork(void);
void free(void *ptr);
char *getcwd(char *buf, size_t size);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
pid_t getpid(void);
int isatty(int fd);
int kill(pid_t pid, int sig);
void *malloc(size_t size);
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
DIR *opendir(const char *name);
void perror(const char *s);
ssize_t read(int fd, void *buf, size_t count);
struct dirent *readdir(DIR *dirp);
typedef void (*sighandler_t)(int);
int stat(const char *pathname, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
pid_t waitpid(pid_t pid, int *wstatus, int options);
pid_t wait3(int *wstatus, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
ssize_t write(int fd, const void *buf, size_t count);


/**
 * struct dirent - manage directory
 * @d_ino: Inode number
 * @d_off: Not an Offset
 * @d_reclen: length of the record
 * @d_type: type of file
 * @d_name: variable name
 *
 * Return: Always 0
 */
struct dirent
{
	ino_t	d_ino;
	off_t	d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char	d_name[256];
};
#endif
