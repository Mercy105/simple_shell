#include "shell.h"
/**
 * execute_command - used to execue command
 * @args: command and list of arguments
 * @filename: the name file
 * Return: 0, or 1
*/
void execute_command(char *args[], char *filename)
{
	char *cmd = args[0];
	int x;

	x = execve(cmd, args, environ);
	if (x == -1)
	{
		perror(filename);
		free((*args));
	}
}
/**
 * shell - used to start shell
 * @filename: name of the executable file
 * Return: void
*/
void shell(char *filename)
{
	pid_t pid;
	char **cmd = NULL;
	int status;

	while (1)
	{
		cmd = prompt();
		pid = fork();
		if (pid > 0)
			waitpid(pid, &status, 0);
		if (pid == -1)
		{
			perror(filename);
			break;
		}
		if (pid == 0)
			execute_command(cmd, filename);
		else
			wait(0);
	}
}
/**
 * new_line - writes a newline
 * @signal: input signal
 * Return: void
*/
void new_line(int signal)
{
	char *prompt_str = "\n$ ";
	int is_valid;

	if (signal == SIGINT)
	{
		is_valid = isatty(STDIN_FILENO);
		if (is_valid == 1)
			write(STDOUT_FILENO, prompt_str, str_len(prompt_str));
	}
}
