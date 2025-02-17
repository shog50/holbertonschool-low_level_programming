#include "main.h"

/**
 * main - Entry point
 * Descreption:  prints the alphabet in lowercase, followed by a new line
 * Return: Always 0 (success)
 */
void print_alphabet(void)
{
char alphabet[] = "abcdefghijklmnopqrstuvwxyz\n";
int i = 0;
while (alphabet[i] != '\0')
{
_putchar(alphabet[i]);
i++;
}
}

