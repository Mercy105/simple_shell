#include "shell.h"
#include <dirent.h>
/**
 * display_prompt - used to display shell prompt
 * Return: Standard output
 */
void display_prompt(void)
{
	DIR *d;
	struct dirent *dir;

	printf("$ ");
	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}
