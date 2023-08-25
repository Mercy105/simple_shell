#include "shell.h"
#define _SHELL_H_

/**
 * tokenizer - tokenizes input buffer
 * @str: input string
 * @delimiter: delimiter character
 * Return: array of tokens
 */
char **tokenizer(char *str, const char *delimiter)
{
	int i = 0;
	char **tokens = NULL;
	char *token = NULL;

	if (str == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (NULL);
	token = strtok(str, delimiter);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * check_builtin - checks for built-in commands
 * @args: argument
 * Return: 1, or 0
 */
int check_builtin(char **args)
{
	if (str_cmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			int exit_status = atoi(args[1]);

			exit(exit_status);
		}
		else
		{
			exit(0);
		}
		return (1);
	}
	else if (str_cmp(args[0], "env") == 0)
	{
		print_environment();
		return (1);
	}
	return (0);
}
/**
 * print_environment - prints current environment
 * Return: void
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

