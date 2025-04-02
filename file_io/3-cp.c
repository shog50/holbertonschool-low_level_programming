#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
* close_file - Closes a file descriptor and handles errors.
* @fd: The file descriptor to close.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - Copies the content of one file to another.
* @argc: The number of arguments provided to the program.
* @argv: The arguments array.
*
* Return: 0 on success, or exits with appropriate error codes on failure.
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to, read_bytes, written_bytes;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/* Open the source file */
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/* Open the destination file */
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_file(fd_from);
exit(99);
}

/* Read from source and write to destination */
while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
written_bytes = write(fd_to, buffer, read_bytes);
if (written_bytes == -1 || written_bytes != read_bytes)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_file(fd_from);
close_file(fd_to);
exit(99);
}
}

if (read_bytes == -1) /* Check if read encountered an error */
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close_file(fd_from);
close_file(fd_to);
exit(98);
}

/* Close both file descriptors */
close_file(fd_from);
close_file(fd_to);

return (0);
}

