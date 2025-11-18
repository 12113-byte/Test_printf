#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_a_char - prints  only  a char
 * @args: arguments
 * Return: 1 on success
 */
int print_a_char(va_list *args)
{
	char c = va_arg(*args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_a_str - prints a char pointer
 * @args: arguments
 * Return: string length
 */
int print_a_str(va_list *args)
{
	char *s = va_arg(*args, char*);
	int len = 0;

	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}

/**
* print_special - prints a literal %
* @args: arguments
* Return: 1 on success
*/
int print_special(va_list *args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
 * print_an_int - prints an integer
 * @args: arguments
 * Return: int length
 */

int print_an_int(va_list *args)
{
	int number = va_arg(*args, int);
	char digits[12];
	int i = 0, j, len = 0;
	long n = number;

	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}

	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &digits[j], 1);
		len++;
	}
	return (len);
}

/**
 * print_binary - translates the numbers into binary
 * @args: arguments
 * Return: int length
 */

int print_binary(va_list *args)
{
	unsigned int n = va_arg(*args, unsigned int);
	char digits[32];
	int i = 0, j, len = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		digits[i] = (n % 2) + '0';
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &digits[j], 1);
		len++;
	}
	return (len);
}

