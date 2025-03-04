#include "main.h"

/**
* _pow_recursion - Returns the value of x raised to the power of y
* @x: The base value
* @y: The exponent
* Return: The result of x raised to the power of y
* -1 if y is less than 0 (indicating an error)
*/
int _pow_recursion(int x, int y)
{
if (y < 0)
return (-1);
if (y == 0)
return (1);
return (x * _pow_recursion(x, y - 1));
}

