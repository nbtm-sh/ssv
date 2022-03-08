#include "object.h"

OBJECT *object_allocate(int p_count) {
	// Calculate memory allocation size
	p_count *= sizeof(POLYGON_T);
	
	// Allocate base object
	OBJECT *alloc = (OBJECT *) malloc(sizeof(OBJECT));
	
	// Allocate polygon array
	alloc->polygons = malloc(p_count);

	return alloc;
}
