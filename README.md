<h1 align="center">_printf</h1>

<p>This Repository had all functions to make _printf() works correctly.<br>
 _printf() its a custom function based on printf() function from <stdio.h> library.</p>

<h2 align="center">Description</h2>

_printf() is a variadic function that take an argument called "format" that is a string and also a variable list of arguments.
This string can display formatted variables and special control characters, such as new lines (‘\n’), backspaces (‘\b’) and tabspaces (‘\t’).
Conversion control characters describe the format of how the message string uses the other arguments. If printf() contains more than one argument then the format of the output is defined using a percent (%) character followed by a format description character


<h2 align="center">Files</h2>

**_printf.c** - contains the code structure of _printf()

**_printf_func_finder.c** - returs functions to use in _printf

**_printf_aux.c** - basic functions called by printf()
>_putchar - print a character<br>
>stringiterator - iterate over a string and return its contents<br>
>ntostring - convert an int to a string<br>
>untostring - convert an int to a string<br>

**_printf_adv_func.c** - advanced functions called by printf()
>revstring - print the reversed string<br>
>rot13 - encodes a string using rot13<br>
>_strdup - copy of the string given as a parameter<br>
>strot - convert a string of chars to rot13<br>

**main.h** - its the header file that contain all prototypes functions and the standard libraries used in the other functions

<h2 align="center">FLAG CHARACTERS</h2>
  
The character that specifies the Format is **'%'** and it be used followed by one of the next specific characters:
>%c - print a character
>%s - print a string of characters
>%d - print an integer of base 10
>%i - same as %d
>%x - print an hexadecimal number
>%X - print an hexadecimal number
>%o - print an octal number
>%b - print a binary number
>%u - print an unsigned decimal (integer) number
>%r - print a reverse string
>%R - print a rot13 string

<h2 align="center"> EXAMPLES </h2>
This is an example of printf() function when we call in main.c:


    #include "main.h"

    int main(void)
    {
    char string_ex[] = "Example string";
    int integer_ex = -42069;
    char char_ex = '?';
    float float_ex = 0.635;
    double double_ex = 9.11654;
    
    _printf("This is a string: %s\n", string_ex);
    _printf("This is an integer: %d\n", integer_ex);
    _printf("This is a char: %c\n", char_ex);
    _printf("This is a float: %.3f\n", float_ex);
    _printf("This is a double: %f\n", double_ex);
    _printf("This is conversion from decimal to hex: %x\n", integer_ex);
    _printf("This is conversion from decimal to octal: %o\n", integer_ex);
    _printf("This is conversion from decimal to binary: %b\n", integer_ex);
    _printf("This is a border case: %% \n");

    return (0);
    }

Output:

    This is a string: Example string
    This is an integer: -42069
    This is a char: ?
    This is a float: %.3f
    This is a double: %f
    This is conversion from decimal to hex: ffff5bab
    This is conversion from decimal to octal: 122125
    This is conversion from decimal to binary: 11111111111111110101101110101011
    This is a reverse string: gnirts elpmaxE
