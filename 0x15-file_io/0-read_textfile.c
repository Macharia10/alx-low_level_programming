#include "main.h"

/**
 * read_textfile - function that reads a text file and prints it to the
 * POSIX standard output.
 *
 * @filename: name of the file
 * @letters: number of letters in the file
 *
 * Return: the actual number of letters it could read and print, else return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = (char *)malloc(letters + 1);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	bytes_read = fread(buffer, sizeof(char), letters, file);
	if (bytes_read < 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	buffer[bytes_read] = '\0';

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	fclose(file);
	free(buffer);

	if (bytes_written < 0 || (size_t)bytes_written != (size_t)bytes_read)
	{
		return (0);
	}
	return (bytes_read);
}
