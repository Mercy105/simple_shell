#include "shell.h"
/**
 * _fork - fork
 * @args: argument input
 * @argv: argument input
 * @pth: argument input
 * Return: 0, or -1
 */
int _fork(char *args[], char *argv[], char *pth)
{
	pid_t pid = fork();
	int i;

	if (pid < 0)
	{
		printf("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		args[0] = pth;
		args[1] = NULL;
		execve(pth, args, NULL);
		printf("%s: No such file or directory\n", argv[0]);
		exit(1);
	}
	else
		waitpid(pid, &i, 0);
	return (0);
}
