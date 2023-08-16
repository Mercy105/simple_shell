#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX_LENGTH 100
/**
 * display_prompt - used to display the prompt
 */
void display_prompt(void)
{
	printf("simple_shell$ ");
	fflush(stdout);
}
/**
 * execute_command - carries out execution of commands
 * @command: argument
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char *args[] = {NULL, NULL};

		args[0] = command;
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * rum_shell - program to run the shell
 */
void run_shell(void)
{
	char buffer[100];
	char command[100];

	size_t len = strlen(buffer);
	while (1)
	{
		display_prompt();
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\nExiting simple_shell\n");
				break;
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}
		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
		}
		if (strlen(buffer) == 0)
		{
			continue;
		}
		strcpy(command, buffer);
		execute_command(buffer);
	}
}
