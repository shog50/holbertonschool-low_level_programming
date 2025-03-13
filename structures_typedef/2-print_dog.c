#include <stdio.h>
#include "dog.h"

/**
* print_dog - prints a struct dog
* @d: pointer to a struct dog
* Description: This function prints the details of a struct dog. If any
* member is NULL, it prints (nil). If d is NULL, it does nothing.
*/
void print_dog(struct dog *d)
{
if (d == NULL)
return;

/* Check each member and print accordingly */
printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
printf("Age: %.6f\n", d->age);
printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}

