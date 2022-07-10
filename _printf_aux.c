#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * _putchar - put a character
 * @ap: character to put
 * @mode: usage mode
 *
 * Return: 1
 */

int _putchar(va_list ap, int mode)
{
	char *c = va_arg(ap, char *);

	(void) mode;
	write(1, &c, 1);
	va_end(ap);
	return (1);
}

/**
 * stringiterator - iterate over a string and return its contents
 * @ap: string to iterate
 * @mode: usage mode
 *
 * Return: string length
 */

int stringiterator(va_list ap, int mode)
{
	char *s = va_arg(ap, char *);

	(void) mode;
	if (s)
		write(1, s, strlen(s));
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	va_end(ap);
	return (strlen(s));
}

/**
 * ntostring - convert an int to a string
 * @ap: int to convert
 * @base: int base
 *
 * Return: strlen
 */

int ntostring(va_list ap, int base)
{
	char *buffer;
	long int n = (long)(va_arg(ap, int));
	long int i = 0, len, flag;

	buffer = malloc(32);
	if (!buffer)
		return (0);
	flag = ((n < 0) ? 1 : 0);
	n = ((n < 0) ? (n * -1) : n);
	if (n != 0)
	{
		while (n > 0)
		{
			if (base <= 10)
				buffer[i++] = ((n % base) + '0');
			else if (base == 16)
			{
				if ((n % base) >= 10)
					buffer[i++] = ((n % base) + ((base == 32) ? 55 : 87));
				else
					buffer[i++] = ((n % base) + '0');
			}
			n = n / base;
		}
		if (flag && (base == 10))
			buffer[i++] = 45;
		i = ((base == 2) ? i : i - 1);
		for (; i >= 0; i--)
			write(1, &buffer[i], 1);
	} else
	{
		buffer[i] = '0';
		write(1, &buffer[i], 1);
		return (1);
	}
	len = strlen(buffer);
	free(buffer);
	va_end(ap);
	return ((int)len);
}

int untostring(va_list ap, int base)
{
	char *buffer;
	unsigned int n = (unsigned int)(va_arg(ap, int));
	int i = 0, len, flag;

	base = (unsigned int)base;
	flag = ((base == 32) ? 1 : 0);
	base = ((base == 32) ? 16 : base);
	buffer = malloc(32);
	if (!buffer)
		return (0);
	if (n != 0)
	{
		while (n > 0)
		{
			if (base <= 10)
				buffer[i++] = ((n % base) + '0');
			else if (base == 16)
			{
				if ((n % base) >= 10)
					buffer[i++] = ((n % base) + ((flag == 1) ? 55 : 87));
				else
					buffer[i++] = ((n % base) + '0');
			}
			n = n / base;
		}
		i = ((base == 2) ? i : i - 1);
		for (; i >= 0; i--)
			write(1, &buffer[i], 1);
	} else
	{
		buffer[i] = '0';
		write(1, &buffer[i], 1);
		return (1);
	}
	len = strlen(buffer);
	free(buffer);
	va_end(ap);
	return ((int)len);
}