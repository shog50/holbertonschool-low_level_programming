#include <stdlib.h>
#include "dog.h"

int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/**
* new_dog - Creates a new dog
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
* Return: Pointer to the new dog (dog_t), or NULL if it fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *max_dog;
int name_l = 0, own_l = 0;

if (name == NULL || owner == NULL)
return (NULL);

name_l = _strlen(name) + 1;
own_l = _strlen(owner) + 1;

/* Allocate memory for the dog structure */
max_dog = malloc(sizeof(dog_t));
if (max_dog == NULL)
return (NULL);

/* Allocate memory for name */
max_dog->name = malloc(sizeof(char) * name_l);
if (max_dog->name == NULL)
{
free(max_dog);
return (NULL);
}

/* Allocate memory for owner */
max_dog->owner = malloc(sizeof(char) * own_l);
if (max_dog->owner == NULL)
{
free(max_dog->name);
free(max_dog);
return (NULL);
}

/* Copy name and owner */
_strcpy(max_dog->name, name);
_strcpy(max_dog->owner, owner);

/* Initialize age */
max_dog->age = age;

return (max_dog);
}

/**
* _strlen - Returns the length of a string
* @s: String to count
* Return: Length of the string
*/
int _strlen(char *s)
{
int c = 0;

for (; *s != '\0'; s++)
{
c++;
}
return (c);
}

/**
* _strcpy - Copies a string
* @dest: Destination value
* @src: Source value
* Return: Pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';

return (dest);
}

