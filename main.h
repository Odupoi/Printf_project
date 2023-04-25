#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define UNUSED (*) (void)(*)

/**
 * struct fmt - format structure
 * @spec: the character that is the conversion specifier
 * @fnc: the function that handles the conversion
 *
 * Description: A structure that maps a conversion specifier to the function that handles that conversion
 */
typedef struct fmt
{
	char spec;
	int (*fnc)(va_list, char[]);
} fmt_t;

int _printf(const char *format, ...);

int print_char(va_list args, char buffer[]);
int prrint_str(va_list args, char buffer[]);
int print_percent(va_list args, char buffer[]);
int print_int (va_list args, char buffer[]);

#endif /*MAIN_H*/
