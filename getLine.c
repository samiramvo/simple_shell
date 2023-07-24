#include <stdio.h>
#include <stdlib.h>

/**
 * get_line - method for reading lines of text
 * @lineptr: the adress of the input text
 * @n: the variable holding the size of the buffer
 * @stream: where we are going to write the input
 * Return : the number of bytes
 */

ssize_t get_line(char **lineptr, size_t *n , FILE *stream)
{


