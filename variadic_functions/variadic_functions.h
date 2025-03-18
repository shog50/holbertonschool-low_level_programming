#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 * Return: On success, returns 1. On error,
 * -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);


#endif /* FUNCTION_POINTERS_H */

