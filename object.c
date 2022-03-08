#include "object.h"

OBJECT *object_allocate(int32_t p_count) {
	// Calculate memory allocation size
	p_count *= sizeof(POLYGON_T);
	
	// Allocate base object
	OBJECT *alloc = (OBJECT *) ss_malloc(sizeof(OBJECT));
	
	// Allocate polygon array
	alloc->polygons = ss_malloc(p_count);

	return alloc;
}
