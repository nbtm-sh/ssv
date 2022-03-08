#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__

#define ss_malloc malloc

#endif

#ifdef __SATURN__ 

#define ss_malloc jo_malloc 

#endif

