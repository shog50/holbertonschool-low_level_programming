#ifndef DOG_H
#define DOG_H

/**
* struct dog - structure to store a dog's information
* @name: the name of the dog (type: char *)
* @age: the age of the dog (type: float)
* @owner: the owner of the dog (type: char *)
* Description: A structure to hold a dog's basic details, including
* its name, age, and owner's name.
*/
struct dog
{
char *name;
float age;
char *owner;
};

#endif /* DOG_H */

