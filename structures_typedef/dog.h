#ifndef DOG_H
#define DOG_H

#include <stddef.h> /* For NULL */

/**
* struct dog - structure to store a dog's information
* @name: the name of the dog
* @age: the age of the dog
* @owner: the owner of the dog
*/
struct dog
{
char *name;
float age;
char *owner;
};

/* Typedef for struct dog */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */

