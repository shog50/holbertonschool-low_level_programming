#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: A program that prints all possible different combinations
 * of three digits in ascending order, separated by ', '.
 * Return: Always 0 (Success)
 */

int main(void)
{
int i, j, k;
for (i = 0; i < 10; i++)
{
for (j = i + 1; j < 10; j++)
{
for (k = j + 1; k < 10; k++)
{
putchar(i + 48);
putchar(j + 48);
putchar(k + 48);
if (i != 7 || j != 8 || k != 9)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');
return (0);
}
