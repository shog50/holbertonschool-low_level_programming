#include <stdlib.h>
#include "main.h"

/**
* word_count - Counts the number of words in a string.
* @str: The input string.
* Return: Number of words in the string.
*/
int word_count(char *str)
{
int count = 0, i = 0;

while (str[i])
{
if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
count++;
i++;
}
return (count);
}

/**
* word_length - Finds the length of the next word in the string.
* @str: The input string.
* Return: The length of the word.
*/
int word_length(char *str)
{
int length = 0;

while (str[length] != ' ' && str[length] != '\0')
length++;
return (length);
}

/**
* strtow - Splits a string into words.
* @str: The input string.
* Return: Pointer to an array of strings (words),
*         or NULL if str == NULL, str == "" or if memory allocation fails.
*/
char **strtow(char *str)
{
char **words;
int i, j, k = 0, len, wc;

if (str == NULL || *str == '\0')
return (NULL);

wc = word_count(str); /* Count the number of words */
if (wc == 0)
return (NULL);

words = malloc(sizeof(char *) * (wc + 1)); /* Allocate memory for words array */
if (words == NULL)
return (NULL);

for (i = 0; str[i] && k < wc; i++)
{
if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
{
len = word_length(&str[i]);
words[k] = malloc(sizeof(char) * (len + 1)); /* Allocate memory for the word */
if (words[k] == NULL)
{
for (j = 0; j < k; j++) /* Free previously allocated memory on failure */
free(words[j]);
free(words);
return (NULL);
}

for (j = 0; j < len; j++) /* Copy characters of the word */
words[k][j] = str[i + j];
words[k][j] = '\0'; /* Null-terminate the word */
k++;
i += len - 1; /* Move index to the end of the word */
}
}
words[k] = NULL; /* Null-terminate the array of words */
return (words);
}

