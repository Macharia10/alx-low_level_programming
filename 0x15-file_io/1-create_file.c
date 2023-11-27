#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: name of file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fileDesc;
	ssize_t bytesW;

	if (filename == NULL)
		return (-1);

	fileDesc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDesc == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytesW = write(fileDesc, text_content, strlen(text_content));
		if (bytesW == -1 || (size_t)bytesW != strlen(text_content))
		{
			close(fileDesc);
			return (-1);
		}
	}
	close(fileDesc);
	return (1);
}
