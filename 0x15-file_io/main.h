#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <elf.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFSIZE 1024

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void copy_file(const char *file_from, const char *file_to);
void error_exit(int code, const char *message);
int main(int argc, char *argv[]);


void check_sys(char *ptr);
int check_elf(char *ptr);
void print_addr(char *ptr);
void print_type(char *ptr);
void print_osabi(char *ptr);
void print_version(char *ptr);
void print_data(char *ptr);
void print_magic(char *ptr);


#endif
