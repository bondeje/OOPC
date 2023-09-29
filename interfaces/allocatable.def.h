#include <oopc.h>
IFNDEF ALLOCATABLE_H
DEFINE ALLOCATABLE_H

INCLUDE <stdlib.h>
INCLUDE <stddef.h>
INCLUDE_OOPC

CLASS(Allocatable,
    FUNCTION(malloc, void *, malloc, size_t)
    FUNCTION(calloc, void *, calloc, size_t, size_t)
    FUNCTION(free, void, free, void *)
)

CLASS(Reallocatable,
    FUNCTION(realloc, void *, realloc, void *, size_t)
    EXTENDS(Allocatable)
)

ENDIF // ALLOCATABLE_H