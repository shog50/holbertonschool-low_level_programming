#include <stdio.h>
#include <math.h>

/**
* main - finds and prints the largest prime factor of 612852475143
*
* Return: Always 0 (Success)
*/
int main(void)
{
long number = 612852475143;
long max_prime = -1;
long i;

/* Divide out the factor of 2 first */
while (number % 2 == 0)
{
max_prime = 2;
number /= 2;
}

/* Divide out odd factors from 3 onwards */
for (i = 3; i <= sqrt(number); i += 2)
{
while (number % i == 0)
{
max_prime = i;
number /= i;
}
}

/* If number is a prime number greater than 2 */
if (number > 2)
{
max_prime = number;
}

printf("%ld\n", max_prime);

return (0);
}

