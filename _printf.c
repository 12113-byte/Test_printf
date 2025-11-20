#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

specifier_t handlers[] = {
	{ 'c', print_a_char },
	{ 's', print_a_str },
	{ '%', print_special },
	{ 'i', print_an_int_or_decimal },
	{ 'd', print_an_int_or_decimal },
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
	char buffer[1024];
	int counter = 0, buffer_counter = 0, i, found;
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
					counter += handlers[i].print_func(&args, buffer, &buffer_counter);
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
				buffer[buffer_counter] = *format;
				buffer_counter++;
				if (buffer_counter == 1024)
				{
					flush_buffer(buffer, &buffer_counter);
				}
				counter++;
				format++;
			}
		}
		else
		{
			buffer[buffer_counter] = *format;
			buffer_counter++;
			if (buffer_counter == 1024)
			{
				flush_buffer(buffer, &buffer_counter);
			}
			counter++;
			format++;
		}
	}
	flush_buffer(buffer, &buffer_counter);
	va_end(args);
	return (counter);
}
