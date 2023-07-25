#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>


#define BUFSIZE 1024
#define TOKEN_BUFSIZE 128

/* whne you call the environement*/
extern char **environ;

/**
 * struc data_sh - that contains all relevant data
 * @av : argument
 * @args : tokens in the command
 * @inp : command line that user write
 * @stat: last status of the sh
 * @count: counter line
 * @_environ: variable environnement
 * @pid: process ID 
 */

typedef struct data_sh
{
	char **av;
	char **args;
	char *input;
	int stat;
	int count;
	char **_environ;
	char *pid;
}datash;

/**
 * struct builtin_s -Builtin struct
 * @name: The name of the command(cd, exit...)
 * @ftype: data type pointer function
 */

typedef struct builtin_s
{
	char *name;
	int (*ftype)(datash *data);
}builtin_t;
	

int execv(const char *filename, char *const argv[], char *const envp[]);
int open(const char *pathname, int flags, mode_t mode);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf , size_t count);
char * _getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char **_strtok(char *str, const char *delim);
extern char **environ
#endif
