#include "shell.h"
/**
 * print_environment - prints the current environment
 * @pth: argument input
 * Return: Always 0
 */
void print_environment(char *pth)
{
	char **env = environ;

	if (strcmp(pth, "env") == 0)
	{
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
