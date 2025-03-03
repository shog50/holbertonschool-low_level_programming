#include "main.h"
#include <stddef.h>

/**
* _strstr - Finds the first occurrence of the substring needle
* in the string haystack
* @haystack: The main C string to be scanned
* @needle: The small string to be searched with-in haystack string
* Return: A pointer to the beginning of the located substring,
* or NULL if the substring is not found
*/
char *_strstr(char *haystack, char *needle)
{
int i, j;

if (*needle == '\0')
return (haystack);

for (i = 0; haystack[i] != '\0'; i++)
{
for (j = 0; needle[j] != '\0'; j++)
{
if (haystack[i + j] != needle[j])
break;
}
if (needle[j] == '\0')
return (&haystack[i]);
}

return (NULL);
}

