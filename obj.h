#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

enum type; 

struct quad; 
struct vertice;
typedef unsigned int face[4];

int next_char_pointer(char *content, int current_offset, int lim, char delim);

char *out_file;
char *in_file;
int main(int argc, char *argv[]);
