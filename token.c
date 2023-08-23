#include "shell.h"
/**
 * get_tokens - gets tokens from string
 * @args: input
 * @pth: input
 * Return: tokens
 */
void get_tokens(char *args[], char *pth)
{
	char *token = strtok(pth, " ");
	int y = 0;

	while (token != NULL)
	{
		args[y] = token;
		token = strtok(NULL, " ");
		y++;
	}
	args[y] = NULL;
}
