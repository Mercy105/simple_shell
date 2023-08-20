#include "shell.h"
/**
 * _execve - execve
 * @command: input argument
 * @argv: input argument
 * @environ: input argument
 * Return: i
 */
int _execve(const char *command, char *const argv[], char *const environ[])
{
	pid_t c_pid = fork();
	int i;

	if (c_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (c_pid == 0)
	{
		execve(command, argv, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{/*parent process*/
		waitpid(c_pid, &i, 0);
		if (WIFEXITED(i))
			return (WEXITSTATUS(i));
		else if (WIFSIGNALED(i))
			return (-WTERMSIG(i));
		else
			return (-1);
	}
}
