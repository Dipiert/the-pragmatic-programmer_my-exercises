#include "tpp11.h"
#define BUFFER_SIZE 255

int main() {
	write_h_file();
	write_c_file();
}

void write_h_file() {
	FILE* in, *h;
	char buffer[BUFFER_SIZE];
	char* str_head = "extern const char* %s_names[];\ntypedef enum {\n";
	in = fopen("in", "r"); 
	h = fopen("name.h", "w");
	if (h == NULL || in == NULL) {
		printf("Error opening file.\n");
		exit(1);
	}	
	char* first_line = str_toupper(strdup(strtok(fgets(buffer, BUFFER_SIZE, (FILE*) in), "\n")));	
    write_head(str_head, h, "%s", first_line);
    write_lines(buffer, h, in, "\t%s,\n");
    write_tail(first_line, h, "} %s;");
	fclose(h);
	fclose(in);
}

void write_c_file() {
	FILE* in, *c;
	char buffer[BUFFER_SIZE];
	char* str_head = "const char* %s_names[] = {";
	in = fopen("in", "r"); 
	c = fopen("name.c", "w");
	if (c == NULL || in == NULL) {
		printf("Error opening file.\n");
		exit(1);
	}	
	char* first_line = str_toupper(strdup(strtok(fgets(buffer, BUFFER_SIZE, (FILE*) in), "\n")));
	write_head(str_head, c, "%s\n", first_line);
	write_lines(buffer, c, in, "\t\"%s\",\n");
	write_tail(first_line, c, "};");
	fclose(c);
	fclose(in);
}

void write_head(char* str, FILE* fp, char* format, char* first_line) {
	char* head = malloc(BUFFER_SIZE);
	sprintf(head,str,first_line);
	fprintf(fp, format, head);
}

void write_lines(char buffer[], FILE* fp, FILE* in, char* format) {
	while(fgets(buffer, BUFFER_SIZE, (FILE*) in))	
		fprintf(fp, format, strtok(buffer, "\n"));		
}

void write_tail(char* first_line, FILE* fp, char* format) {
	char* tail = malloc(BUFFER_SIZE);
	sprintf(tail, format, first_line);
	fprintf(fp, "%s", tail);
}

char* str_toupper(char* str) {
   size_t str_size = strlen(str);
   int index = 0;
   char* upp_str = malloc(str_size);
   strncpy(upp_str, str, str_size);
   upp_str[str_size] = '\0';
   while(upp_str[index]) {
      upp_str[index] = toupper(str[index]);
      index++;
   }
   return upp_str;
}
