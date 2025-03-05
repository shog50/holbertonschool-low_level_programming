#include "main.h"

/**
* _strlen_rec - Computes the length of a string recursively
* @s: The string to measure
* Return: The length of the string
*/
int _strlen_rec(char *s)
{
if (*s == '\0')
return (0);
return (1 + _strlen_rec(s + 1));
}

/**
* _check_palindrome - Recursively checks if a string is a palindrome
* @s: The string to check
* @start: The starting index
* @end: The ending index
* Return: 1 if the string is a palindrome, 0 otherwise
*/
int _check_palindrome(char *s, int start, int end)
{
if (start >= end)
return (1);
if (s[start] != s[end])
return (0);
return (_check_palindrome(s, start + 1, end - 1));
}

/**
* is_palindrome - Returns 1 if a string is a palindrome, 0 otherwise
* @s: The string to check
* Return: 1 if the string is a palindrome, 0 otherwise
*/
int is_palindrome(char *s)
{
if (*s == '\0')
return (1);
return (_check_palindrome(s, 0, _strlen_rec(s) - 1));
}

