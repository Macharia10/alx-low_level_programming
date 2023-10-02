#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: name of the file to which to append the text.
 * @text_content: text to append to the file.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, length, bytes_w;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length] != '\0'; length++)
			continue;

		bytes_w = write(fd, text_content, length);
		if (bytes_w == -1 || bytes_w != length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

