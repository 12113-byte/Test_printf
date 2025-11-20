#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_a_char - prints  only  a char
 * @args: arguments
 * Return: 1 on success
 */
int print_a_char(va_list *args, char *buffer, int *buffer_counter)
{
	char c = va_arg(*args, int);
	buffer[*buffer_counter] = c;
	(*buffer_counter)++;
	if (*buffer_counter == 1024)
	{
		flush_buffer(buffer, buffer_counter);
	}
	return (1);
}

/**
 * print_a_str - prints a char pointer
 * @args: arguments
 * Return: string length
 */
int print_a_str(va_list *args, char *buffer, int *buffer_counter)
{
	int len = 0, i = 0;
	char *s = va_arg(*args, char*);

	if (s == NULL)
	{
		while (i < 6)
		{
			buffer[*buffer_counter] = "(null)"[i];
			(*buffer_counter)++;
			i++;
			len++;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
	}
	while (*s)
	{
		buffer[*buffer_counter] = *s;
		(*buffer_counter)++;
		s++;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
	}
	return (len);
}

/**
* print_special - prints a literal %
* @args: arguments
* Return: 1 on success
*/
int print_special(va_list *args, char *buffer, int *buffer_counter)
{
	(void)args;
	buffer[*buffer_counter] = '%';
	(*buffer_counter)++;
	if (*buffer_counter == 1024)
	{
		flush_buffer(buffer, buffer_counter);
	}
	return (1);
}

/**
 * print_an_int - prints an integer
 * @args: arguments
 * Return: int length
 */

int print_an_int_or_decimal(va_list *args, char *buffer, int *buffer_counter)
{
	int number = va_arg(*args, int);
	char digits[sizeof(int) * 8 + 2];
	int i = 0, j, len = 0;
	long n = number;

	if (number == 0)
	{
		buffer[*buffer_counter] = '0';
		(*buffer_counter)++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
		len++;
		return (len);
	}

	if (n < 0)
	{
		buffer[*buffer_counter] = '-';
		(*buffer_counter)++;
		n = -n;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
	}

	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer[*buffer_counter] = digits[j];
		(*buffer_counter)++;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
	}
	return (len);
}

/**
 * print_binary - translates the numbers into binary
 * @args: arguments
 * Return: int length
 */

int print_binary(va_list *args, char *buffer, int *buffer_counter)
{
	unsigned int n = va_arg(*args, unsigned int);
	char digits[sizeof(unsigned int) * 8];
	int i = 0, j, len = 0;

	if (n == 0)
	{
		buffer[*buffer_counter] = '0';
                (*buffer_counter)++;
                if (*buffer_counter == 1024)
                {
                        flush_buffer(buffer, buffer_counter);
                }
                len++;
                return (len);
	}

	while (n > 0)
	{
		digits[i] = (n % 2) + '0';
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		
		buffer[*buffer_counter] = digits[j];
                (*buffer_counter)++;
                len++;
                if (*buffer_counter == 1024)
                {
                        flush_buffer(buffer, buffer_counter);
                }
	}
	return (len);
}

/**
 * flush_buffer - prints all stored values
 */
void flush_buffer(char *buffer, int *buffer_counter)
{
	write(1, buffer, *buffer_counter);
	*buffer_counter = 0;
}

/**
 * print_string - prints a string with non priintable characters included
 * @args: arguments
 * Return:
 */

int print_string(va_list *args, char *buffer, int *buffer_counter)
{
	int len = 0, i = 0, firt_digit, second_digit;
	unsigned char val;
	char *s = va_arg(*args, char*);

	if (s == NULL)
	{
		while (i < 6)
		{
			buffer[*buffer_counter] = "(null)"[i];
			(*buffer_counter)++;
			i++;
			len++;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
	}
	while (*s)
	{
		if (*s >= 32 && *s <= 126)
		{
		buffer[*buffer_counter] = *s;
		(*buffer_counter)++;
		s++;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
		}
		else
		{
		buffer[*buffer_counter] = '\\';
		(*buffer_counter)++;
		buffer[*buffer_counter] = 'x';
		(*buffer_counter)++;
		val = (unsigned char)*s;
		first_digit = val / 16;
		buffer[*buffer_counter] = first_digit;
		(*buffer_counter)++;
		second_digit = val % 16;
		buffer[*buffer_counter] = second_digit;
		(*buffer_counter)++;
		len++;
		if (first_digit < 10)
		{
			first_char = '0' + first_digit;
			buffer[*buffer_counter] = *s;
			(*buffer_counter)++;
		}
		else (first_digit >= 10)
		{
			first_char = 'A' + (first_digit - 10);
			buffer[*buffer_counter] = *s;
			(*buffer_counter)++;
		}
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
		}
	}
	return (len);
}

