#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: It prints all possible different combinations of two digit
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i, j;
for (i = 0; i < 10; i++)
{
for (j = i + 1; j < 10; j++)
{
putchar(i + 48);
putchar(j + 48);
if (i < 8 || j < 9)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
