#include "shell.h"
/**
 * main - entry point
 * @argc: argument input
 * @argv: argument input
 * Return: always 0
*/
int main(int argc, char *argv[])
{
	(void)argc;
	signal(SIGINT, &new_line);
	shell(argv[0]);
	return (0);
}

