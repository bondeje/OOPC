#ifndef NDEBUG
    #define INCLUDE_STDIO INCLUDE <stdio.h>
#else
    #define INCLUDE_STDIO 
#endif

#ifndef NO_STDLIB
    #define OOP_MALLOC(type) (type *) malloc(sizeof(type))
    #define OOP_FREE(type) free(type)
    #define INCLUDE_STDLIB INCLUDE <stdlib.h>
#else
    #define OOP_MALLOC(type) NULL
    #define OOP_FREE(type) do {} while (0)
    #define INCLUDE_STDLIB 
#endif