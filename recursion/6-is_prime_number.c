#include "main.h"

/**
* check_prime - Recursively checks if a number is prime
* @n: The number to check
* @divisor: The current divisor to test
* Return: 1 if n is prime, 0 otherwise
*/
int check_prime(int n, int divisor)
{
if (n < 2)
return (0);
if (divisor == n)
return (1);
if (n % divisor == 0)
return (0);
return (check_prime(n, divisor + 1));
}

/**
* is_prime_number - Returns 1 if the number is a prime number, otherwise 0
* @n: The number to check
* Return: 1 if n is prime, 0 otherwise
*/
int is_prime_number(int n)
{
return (check_prime(n, 2));
}

