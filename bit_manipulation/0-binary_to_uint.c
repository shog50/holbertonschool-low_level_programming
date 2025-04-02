#include <stddef.h>
#include "main.h"

/**
* binary_to_uint - Converts a binary number to an unsigned int.
* @b: Pointer to a string of 0 and 1 characters.
* Return: The converted number, or 0 if there's an invalid char or NULL input.
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;
int i;

if (b == NULL)
return (0);

for (i = 0; b[i] != '\0'; i++)
{
if (b[i] != '0' && b[i] != '1') /* Check for valid binary characters */
return (0);

result = (result << 1) + (b[i] - '0'); /* Bitwise operation */
}

return (result);
}

