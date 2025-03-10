#include <stdlib.h>
#include "main.h"

/**
* str_concat - Concatenates two strings.
* @s1: The first string.
* @s2: The second string.
* Return: Pointer to the newly allocated memory containing the concatenated
*         string, or NULL on failure.
*/
char *str_concat(char *s1, char *s2)
{
char *concat;
unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

/* Treat NULL strings as empty strings */
if (s1 != NULL)
{
while (s1[len1] != '\0')
len1++;
}
if (s2 != NULL)
{
while (s2[len2] != '\0')
len2++;
}

/* Allocate memory for the concatenated string */
concat = malloc(sizeof(char) * (len1 + len2 + 1));
if (concat == NULL)
return (NULL);

/* Copy the contents of s1 into concat */
while (i < len1)
{
concat[i] = s1[i];
i++;
}

/* Copy the contents of s2 into concat */
while (j < len2)
{
concat[i] = s2[j];
i++;
j++;
}

concat[i] = '\0'; /* Null-terminate the new string */
return (concat);
}

