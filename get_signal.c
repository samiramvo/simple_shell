#include "main.h"

/**
 * get_signal - ctrl + c
 * @signal: signal handler
 */

void get_signal(int signal)
{
	(void) signal;
	write(STDOUT_FILENO, "\n^-^", 5);
}
