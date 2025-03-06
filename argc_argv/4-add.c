#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
* is_number - Checks if a string contains only digits
* @str: The string to check
* Return: 1 if the string is a number, 0 otherwise
*/
int is_number(char *str)
{
while (*str)
{
if (!isdigit(*str))
return (0);
str++;
}
return (1);
}

/**
* main - Adds positive numbers
* @argc: Argument count
* @argv: Array of argument strings
* Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
int i, sum = 0;

if (argc == 1)
{
printf("0\n");
return (0);
}

for (i = 1; i < argc; i++)
{
if (!is_number(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}

printf("%d\n", sum);
return (0);
}

