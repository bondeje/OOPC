#include <oopc.h>
IFNDEF ITERATION_H
DEFINE ITERATION_H

INCLUDE <creatable.h>

enum iterator_status {
    ITERATOR_FAIL = -1,
    ITERATOR_GO,
    ITERATOR_STOP,
    ITERATOR_PAUSE,
};

// convenience macros to wrap calls to the interface
DEFINE ITER(IterableType, pinst, ...) OOPC(INTERFACE)(IterableType, *pinst, Iterable).iter(pinst, CATD(__VA, ARGS__, _))
DEFINE NEXT(IteratorType, pinst) OOPC(INTERFACE)(IteratorType, *pinst, Iterator).next(pinst)
DEFINE STOP(IteratorType, pinst) OOPC(INTERFACE)(IteratorType, *pinst, Iterator).stop(pinst)

// iter takes two arguments. the first is the Iterable object 'self' and the second is the iterator to initialize. The remainder are initialization arguments
CLASS(Iterable,
    FUNCTION(NULL, int, iter, void *, void *, ...)
)

// both next and stop only take a single argument, that being the Iterator object 'self'
// next returns a pointer to the next object in the Iterable
// stop returns an iterator status. Mostly for use in constructs like FOREACH
CLASS(Iterator,
    FUNCTION(NULL, void *, next, void *)
    FUNCTION(NULL, enum iterator_status, stop, void *)
    EXTENDS(Iterable)
)

ENDIF // ITERATION_H
