#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _strlen - returns the len of string
 * @str: string arg
 * Return: len of str
*/
int _strlen(char *str)
{
	int i;

	for (i = 0; *(str + i); i++)
		;
	i++;
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * my_printf - prints a string to std output
 * @str: string arg
 * Return: 1 on success
*/
int my_printf(char *str)
{
	return (write(1, str, _strlen(str)));
}

/**
 * _printf - prints a string to std output
 * @format: format-string arg
 * Return: 0 on success
*/
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		_putchar(*format);
		else
		{
			if (*(format + 1) == '%')
			{
				_putchar('%');
				format++;
			}
			if (*(format + 1) == 'c')
			{
				_putchar(va_arg(args, int));
				format++;
			}
			if (*(format + 1) == 's')
			{
				my_printf(va_arg(args, char*));
				format++;
			}
		}
		format++;
	}
	va_end(args);

	return (0);
}
