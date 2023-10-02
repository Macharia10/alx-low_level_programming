#include "main.h"


/**
 * main - Copy the content of one file to another file.
 * @argc: number of command-line arguments.
 * @argv: array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int res;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	res = copy_file(argv[1], argv[2]);
	if (res == 98)
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	else if (res == 99)
		dprintf(2, "Error: Can't write to file %s\n", argv[2]);
	else if (res == 100)
		dprintf(2, "Error: Can't close file descriptor\n");

	return (res);
}

/**
 * copy_file - Copy the content of one file to another file.
 * @src_filename: source filename.
 * @dest_filename: destination filename.
 *
 * Return: 0 on success, or an error code on failure.
 */
int copy_file(const char *src, const char *dest)
{
	int fd_from, fd_to;
	char buffer[BUFFSIZE];
	ssize_t r_bytes, w_bytes;

	fd_from = open(src, O_RDONLY);
	if (fd_from == -1)
		return (98);

	fd_to = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		return (99);
	}

	while ((r_bytes = read(fd_from, buffer, BUFFSIZE)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes == -1 || w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (r_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		return (98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
		return (100);

	return (0);
}
/**
 * print_type - prints type
 * @ptr: magic.
 * Return: no return.
 */
void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}
