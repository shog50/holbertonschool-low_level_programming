#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * print_name - Prints a name using a given function pointer.
 * @name: The name to be printed.
 * @f: A pointer to a function that defines how the name is printed.
 */
void print_name(char *name, void (*f)(char *));

/**
 * _putchar - Writes a character to standard output.
 * @c: The character to be written.
 * Return: On success, returns 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);
void array_iterator(int *array, size_t size, void (*action)(int));




#endif /* FUNCTION_POINTERS_H */

