#include "main.h"

/**
 * print_out_error_and_exit - prints an error message to stderr
 *	and exits with status code 98
 * @msg: error message to be printed
 */
void print_out_error_and_exit(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header_info - prints information from the ELF header
 * @header: pointer to the ELF header structure
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:	%s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ?
			"ELF64" : "ELF32");
	printf("  Data:	%s\n", header->e_ident[EI_DATA] == ELFDATA2MSB ?
			"2's complement, big endian" :
			"2's complement, little endian");
	printf("  Version:	%d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:	%d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version:	%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:		%s\n",
			header->e_type == ET_REL ? "REL (Relocatable file)" :
			(header->e_type == ET_EXEC ? "EXEC (Executable file)" :
			 (header->e_type == ET_DYN ? "DYN (Shared object file)" :
			  (header->e_type == ET_CORE ? "CORE (Core file)" : "Unknown"))));
	printf("  Entry point address:		0x%lx\n", header->e_entry);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_out_error_and_exit("Error: Unable to open file");
	}

	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr) ||
			memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_out_error_and_exit("Error: Not an ELF file");
	}

	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}
