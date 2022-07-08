#include "main.h"
#include <unistd.h>
#include <stddef.h>

/**
 * _printf: print string to stdout using variable arguments
 * @format: template string to print
 *
 * Return: string length
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	ftype func_data;
	va_list ap;

	if (format == NULL)
	{
		return (-1);
	}
	else
	{
		va_start(ap, format);
			while ((format[i] != '\0') && (format != NULL))
			{
				if ((format[i] == '%') && (format[i + 1] != '%'))
				{
					func_data = func_finder(format[i + 1]);
					if (func_data.op != 0)
					{
						j += (*(func_data.op))(ap, func_data.mode);
						i = ((*(func_data.fmt) == '.') ? (i + 4) : (i + 2));
					}
				}
				else if ((format[i] == '%') && ((format[i + 1] == '%') || (format[i + 1] == '\0')))
				{
					i++;
					j += singlewrite(format[i++]);
				}
				else
				{
					j += singlewrite(format[i++]);
				}
			}
	va_end(ap);
	}
	return (j);
}