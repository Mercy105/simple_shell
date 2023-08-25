#include "shell.h"

/**
 * prompt - displays command prompt
 * Return: command
 */
char **prompt(void)
{
	char *cmd = NULL, *token,
	*prompt_str = "$ ", *delim = " ";
	size_t z = 512;
	char **args = malloc(sizeof(char *) * z);
	int r, x = 0, w = 0;
	int j;

	j = str_len(prompt_str);
	if (args == NULL)
	{
		perror("Malloc Error");
		return (NULL);
	}
	if (isatty(STDIN_FILENO))
		w = write(STDOUT_FILENO, prompt_str, j);
	if (w < 0)
	{
		perror("Write Error");
		return (NULL);
	}
	r = getline(&cmd, &z, stdin);
	if (r == -1)
		return (NULL);
	if (str_len(cmd) == 0)
		return (NULL);
	cmd[str_len(cmd) - 1] = '\0';
	token = strtok(cmd, delim);
	while (token != NULL)
	{
		args[x] = token;
		x += 1;
		token = strtok(NULL, delim);
	}
	return (args);
}

