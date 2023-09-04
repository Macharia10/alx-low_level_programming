#include <elf.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * print_magic - print the efl magic bytes
 * @magic: pointer to efl bytes.
 */
void print_magic(unsigned char *magic)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", magic[i]);
	}
	printf("\n");
}

/**
 * print_elf_header_info - print the header information
 * @header: pointer to efl structure
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	printf("  Class:                             %s\n",
			header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "unknown");
	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
		switch (header->e_type)
		{
			case ET_NONE:
				printf("NONE (No file type)\n");
				break;
			case ET_REL:
				printf("REL (Relocatable file)\n");
				break;
			case ET_EXEC:
				printf("EXEC (Executable file)\n");
				break;
			case ET_DYN:
				printf("DYN (Shared object file)\n");
				break;
			case ET_CORE:
				printf("CORE (Core file)\n");
				break;
			default:
				printf("unknown\n");
				break;
		}
	printf("  Entry point address:               0x%lx\n",
			(unsigned long)header->e_entry);
}

/**
 * read_elf_header - read and validate
 * @fd: file descriptor of the file
 * @header: pointer to the header structure
 *
 * Return: 1 if efl successful
 */
int read_elf_header(int fd, Elf64_Ehdr *header)
{
	ssize_t n = read(fd, header, sizeof(Elf64_Ehdr));

	if (n == -1)
	{
		perror("Error reading ELF header");
		return (0);
	}

	if (n != sizeof(Elf64_Ehdr) || memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		return (0);
	}

	return (1);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr elf_header;
	const char *elf_filename;
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	elf_filename = argv[1];
	fd = open(elf_filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}
	if (read_elf_header(fd, &elf_header))
	{
		printf("ELF Header:\n");
		print_magic(elf_header.e_ident);
		print_elf_header_info(&elf_header);
	}

	close(fd);
	return (0);
}
