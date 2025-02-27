#include "main.h"
#include <stdio.h>

char *rot13(char *str)
{
char *p = str;
char alph[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
int i;

while (*p)
{
for (i = 0; i < 52; i++)
{
if (*p == alph[i])
{
*p = rot13[i];
break;
}
}
p++;
}
return (str);
}

