#include "write.h"

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
	// Create cube
	struct quad cube_object[6];
	// 1, 1	
	cube_object[0].x[0] = 1;
	cube_object[0].x[1] = -1;
	cube_object[0].x[2] = -1;
	cube_object[0].x[3] = 1; 
	cube_object[0].y[0] = 1;
	cube_object[0].y[1] = 1;
	cube_object[0].y[2] = 1;
	cube_object[0].y[3] = 1;
	cube_object[0].z[0] = -1;
	cube_object[0].z[1] = -1;
	cube_object[0].z[2] = 1;
	cube_object[0].z[3] = 1;
	
	cube_object[1].x[0] = 1;
	cube_object[1].x[1] = 1;
	cube_object[1].x[2] = -1;
	cube_object[1].x[3] = -1;
	cube_object[1].y[0] = -1;
	cube_object[1].y[1] = 1;
	cube_object[1].y[2] = 1;
	cube_object[1].y[3] = -1;
	cube_object[1].z[0] = 1;
	cube_object[1].z[1] = 1;
	cube_object[1].z[2] = 1;
	cube_object[1].z[4] = 1;

	cube_object[2].x[0] = -1;
	cube_object[2].x[1] = -1;
	cube_object[2].x[2] = -1;
	cube_object[2].x[3] = -1;
	cube_object[2].y[0] = -1;
	cube_object[2].y[1] = 1;
	cube_object[2].y[2] = 1;
	cube_object[2].y[3] = -1;
	cube_object[2].z[0] = 1;
	cube_object[2].z[1] = 1;
	cube_object[2].z[2] = -1;
	cube_object[2].z[3] = -1; 
	
	cube_object[3].x[0] = -1;
	cube_object[3].x[1] = 1;
	cube_object[3].x[2] = 1;
	cube_object[3].x[3] = -1;
	cube_object[3].y[0] = -1;
	cube_object[3].y[1] = -1;
	cube_object[3].y[2] = -1;
	cube_object[3].y[3] = -1;
	cube_object[3].z[0] = -1;
	cube_object[3].z[1] = -1;
	cube_object[3].z[2] = 1;
	cube_object[3].z[3] = 1; 

	cube_object[4].x[0] = 1;
	cube_object[4].x[1] = 1;
	cube_object[4].x[2] = 1;
	cube_object[4].x[3] = 1;
	cube_object[4].y[0] = -1;
	cube_object[4].y[1] = 1;
	cube_object[4].y[2] = 1;
	cube_object[4].y[3] = -1;
	cube_object[4].z[0] = -1;
	cube_object[4].z[1] = -1;
	cube_object[4].z[2] = 1;
	cube_object[4].z[3] = 1;
	
	cube_object[5].x[0] = -1;
	cube_object[5].x[1] = -1;
	cube_object[5].x[2] = 1;
	cube_object[5].x[3] = 1;
	cube_object[5].y[0] = -1;
	cube_object[5].y[1] = 1;
	cube_object[5].y[2] = 1;
	cube_object[5].y[3] = -1;
	cube_object[5].z[0] = -1;
	cube_object[5].z[1] = -1;
	cube_object[5].z[2] = -1;
	cube_object[5].z[3] = -1;

	file_name = "out.bin";

	FILE *fp;
	fp = fopen(file_name, "w");
	// Write object size/data length
	unsigned int data_length = 6;
	fwrite(&data_length, sizeof(unsigned int), 1, fp);
	
	// Write object contents
	fwrite(&cube_object, sizeof(struct quad)*data_length, 1, fp);
	
	printf("Contents written. Data length %d. Byte size %d", data_length, sizeof(struct quad)*data_length);
}
