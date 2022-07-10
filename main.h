#ifndef PRNTF
#define PRNTF

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

/**
 * struct function_type - struct with the correct format specifier and function
 * to be called
 * @fmt: format specifier
 * @op: function to be called
 * @mode: usage mode
 *
 * Return: void
 */

typedef struct function_type
{
	char *fmt;
	int (*op)(va_list ap, int mode);
	int mode;
} ftype;

int _printf(const char *format, ...);
int _putchar(va_list args, int mode);
int stringiterator(va_list args, int mode);
int ntostring(va_list args, int mode);
int untostring(va_list ap, int base);
int singlewrite(char c);
int revstring(va_list ap, int mode);
char *rot13(char *s);
char *_strdup(char *str);
int strot(va_list ap, int mode);
ftype func_finder(char c);

#endif
