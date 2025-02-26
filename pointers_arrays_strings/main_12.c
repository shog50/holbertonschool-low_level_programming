#include "main.h"
#include <stdio.h>

/**
* main - check the code for _atoi function.
*
* Return: Always 0.
*/
int main(void)
{
int nb;

nb = _atoi("-2147483648");  /* Test case for INT_MIN */
printf("%d\n", nb);
return (0);
}

