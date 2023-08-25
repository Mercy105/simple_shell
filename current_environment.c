#include "shell.h"
/**
 * get_env - obtains evironment variable
 * @env: argument name
 * Return: variable
*/
char *get_env(char *env)
{
	char *m, *token, *delim = "=";
	int x = 0;

	while (environ[x] != NULL)
	{
		m = str_cat("", environ[x]);
		token = strtok(m, delim);
		if (str_cmp(token, env) == 0)
			return (strtok(NULL, delim));
		x += 1;
	}
	return ("");
}
/**
 * get_path_cmds - gets list of commands available in PATH
 * Return: list
*/
char **get_path_cmds(void)
{
	int i = 0, max = 1000;
	char *token, **tokens = malloc(sizeof(char *) * max);
	char *path = get_env("PATH");
	char *delim = ":";

	if (tokens == NULL)
	{
		perror("malloc");
		exit(0);
	}
	if (ON_WIN == 1)
		delim = ";";

	token = strtok(path, delim);

	while (token != NULL)
	{
		tokens[i] = token;

		token = strtok(NULL, delim);
		i += 1;
	}
	free(token);
	return (tokens);
}
/**
 * get_command_in_path - returns a command on PATH
 * @cmd: the command
 * Return: the command's full path
*/
char *get_command_in_path(char *cmd)
{
	char *full, *file, **files = get_path_cmds();
	int x, i = 0;

	while (files[i] != NULL)
	{
		file = files[i];
		full = str_cat(file, str_cat("/", cmd));
		x = access(full, X_OK);
		if (x == 0)
			return (full);
		i += 1;
	}
	free(files);
	return (NULL);
}

