#include "main.h"
/**
 * print_alphabet_x10 - Prints the alphabet 10 times in lowercase.
 *
 * Description: This function prints the alphabet in lowercase letters
 *              10 times, followed by a new line each time.
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
int count = 0;
char letter;
while (count < 10)
{
letter = 'a';
while (letter <= 'z')
{
_putchar(letter);
letter++;
}
_putchar('\n');
count++;
}
}

