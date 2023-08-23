#include "shell.h"
/**
 * _strlen - returns the length of string
 * @s: argument input
 * Return: m
 */
size_t _strlen(const char *s)
{
	size_t m;

	m = strlen(s);
	return (m);
}
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: out
 */
int _strcmp(const char *s1, const char *s2)
{
	int out;

	out = strcmp(s1, s2);
	return (out);
}
/**
 * _strcspn - gets legth prefix
 * @str: argument input
 * @remaining: argument 2
 * Return: count
 */
size_t _strcspn(const char *str, const char *remaining)
{
	size_t ct = 0;

	ct = strcspn(str, remaining);
	return (ct);
}
/**
 * _strtok - extracts token from string
 * @str: input 1
 * @input: input 2
 * Return: token
 */
char *_strtok(char *str, const char *input)
{
	char *token;

	token = strtok(str, input);
	return (token);
}
