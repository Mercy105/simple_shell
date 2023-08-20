#include "shell.h"
/**
 * _ext - exiting shell program
 * @pth: input
 */
void _ext(char *pth)
{
	if (strcmp(pth, "exit") == 0)
	{
		printf("\nExiting simple_shell\n");
		exit(0);
	}
}
