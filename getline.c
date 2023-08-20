#include "shell.h"
/**
 * _getline - my own getline
 * @line: argument input
 * @m: argument input
 * @stream: argument input
 * Return: len
 */
ssize_t _getline(char **line, size_t *m, FILE *stream)
{
	size_t len = 0, m_size;
	int c;
	char *m_buff;

	if (*line == NULL || m == NULL || stream == NULL)
		return (-1);
	if (*line == NULL || *m == 0)
	{
		*m = IBS; /*INITIAL_BUFFER_SIZE*/
		*line = (char *)malloc(*m);
		if (*line == NULL)
			return (-1);
	}
	c = fgetc(stream);
	while (c)
	{
		if (len >= *m - 1)
		{
			m_size = *m * BGF; /*BUFFER_GROWING_FUNCTION*/
			m_buff = (char *)realloc(*line, m_size);
			if (m_buff == NULL)
				return (-1);
			*line = m_buff;
			*m = m_size;
		}
		(*line)[len++] = c;
		if (c == '\n')
			break;
	}
	if (len == 0 && c == EOF)
		return (-1);
	(*line)[len] = '\0';
	return (len);
}
