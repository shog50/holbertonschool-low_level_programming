#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: The name of the file to append to.
* @text_content: The NULL-terminated string to add at the end of the file.
*
* Return: 1 on success, -1 on failure.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, written_bytes, length = 0;

if (filename == NULL)
return (-1);

/* Open the file in append mode */
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

/* If text_content is not NULL, write it to the file */
if (text_content != NULL)
{
while (text_content[length]) /* Calculate the length of text_content */
length++;

written_bytes = write(fd, text_content, length);
if (written_bytes == -1)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

