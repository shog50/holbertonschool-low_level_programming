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
* word_length - Finds the length of a word in a string.
* @str: The input string.
* Return: The length of the first word found.
*/
int word_length(char *str)
{
int length = 0;

while (str[length] != ' ' && str[length] != '\0')
length++;
return (length);
}

/**
* allocate_words - Allocates memory for the words in the array.
* @str: The input string.
* @words: The pointer to the array of words.
* @wc: The number of words.
* Return: 1 on success, 0 on failure.
*/
int allocate_words(char *str, char **words, int wc)
{
int i = 0, j = 0, len, word_start;

while (str[i] && j < wc)
{
if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
{
word_start = i;
len = word_length(&str[i]);

words[j] = malloc(sizeof(char) * (len + 1));
if (words[j] == NULL)
{
for (int k = 0; k < j; k++)
free(words[k]);
return (0);
}

for (int k = 0; k < len; k++)
words[j][k] = str[word_start + k];
words[j][len] = '\0';

j++;
i += len - 1; /* Skip to the end of the word */
}
i++;
}
return (1);
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
int wc;

if (str == NULL || *str == '\0')
return (NULL);

wc = word_count(str);
if (wc == 0)
return (NULL);

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
return (NULL);

if (!allocate_words(str, words, wc))
{
free(words);
return (NULL);
}

words[wc] = NULL;
return (words);
}

