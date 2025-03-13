#include <stdlib.h>
#include "dog.h"

/**
* free_dog - Frees memory allocated for a dog_t structure
* @d: Pointer to the dog_t structure to free
*/
void free_dog(dog_t *d)
{
if (d == NULL)
return;

/* Free the dynamically allocated name and owner */
free(d->name);
free(d->owner);

/* Free the structure itself */
free(d);
}

