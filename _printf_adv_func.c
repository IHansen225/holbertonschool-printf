#include "main.h"

/**
 * revstring - print the reversed string
 * @ap: string to iterate)
 * @mode: usage mode
 *
 * Return: string length
 */

int revstring(va_list ap, int mode)
{
	char *s = va_arg(ap, char*);
	int i = 0, l = strlen(s);

	(void) mode;
	for (i = l - 1; i >= 0; i--)
		write(1, &s[i], 1);
	va_end(ap);
	return (l);
}

/**
 * rot13 - encodes a string using rot13
 * @s: string of chars
 * Return: a pointer to a string
 */

char *rot13(char *s)
{
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (j <= 51)
		{
			if (s[i] == input[j])
			{
				s[i] = output[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (s);
}

/**
 * _strdup - copy of the string given as a parameter
 * @str: string of char
 *
 * Return: a pointer to the duplicated string. It returns
 * NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	char *res = NULL;
	size_t i = 0;

	if (str != NULL)
		res = malloc(strlen(str) + 1);
	if (res != NULL)
	{
		for (i = 0; i <= strlen(str); i++)
			res[i] = str[i];
	}
	return (res);
}

/**
 * strot - convert a string of chars to ro13
 * @ap: string of chars to convert
 * @mode: usage mode
 *
 * Return: string length
 */

int strot(va_list ap, int mode)
{
	int l = 0;
	char *aux1, *aux2, *s = va_arg(ap, char*);

	(void) mode;
	if (s)
	{
		l = strlen(s);
		aux1 = _strdup(s);
		if (aux1 != NULL)
		{
			aux2 = rot13(aux1);
			write(1, aux2, l);
			free(aux1);
			va_end(ap);
		}
	}
	return (l);
}
