#include <oopc.h>
IFNDEF SET_H
DEFINE SET_H

INCLUDE <collection.h>
INCLUDE <comparable.h>

// This one is much more complicated as I need to be able to do set math...need more interfacing

CLASS(Set,
    EXTENDS(Collection)
    EXTENDS(Comparable)
)

// interface is likely to change for the functions introduced with MutableSet
CLASS(MutableSet,
    FUNCTION(NULL, int, add, void *, void *)
    FUNCTION(NULL, int, discard, void *, void *)
    FUNCTION(NULL, int, remove, void *, void *)
    EXTENDS(Set)
)

ENDIF // SET_H
