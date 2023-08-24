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
#include <signal.h>
#ifdef _WIN32
  #define ON_WIN 1
#else
  #define ON_WIN 0
#endif
extern char **environ;

char **prompt(void);
int main(int argc, char *argv[]);
/*ssize_t _getline(char *strnptr, size_t *sz, FILE *desc);*/
int str_cmp(char *a, char *b);
size_t str_len(char *s);
int str_contains(char *a, char *b);
char *str_cat(char *a, char *b);
char *get_env(char *env);
char **get_path_cmds(void);
char *get_command_in_path(char *cmd);
char **tokenizer(char *str, const char *delimeter);
int check_builtin(char **args);
void print_environment(void);
void shell(char *filename);
void execute_command(char *args[], char *filename);
void new_line(int signal);

#endif
