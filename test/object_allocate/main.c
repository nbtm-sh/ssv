#include "object.h"

int main() {
	OBJECT *o = object_allocate(12);
	(o->polygons + 1)[0]->x = 5;
	printf("%d\n%d\n", (o->polygons + 0)[0]->x, (o->polygons + 1)[0]->x);
}
