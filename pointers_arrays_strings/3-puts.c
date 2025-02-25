#include "main.h"
#include <unistd.h>

/**
* _puts - Prints a string, followed by a new line, to stdout
* @str: Pointer to the string to be printed
*
* This function takes a pointer to a string as a parameter and prints
* the string followed by a new line to the standard output.
*/
void _puts(char *str)
{
int len = 0;

while (str[len])
{
len++;
}

write(1, str, len);
write(1, "\n", 1);
}

