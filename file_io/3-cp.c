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
/* Write the bytes read to the destination file */
written_bytes = write(fd_to, buffer, read_bytes);
if (written_bytes == -1 || written_bytes != read_bytes)
{
dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
close_file(fd_from);
close_file(fd_to);
exit(99);
}
}

/* Handle errors in the read operation */
if (read_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
close_file(fd_from);
close_file(fd_to);
exit(98);
}
}

/**
* main - Entry point, copies the content of one file to another.
* @argc: The number of arguments provided to the program.
* @argv: The arguments array.
*
* Return: 0 on success, or exits with appropriate error codes on failure.
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
void copy_content(int fd_from, int fd_to)
{
char buffer[BUFFER_SIZE];
ssize_t read_bytes, written_bytes;

/* Read from source and write to destination */
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

/* Check for read errors */
if (read_bytes == -1) /* If an error occurred during read */
{
dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
close_file(fd_from);
close_file(fd_to);
exit(98);
}
}

