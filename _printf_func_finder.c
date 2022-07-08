#include "main.h"
#include <stddef.h>

/**
 * func_finder - returs function to use in _printf
 * @c: character identifier for function
 *
 * Return: ftype containing function
 */

ftype func_finder(char c)
{
	ftype func[] = {
		{"c", _putchar, 0},
		{"s", stringiterator, 0},
		{"d", ntostring, 10},
		{"x", ntostring, 16},
		{"X", ntostring, 32},
		{"o", ntostring, 8},
		{"b", ntostring, 2},
		{"i", ntostring, 10},
		{NULL, NULL, 0}
	};
	int i = 0;

	while (func[i].fmt != NULL)
	{
		if (*(func[i].fmt) == c)
			return (func[i]);
		i++;
	}
	return (func[i]);
}
