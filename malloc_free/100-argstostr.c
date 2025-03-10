#include <stdlib.h>
#include "main.h"

/**
* argstostr - Concatenates all the arguments of a program into a single string.
* @ac: The number of arguments.
* @av: The array of arguments.
* Return: Pointer to the concatenated string, or NULL on failure.
*/
char *argstostr(int ac, char **av)
{
char *str;
int i, j, k = 0, total_length = 0;

if (ac == 0 || av == NULL)
return (NULL);

/* Calculate the total length of the concatenated string */
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
total_length++;
total_length++; /* Account for '\n' */
}

/* Allocate memory for the new string */
str = malloc(sizeof(char) * (total_length + 1));
if (str == NULL)
return (NULL);

/* Copy each argument into the new string, followed by '\n' */
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
{
str[k] = av[i][j];
k++;
}
str[k] = '\n'; /* Add '\n' after each argument */
k++;
}

str[k] = '\0'; /* Null-terminate the string */
return (str);
}

