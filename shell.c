#include "shell.h"
/**
 * main - main program
 * @argc: input argument
 * @argv: input argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *pth = NULL, *args[MCL];
	size_t pth_size = 0;
	ssize_t pth_len;
	pid_t pid;

	(void) argc;
	while (1)
	{
		display_prompt();
		pth_len = getline(&pth, &pth_size, stdin);
		if (pth_len == -1)
		{
			printf("\n");
			break;
		}
		pth[pth_len - 1] = '\0';
		_ext(pth);
		print_environment(pth);
		get_tokens(args, pth);
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
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
		{
			wait(NULL);
		}
	}
	free(pth);
	return (0);
}
