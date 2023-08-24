#include "shell.h"
/**
 * _getline - readline
 * @strnptr: shows where string is written
 * @sz: size of the string
 * @desc: identifies an open file
 * Return: -1 or length of the line read
*/
ssize_t _getline(char **strnptr, size_t *sz, FILE *desc)
{
	char *m_buffer = malloc(sizeof(char *) * *sz);
	int x;

	if (m_buffer == NULL)
		return (-1);
	if (desc != NULL)
	x = read(STDIN_FILENO, m_buffer, *sz);

	if (x  == 0)
		return (-1);

	if (str_len(m_buffer) > 0)
	{
		m_buffer[str_len(m_buffer)] = '\0';
		strnptr[0] = m_buffer;
	}
	return (str_len(m_buffer));
}
