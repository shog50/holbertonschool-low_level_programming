#include "main.h"

/**
 * main - point Entry
 * print_alphabet_x10 - Prints the alphabet 10 times in lowercase
 * descriptin: a function that prints 10 times the alphabet, in lowercase.
 * Return: Always 0 (Success)
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

