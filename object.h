#include <stdio.h>
#include <stdlib.h>

// Datatype for points in space
typedef struct vec3 {
	int x, y, z;
} VEC3;

// Datatype for a single polygon
typedef VEC3 POLYGON_T[3];

// Datatype for object
typedef struct object {
	int p_count; // Size of array
	POLYGON_T *polygons;
	
	// Origin point for the group of polygons
	VEC3 origin;
} OBJECT;

OBJECT *object_allocate(int p_count);
