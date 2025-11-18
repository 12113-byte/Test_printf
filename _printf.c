#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

specifier_t handlers[] = {
	{ 'c', print_a_char },
	{ 's', print_a_str },
	{ '%', print_special },
	{ 'i', print_an_int },
	{ 'b', print_binary },
	{ 0, NULL }
};

/**
 * _printf - prints all arguments
 * @format: string
 * Return: counter
 */

int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0, i, found;
	char next;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			next = *(format + 1);
			
			if (next == '\0')
			{
				return (-1);
				break;
			}
			found = 0;
			for (i = 0; handlers[i].specifier != 0; i++)
			{
				if (handlers[i].specifier == next)
				{
					counter += handlers[i].print_func(&args);
					found = 1;
					break;
				}
			}
			if (found)
			{
				format += 2;
			}
			else
			{
				write (1, format, 1);
				counter++;
				format++;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
			format++;
		}
	}
	va_end(args);
	return (counter);
}
