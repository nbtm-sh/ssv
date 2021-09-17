#include "obj.h"

enum type {
	COL = 1,
	NOCOL = 2
};

struct quad {
	int x[4];
	int y[4];
	int z[4];

	enum type type;
	unsigned int texture;
};

struct vertice {
	int x;
	int y;
	int z;
};

int next_char_pointer(char *content, int current_offset, int lim, char delim) {
	// Returns the index of the next newline char
	int i = 0;
	
	while ((*(content + current_offset + i) != delim) && i + current_offset < lim) {
		i += 1;
	}	

	return current_offset + i;
};

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("No infile or outfile supplied");
		return 0;
	}
	in_file = argv[1];
	out_file = argv[2];	
	
	printf("Read: %s. Write: %s\n", in_file, out_file);

	// Allocate buffer for file size
	FILE *fp;
	fp = fopen(in_file, "r");

	if (fp == NULL) {
		perror("Failed to open infile");
		return 0;
	}

	fseek(fp, 0L, SEEK_END);
	int file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	printf("%s %d bytes long\n", in_file, file_size);
	char fp_content[file_size];

	fread(&fp_content, file_size, 1, fp);

	// Count vertexes
	int vertex_count = 0;
	int offset = 0;

	while (offset < file_size) {
		int line_size = next_char_pointer((char *) &fp_content, offset, file_size, (char) *"\n");
		line_size -= offset;

		char *line = (char*) malloc(line_size + 2);
		memset(line, '\x00', line_size);
		memcpy(line, (char *) &fp_content[offset], line_size);
		
		if (line[0] == *"v" && line[1] == *" ") {
			vertex_count += 1;
		}

		free(line);
		offset += line_size + 1;
	}
	printf("%d\n", vertex_count);

	// Allocate the array for the vertices
	struct vertice object_vertices[vertex_count];
	offset = 0;
	int vertex_i = 0;

	while (offset < file_size) {
		int line_size = next_char_pointer((char *) &fp_content, offset, file_size, (char) *"\n");
		line_size -= offset;

		char *line = (char*) malloc(line_size + 2);
		memset(line, '\x00', line_size);
		memcpy(line, (char *) &fp_content[offset], line_size);
		
		if (line[0] == *"v" && line[1] == *" ") {
			// Interperate vertex
			int col_offset = 2;
			int v_size;

			v_size = next_char_pointer((char*) &fp_content, offset + col_offset, file_size, (char) *" "); 			
			v_size -= offset;
			v_size -= col_offset;

			char *x_str = (char*) malloc(v_size + 2);
			memset(x_str, '\x00', v_size);
			memcpy(x_str, (char*) &fp_content[offset + col_offset], v_size);
			object_vertices[0].x = atoi(x_str);
			free(x_str);
			printf("%d\n", object_vertices[0].x);
		}

		free(line);
		offset += line_size + 1;
	}
}
