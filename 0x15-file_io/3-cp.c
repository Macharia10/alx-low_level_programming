#include "main.h"

/**
 * print_error_and_exit - Prints an error message and exits the program
 * @code: The exit code to use
 * @msg: The error message to print
 * @filename: The name of the file associated with the error
 * @fd: File descriptor to close (if necessary)
 */
void print_error_and_exit(int code, const char *msg,
		const char *filename, int fd)
{
	if (fd != -1)
		close(fd);
	dprintf(STDERR_FILENO, "%s %s\n", msg, filename);
	exit(code);
}

/**
 * main - Copies the content of one file to another file
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * Return: 0 on success, appropriate error code otherwise
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		print_error_and_exit(98, "Error: Can't read from file", argv[1], -1);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file_to == -1)
		print_error_and_exit(99, "Error: Can't write to file",
				argv[2], file_from);

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			print_error_and_exit(99, "Error: Can't write to file",
					argv[2], file_from);
	}

	if (bytes_read == -1)
		print_error_and_exit(98, "Error: Can't read from file",
				argv[1], file_from);

	if (close(file_from) == -1 || close(file_to) == -1)
		print_error_and_exit(100, "Error: Can't close fd", "", -1);

	return (0);
}
