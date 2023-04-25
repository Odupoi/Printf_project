#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 *//print_int: writes an integer to stdout
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args, char buffer[])
{
	int i = BUFFER_SIZE - 2; /* start from the end */
	int is_negative = 0; /* flag for whether integer is negative */
	int n = va_arg(args, int); /* get integer from argument list */
	unsigned int num; /* unsigned int to take into account INT_MIN */

	buffer[BUFFER_SIZE - 1] = ‘\0’; /* set last character to null byte */

	/* if n is negative, set is_negative flag, convert n to positive */
	if (n < 0)
	{
		is_negative = 1;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	/* if n is 0, print 0 */
	if (n == 0)
		buffer[i--] = ‘0’;

	/* write num to buffer, starting from the last digit */
	while (num > 0)
	{
		buffer[i--] = (num % 10) + ‘0’;
		num /= 10;
	}

	/* if n is negative, add ‘-’ to buffer */
	if (is_negative)
		buffer[i] =  ‘-’;
	else
		i++;

	/* write buffer to stdout starting from index i */
	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}

