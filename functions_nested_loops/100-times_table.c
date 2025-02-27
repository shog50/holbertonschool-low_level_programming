#include "main.h"

/**
* print_number - prints an integer using _putchar
* @n: integer to be printed
*/
void print_number(int n)
{
if (n == 0)
{
_putchar('0');
return;
}

if (n < 0)
{
_putchar('-');
n = -n;
}

if (n / 10)
{
print_number(n / 10);
}

_putchar(n % 10 + '0');
}

/**
* print_times_table - prints the n times table, starting with 0
* @n: the number for the times table
*/
void print_times_table(int n)
{
int i, j, result;

if (n < 0 || n > 15)
return;

for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
result = i * j;

if (j != 0)
{
_putchar(',');
_putchar(' ');

if (result < 10)
{
_putchar(' ');
_putchar(' ');
}
else if (result < 100)
{
_putchar(' ');
}
}

print_number(result);
}
_putchar('\n');
}
}

