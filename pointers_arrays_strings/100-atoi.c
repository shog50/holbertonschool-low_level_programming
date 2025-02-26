#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: the string to convert
*
* Return: the converted integer
*/
int _atoi(char *s)
{
int sign = 1;
int result = 0;
int i = 0;
int found_num = 0;


while (s[i] != '\0')
{

if (s[i] == '-' || s[i] == '+')
{
if (found_num)
break;
if (s[i] == '-')
sign *= -1;
}

else if (s[i] >= '0' && s[i] <= '9')
{
found_num = 1;

result = result * 10 + (s[i] - '0');
}
else if (found_num)
{
break;
}
i++;
}

return (sign * result);
}

