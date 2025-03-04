#include "main.h"

/**
* _print_rev_recursion - Prints a string in reverse.
* @s: The string to be printed.
* Description: This function uses recursion to traverse the string
* to the end and prints characters in reverse order
* as the recursion unwinds.
*/
void _print_rev_recursion(char *s)
{
if (*s == '\0')
return;
_print_rev_recursion(s + 1);
_putchar(*s);
}

