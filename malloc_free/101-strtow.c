#include <stdlib.h>
#include "main.h"

/**
* word_count - Counts the number of words in a string.
* @str: The input string.
* Return: The number of words in the string.
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
* strtow - Splits a string into words.
* @str: The input string.
* Return: Pointer to an array of strings (words),
*         or NULL if str == NULL, str == "" or the function fails.
*/
char **strtow(char *str)
{
char **words;
int i, j, k, len = 0, wc, word_start;

if (str == NULL || *str == '\0')
return (NULL);

wc = word_count(str);
if (wc == 0)
return (NULL);

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
return (NULL);

k = 0;
for (i = 0; str[i]; i++)
{
if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
{
word_start = i;

len = 0;
while (str[i] != ' ' && str[i] != '\0')
{
len++;
i++;
}

words[k] = malloc(sizeof(char) * (len + 1));
if (words[k] == NULL)
{
for (j = 0; j < k; j++)
free(words[j]);
free(words);
return (NULL);
}

for (j = 0; j < len; j++)
words[k][j] = str[word_start + j];
words[k][j] = '\0';
k++;
}
}
words[k] = NULL;
return (words);
}

