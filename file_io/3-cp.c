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
* open_file - Opens a file and handles errors.
* @filename: The name of the file to open.
* @flags: The flags for opening the file.
* @mode: The file mode (permissions).
*
* Return: The file descriptor.
*/
int open_file(const char *filename, int flags, mode_t mode)
{
int fd = open(filename, flags, mode);

if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't %s file %s\n",
(flags & O_RDONLY) ? "read from" : "write to", filename);
exit((flags & O_RDONLY) ? 98 : 99);
}
return (fd);
}

/**
* copy_content - Copies data from one file descriptor to another.
* @fd_from: The file descriptor for the source file.
* @fd_to: The file descriptor for the destination file.
*/
void copy_content(int fd_from, int fd_to)
{
char buffer[BUFFER_SIZE];
ssize_t read_bytes, written_bytes;

while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
written_bytes = write(fd_to, buffer, read_bytes);
if (written_bytes == -1 || written_bytes != read_bytes)
{
dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
close_file(fd_from);
close_file(fd_to);
exit(99);
}
}
if (read_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
close_file(fd_from);
close_file(fd_to);
exit(98);
}
}

/**
* main - Copies the content of one file to another.
* @argc: The number of arguments.
* @argv: The array of arguments.
*
* Return: 0 on success, or exits with error codes on failure.
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;

/* Validate argument count */
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/* Open files */
fd_from = open_file(argv[1], O_RDONLY, 0);
fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

/* Copy content */
copy_content(fd_from, fd_to);

/* Close files */
close_file(fd_from);
close_file(fd_to);

return (0);
}

