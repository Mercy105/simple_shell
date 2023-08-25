#include "shell.h"
#define _SHELL_H_

/**
 * str_cmp - compares two strings
 * @a: first string
 * @b: second string
 * Return: -1, or 0
*/
int str_cmp(char *a, char *b)
{
	int x = 0;

	while (a[x] != '\0' && b[x] != '\0' && a[x] == b[x])
		x += 1;
	if (a[x] == '\0' && a[x] == '\0')
		return (0);
	return (-1);
}
/**
 * str_len - measure length of a string
 * @s: string argument
 * Return: length of a string
 */
size_t str_len(char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len += 1;
	return (len);
}
/**
 * str_contains - checks if a string contains another string
 * @a: string one
 * @b: string two
 * Return: 1 or 0
 */
int str_contains(char *a, char *b)
{
	size_t i = 0, j, x = 0;

	if (str_len(a) == 0 || str_len(b) == 0)
		return (0);
	while (i < str_len(a))
	{
		j = 0;

		while (j < str_len(b))
		{
			if (a[i + j] == b[j])
				x += 1;
			j += 1;
		}
		if (x == str_len(b))
			return (1);

		i += 1;
	}
	return (0);
}
/**
 * str_cat - concatenetes two strings
 * @a: first string
 * @b: second string
 * Return:  new string
 */
char *str_cat(char *a, char *b)
{
	int i = 0, j = 0;
	char *s = malloc(sizeof(char) * (str_len(a) + str_len(b)));

	if (s == NULL)
	{
		perror("malloc");
		exit(0);
	}
	while (a[i] != '\0')
	{
		s[j] = a[i];
		i += 1;
		j += 1;
	}
	i = 0;
	while (b[i] != '\0')
	{
		s[j] = b[i];
		i += 1;
		j += 1;
	}
	return (s);
}

