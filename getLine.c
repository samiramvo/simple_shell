#include "main.h"

/**
 * attr_line - attribute the line
 * @lineptr: Buffer
 * @buffer: str
 * @n: size of the line
 * @len: size of buffer
 */

void attr_line(char **lineptr, size_t *n, char *buffer, size_t len)
{
	if (*lineptr == NULL)
	{
		if (len > BUFSIZE)
			*n = len;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < len)
	{
		if (len > BUFSIZE)
			*n = len;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - method for reading lines of text
 * @lineptr: the adress of the input text
 * @n: the variable holding the size of the buffer
 * @stream: where we are going to write the input
 * Return: the number of bytes
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int item;
	static ssize_t inp;
	ssize_t value;
	char *buffer;
	char t = 'z';

	if (inp == 0)
		fflush(stream);
	else
		return (-1);
	inp = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		item = read(STDIN_FILENO, &t, 1);
		if (item == -1 || (item == 0 && inp == 0))
		{
		free(buffer);
	return (-1);
		}
	if (item == 0 && inp != 0)
	{
	inp++;
break;
	}
	if (inp >= BUFSIZE)
		buffer = _realloc(buffer, inp, inp + 1);
	buffer[inp] = t;
	inp++;
	}
	buffer[inp] = '\0';
	attr_line(lineptr, n, buffer, inp);
	value = inp;
	if (item != 0)
		inp = 0;
	return (value);
}
