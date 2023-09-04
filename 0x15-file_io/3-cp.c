#include "main.h"

void error_and_exit(const char *msg, char *buf, int fd1, int fd2)
{
	free(buf);
	if (fd1 != -1)
		close(fd1);

	if (fd2 != -1)
		close(fd2);

	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(1);
}

int copy_file(const char *file_to, const char *file_from)
{
	int to = -1, from = -1;
	char *buf = malloc(1024);
	ssize_t re, wr;


	if (!buf)
		error_and_exit("Error: Memory allocation failed", NULL, -1, -1);
	from = open(file_from, O_RDONLY);
	if (from == -1)
		error_and_exit("Error: Can't read from file", buf, -1, -1);

	to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
		error_and_exit("Error: Can't write to file", buf, from, -1);

	re = 0, wr = 0;
	while ((re = read(from, buf, 1024)) > 0)
	{
		if ((wr = write(to, buf, re)) == -1)
			error_and_exit("Error: Can't write to file", buf, from, to);

	}
	if (re == -1)
		error_and_exit("Error: Can't read from file", buf, from, to);
	
	close(from);
	close(to);
	free(buf);

	return (0);
}
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	}

	if (copy_file(argv[2], argv[1]) != 0)
		return (1);

	return (0);
}
