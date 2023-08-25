#include "shell.h"
/**
 * path_checker - check if command exists in a path
 * @pth: argument input
 * Return: path or, NULL
 */
char *path_checker(char *pth)
{
	char *path = getenv("PATH");
	char *x, *fpath;
	struct stat st;

	x = strtok(path, ":");
	while (x != NULL)
	{
		fpath = malloc(strlen(x) + strlen(pth) + 2);
		if (fpath == NULL)
		{
			perror("malloc error");
			exit(1);
		}
		sprintf(fpath, "%s/%s", x, pth);
		if (stat(fpath, &st) == 0)
			return (fpath);
		free(fpath);
		x = strtok(NULL, ":");
	}
	return (NULL);
}

