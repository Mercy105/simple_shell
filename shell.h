#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define MCL 100 /*MAXIMUM COMMAND LENGTH*/
#define IBS 64 /*INITIAL BUFFER SIZE*/
#define BGF 2 /*BUFFER GROWING FACTOR*/

extern char **environ;

void display_prompt(void);
void _ext(char *pth);
void print_environment(char *pth);
void get_tokens(char *args[], char *pth);
/*int _execve(const char *command, char *const argv[], char *const environ[]);*/
/*pid_t wait_pid(pid_t pid, int *wstatus, int options);*/
/*char *path_checker(char *pth);*/

/*string function*/
size_t _strlen(const char *s);
/*int _strcmp(const char *s1, const char s2);*/
size_t _strcspn(const char *str, const char *remaining);
char *_strtok(char *str, const char *input);

/*getline*/
ssize_t getline(char **line, size_t *m, FILE *stream);

#endif
