#include <stdio.h>
#include "lists.h"

/**
* print_dlistint - Prints all the elements of a dlistint_t list.
* @h: A pointer to the head of the dlistint_t list.
* Return: The number of nodes in the list.
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t count = 0;

while (h != NULL)
{
printf("%d\n", h->n); /* Print the integer data stored in the node */
count++;              /* Increment the count for each node */
h = h->next;          /* Move to the next node in the list */
}

return (count); /* Return the total number of nodes */
}

