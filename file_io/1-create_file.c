#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
* create_file - Creates a file with specific content.
* @filename: The name of the file to create.
* @text_content: NULL-terminated string to write to the file.
*
* Return: 1 on success, -1 on failure.
*/
int create_file(const char *filename, char *text_content)
{
int fd, written_bytes, length = 0;

if (filename == NULL)
return (-1);

/* Open the file with O_CREAT, O_WRONLY, O_TRUNC */
fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

/* If text_content is not NULL, write it to the file */
if (text_content != NULL)
{
while (text_content[length]) /* Get the length of text_content */
length++;

written_bytes = write(fd, text_content, length);
if (written_bytes == -1 || written_bytes != length)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

