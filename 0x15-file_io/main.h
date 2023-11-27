#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void print_error_and_exit(int code, const char *msg, const char *filename, int fd);
int main(int argc, char *argv[]);
void print_out_error_and_exit(const char *msg);
void print_elf_header_info(Elf64_Ehdr *header);


#endif
