#include <oopc.h>
IFNDEF REVERSIBLE_H
DEFINE REVERSIBLE_H

INCLUDE <iteration.h>


// TODO: emit macro REVERSED that takes an 

// reverse takes an object that implements Reversible and reverses it either in place and returns the same object (preferred) or returns a malloc'd object with the same contents in reversed order
// reversed takes an object that implements Reversible and initializes an iterator in reversed order.
// to distinguish, "reverse" makes a permanent change to an object internally or the external return. "reversed" should not change the internal representation of the Reversible object
CLASS(Reversible,
    FUNCTION(NULL, void *, reverse, void *)
    FUNCTION(NULL, int, reversed, void *, void *)
    EXTENDS(Iterable)
)

ENDIF REVERSIBLE_H
