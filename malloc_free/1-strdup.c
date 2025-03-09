#include <stdlib.h>
#include "main.h"

/**
* _strdup - Returns a pointer to a newly allocated space in memory,
*which contains a copy of the string given as a parameter.
* @str: The string to duplicate.
* Return: Pointer to the duplicated string, or NULL if insufficient memory
* or if str is NULL.
*/
char *_strdup(char *str)
{
char *dup;
unsigned int i, len = 0;

if (str == NULL)
return (NULL);

/* Calculate the length of the input string */
while (str[len] != '\0')
len++;

/* Allocate memory for the new string, including the null terminator */
dup = malloc(sizeof(char) * (len + 1));
if (dup == NULL)
return (NULL);

/* Copy the string to the newly allocated memory */
for (i = 0; i < len; i++)
dup[i] = str[i];
dup[len] = '\0'; /* Null-terminate the string */

return (dup);
}

