#include "main.h"

/**
 * error_exit - Print an error message and exit with the specified code.
 * @code: The exit code.
 * @message: The error message to display.
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(code);
}

/**
 * copy_file - Copy the content of one file to another.
 * @file_from: The source file path.
 * @file_to: The destination file path.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	/* Open the source file for reading*/
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Can't read from file");

	/* Open or create the destination file*/
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
		error_exit(99, "Can't write to file");

	/* Copy data from source to destination using a buffer*/
	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_exit(99, "Can't write to file");
	}
	if (bytes_read == -1)
		error_exit(98, "Can't read from file");

	/* Close both files and check for errors*/
	if (close(fd_from) == -1)
		error_exit(100, "Can't close fd");

	if (close(fd_to) == -1)
		error_exit(100, "Can't close fd");
}

/**
 * main - The main entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, other values on error.
 */
int main(int argc, char *argv[])
{
	const char *file_from, *file_to;

	/* Check the number of arguments*/
	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to");
	}

	/* Get the source and destination file paths from command line arguments*/
	file_from = argv[1];
	file_to = argv[2];

	/* Copy the content of the source file to the destination file */
	copy_file(file_from, file_to);

	return (0);
}
