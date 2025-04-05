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
* copy_content - Copies content from one file descriptor to another.
* @fd_from: Source file descriptor.
* @fd_to: Destination file descriptor.
* @src: Source file name.
* @dest: Destination file name.
*/
void copy_content(int fd_from, int fd_to, char *src, char *dest)
{
ssize_t rd, wr;
char buffer[BUFFER_SIZE];

while ((rd = read(fd_from, buffer, sizeof(buffer))) > 0)
{
wr = write(fd_to, buffer, rd);
if (wr < 0 || wr != rd)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", dest);
close(fd_from);
close(fd_to);
exit(99);
}
}

if (rd < 0)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", src);
close(fd_from);
close(fd_to);
exit(98);
}
}

/**
* main - Copies the content of a file to another file.
* @argc: The number of arguments passed to the program.
* @argv: The argument vector.
*
* Return: 0 on success, or an exit code on failure.
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

fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_file(fd_from);
exit(99);
}

copy_content(fd_from, fd_to, argv[1], argv[2]);

close_file(fd_from);
close_file(fd_to);

return (0);
}

