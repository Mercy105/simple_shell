#include "shell.h"
/**
 * _ext - exiting shell programme
 * @cmd: inpute
 */

void _ext(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		printf("Exiting shell program\n");
		exit(0);
	}
}
