#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase, followed by a new line
 * Description:  prints the alphabet in lowercase, followed by a new line
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

