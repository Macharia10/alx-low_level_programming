#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fileDesc;
	ssize_t bytesW;

	if (filename == NULL)
		return (-1);

	if (access(filename, F_OK) == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	fileDesc = open(filename, O_WRONLY | O_APPEND);
	if (fileDesc == -1)
		return (-1);

	bytesW = write(fileDesc, text_content, strlen(text_content));
	if (bytesW == -1 || (size_t)bytesW != strlen(text_content))
	{
		close(fileDesc);
		return (-1);
	}
	close(fileDesc);
	return (1);
}
