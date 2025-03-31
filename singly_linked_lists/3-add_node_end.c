#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node_end - Adds a new node at the end of a list_t list.
* @head: Double pointer to the head of the list_t list.
* @str: The string to be duplicated and added to the new node.
* Return: The address of the new element, or NULL if it failed.
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node, *temp;
char *dup_str;
unsigned int len = 0;

if (str == NULL)
return (NULL);

dup_str = strdup(str); /* Duplicate the string */
if (dup_str == NULL)
return (NULL);

while (str[len]) /* Calculate string length */
len++;

new_node = malloc(sizeof(list_t)); /* Allocate memory for the new node */
if (new_node == NULL)
{
free(dup_str);
return (NULL);
}

new_node->str = dup_str;
new_node->len = len;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
temp = *head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = new_node;
}

return (new_node);
}

