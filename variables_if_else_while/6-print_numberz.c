#include <stdio.h>
/**
 * main - Entry point
 * Description:the program prints all single numbers of base 10 starting from 0
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
for (i = 0; i < 10; i++)
{
putchar(i + 48);
}
putchar('\n');
return (0);
}

