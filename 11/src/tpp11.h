#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *strdup(const char *s);
char* str_toupper(char *str);
void write_h_file();
void write_c_file();
void write_head(char* str, FILE* fp, char* format, char* first_line);
void write_lines(char buffer[], FILE* fp, FILE* in, char* format);
void write_tail(char* first_line, FILE* fp, char* format);