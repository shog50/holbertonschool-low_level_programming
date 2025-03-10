#include <stdlib.h>
#include "main.h"

/**
* alloc_grid - Returns a pointer to a 2D array of integers.
* @width: The width of the grid (number of columns).
* @height: The height of the grid (number of rows).
* Return: Pointer to the 2D array, or NULL on failure or if width/height <= 0.
*/
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;

if (width <= 0 || height <= 0)
return (NULL);

/* Allocate memory for rows (pointers to int arrays) */
grid = malloc(sizeof(int *) * height);
if (grid == NULL)
return (NULL);

/* Allocate memory for each row and initialize elements to 0 */
for (i = 0; i < height; i++)
{
grid[i] = malloc(sizeof(int) * width);
if (grid[i] == NULL)
{
/* Free previously allocated rows to avoid memory leaks */
for (j = 0; j < i; j++)
free(grid[j]);
free(grid);
return (NULL);
}
for (j = 0; j < width; j++)
grid[i][j] = 0;
}

return (grid);
}

