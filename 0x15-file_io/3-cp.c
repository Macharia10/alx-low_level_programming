#include "main.h"

/**
 * copy_file - Copies content from one file to another.
 *
 * @file_from: Source file name
 * @file_to: Destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytesR, bytesW;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		exit(99);
	}
	while ((bytesR = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytesW = write(fd_to, buffer, bytesR);
		if (bytesW != bytesR)
		{
			dprintf(STDERR_FILENO, "Error: Incomplete write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (bytesR == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		exit(100);
	}
	if (chmod(file_to, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't set file permissions\n");
		exit(101);
	}
}
/**
 * main - Entry point of the program.
 *
 * @argc: param argc Number of command-line arguments
 * @argv: param argv Array of command-line argument strings
 * Return: 0 on successful execution, otherwise exits with specific error codes
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	copy_file(argv[1], argv[2]);

	return (0);
}

