#include "main.h"
#include <unistd.h>
#include <string.h>

/**
* print_times_table - prints the n times table, starting with 0
* @n: the number for the times table
*/
void print_times_table(int n)
{
int i, j, result;
char buffer[4];

if (n < 0 || n > 15)
return;

for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
result = i * j;

if (j != 0)
write(1, ",", 1);

if (result < 10)
{
if (j != 0)
write(1, "   ", 3);
buffer[0] = result + '0';
buffer[1] = '\0';
}
else if (result < 100)
{
if (j != 0)
write(1, "  ", 2);
buffer[0] = (result / 10) + '0';
buffer[1] = (result % 10) + '0';
buffer[2] = '\0';
}
else
{
if (j != 0)
write(1, " ", 1);
buffer[0] = (result / 100) + '0';
buffer[1] = ((result / 10) % 10) + '0';
buffer[2] = (result % 10) + '0';
buffer[3] = '\0';
}

write(1, buffer, strlen(buffer));
}
write(1, "\n", 1);
}
}

