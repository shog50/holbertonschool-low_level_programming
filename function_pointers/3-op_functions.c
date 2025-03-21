#include "3-calc.h"

/**
* op_add - Returns the sum of two integers
* @a: The first integer
* @b: The second integer
* Return: The sum of a and b
*/
int op_add(int a, int b)
{
return (a + b);
}

/**
* op_sub - Returns the difference of two integers
* @a: The first integer
* @b: The second integer
* Return: The difference of a and b
*/
int op_sub(int a, int b)
{
return (a - b);
}

/**
* op_mul - Returns the product of two integers
* @a: The first integer
* @b: The second integer
* Return: The product of a and b
*/
int op_mul(int a, int b)
{
return (a * b);
}

/**
* op_div - Returns the result of the division of two integers
* @a: The first integer
* @b: The second integer
* Return: The result of the division
*         If division by zero, exits with status 100
*/
int op_div(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}
return (a / b);
}

/**
* op_mod - Returns the remainder of the division of two integers
* @a: The first integer
* @b: The second integer
* Return: The remainder of the division
*         If division by zero, exits with status 100
*/
int op_mod(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}
return (a % b);
}

