#include "shell.h"
/**
 * main - entry point
 * @argc: argument input
 * @argv: argument input
 * Return: always 0
*/
int main(__attribute__((unused)) int  argc, char *argv[])
{
	signal(SIGINT, &new_line);
	shell(argv[0]);
	return (0);
}

