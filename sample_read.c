#include "sample_read.h"

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
	file_name = "cube.ssv";
	printf("Reading the file %s\n", file_name);

	FILE *fp;
	fp = fopen(file_name, "r");

	unsigned int data_length;
	fread(&data_length, sizeof(unsigned int), 1, fp);
	
	struct quad object[data_length];
	fread(&object, sizeof(struct quad)*data_length, 1, fp);

	
	for (int i = 0; i < data_length; i += 1) {
		printf("Quad %d of %d\n", i + 1, data_length);

		for (int ii = 0; ii < 4; ii += 1) {
			printf("\tVertex %d, (%d, %d, %d)\n", ii, object[i].x[ii], object[i].y[ii], object[i].z[ii]);
		}
	}

	fclose(fp);
	return 0;
}
