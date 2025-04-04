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
* copy_content - Copies the content from one file descriptor to another.
* @fd_from: The source file descriptor.
* @fd_to: The destination file descriptor.
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
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", "NAME_OF_THE_FILE");
close_file(fd_from);
close_file(fd_to);
exit(99);
}
}

if (read_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", "NAME_OF_THE_FILE");
close_file(fd_from);
close_file(fd_to);
exit(98);
}
}

/**
* main - Entry point to copy file content.
* @argc: Argument count.
* @argv: Argument vector.
*
* Return: 0 on success, exits with appropriate error code on failure.
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_file(fd_from);
exit(99);
}

copy_content(fd_from, fd_to);

close_file(fd_from);
close_file(fd_to);

return (0);
}

