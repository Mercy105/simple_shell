#include "shell.h"
/**
 * display_prompt - used to display shell prompt
 * Return: Standard output
 */
void display_prompt(void)
{
	printf("$ ");
	DIR *d;
	struct dirent *dir;

	d = opendir(".");
	if (d)
	{
		while ((dir = readir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}
