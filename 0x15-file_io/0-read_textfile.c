#include "main.h"

/**
 * read_textfile - funct to Read and print the contents of a file to stdout.
 * @filename: name of the file to read.
 * @letters: number of letters to read and print.
 *
 * Return: The number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int d;
	ssize_t bytes_r, bytes_w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
		return (0);


	d = open(filename, O_RDONLY);
	if (d == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_r = read(d, buffer, letters);
	if (bytes_r == -1)
	{
		free(buffer);
		close(d);
		return (0);
	}
	bytes_w = write(STDOUT_FILENO, buffer, bytes_r);
	if (bytes_w == -1 || bytes_w != bytes_r)
	{
		free(buffer);
		close(d);
		return (0);
	}

	/* Cleanup and return the number of bytes written */
	free(buffer);
	close(d);
	return (bytes_w);
}
