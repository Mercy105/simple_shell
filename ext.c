#include "shell.h"
/**
 * _ext - exiting shell program
 * @pth: input
 * Return: Always 0
 */
void _ext(char *pth)
{
	if (strcmp(pth, "exit") == 0)
	{
		printf("\nExiting simple_shell\n");
		exit(0);
	}
}
