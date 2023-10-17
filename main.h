#ifndef _MAIN_H_
#define  _MAIN_H_

#define _GNU_SOURCE
#define CMD_SIZE 64

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int _putchar(char c);
int create_process(char *cmd[], char *);
char **processToken(char *line);
char *location(char *cmd);
char *_getenv(char *name);

void print_message(const char *message);
void print_number(int num);

void _free(char *cmd);
void free_cmds(char **cmd);

/*String helper functions*/
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
size_t _strlen(const char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

char *getInput();
int execute(char **args);
void sigintHandler(int signum);
void chck(char *, char *);

#endif
