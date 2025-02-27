#include <stdio.h>

int main(void)
{
int n;
int a[5];
int *p;

a[2] = 1024;
p = &n;

/*
* Add one line to this code so that it prints a[2] = 98, 
* followed by a new line.
*/
*(p + 5) = 98;
printf("a[2] = %d\n", a[2]);
return (0);
}

