#include <oopc.h>
IFNDEF CONTAINER_H
DEFINE CONTAINER_H

INCLUDE <stdbool.h>
INCLUDE <creatable.h>
INCLUDE_OOPC

/*
Most containers implicitly need to INHERIT from the Comparable class/interface.
*/

DEFINE CONTAINS(type, pinst, parg) SPLIT(OOP_INTERFACE)(type, *pinst, Container).contains(pinst, parg)
// a little stupid, but to be like 'in' in Python
DEFINE IN(parg, type, pinst) CONTAINS(type, pinst, parg)

/**
 * contains takes as its first argument an instance of the class that implements Container and as its second argument, any arbitrary object.
 * A basic, default implementation will just compare IDs as that is all the information that is guaranteed to be available. If, however, the implementing class also extends Comparable, the results of contains can also check values
 */
CLASS(Container,
    FUNCTION(NULL, bool, contains, void *, void *)
)

ENDIF // CONTAINER_H