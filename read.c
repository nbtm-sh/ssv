#include "read.h"

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

int main() {
	file_name = "out.bin";

	FILE *fp;
	fp = fopen(file_name, "r");

	if (fp == NULL) {
		printf("File not found.");
		return 0;
	}

	unsigned int data_length;
	fread(&data_length, sizeof(unsigned int), 1, fp);

	struct quad object[data_length];
	fread(&object, sizeof(struct quad)*data_length, 1, fp);

	// Object is now loaded into memory.	
	printf("First vertex: (%d, %d, %d)", object[0].x[0], object[0].y[0], object[0].z[0]);
}
