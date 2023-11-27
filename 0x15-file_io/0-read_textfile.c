#include "main.h"

/**
 * read_textfile - function that reads a text file
 *	and prints it to the POSIX standard output.
 * @filename: name of the file
 * @letters: number of letters it should read and print
 * Return: number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fileDesc;
	char *buff;
	ssize_t bytesR, bytesW;

	if (filename == NULL)
		return (0);

	fileDesc = open(filename, O_RDONLY);
	if (fileDesc == -1)
		return (0);

	buff = (char *)malloc(sizeof(char) * (letters + 1));
	if (buff == NULL)
	{
		close(fileDesc);
		return (0);
	}
	bytesR = read(fileDesc, buff, letters);
	if (bytesR == -1)
	{
		free(buff);
		close(fileDesc);
		return (0);
	}
	buff[bytesR] = '\0';
	bytesW = write(STDOUT_FILENO, buff, bytesR);
	if (bytesW == -1 || bytesW != bytesR)
	{
		free(buff);
		close(fileDesc);
		return (0);
	}
	free(buff);
	close(fileDesc);
	return (bytesR);
}
