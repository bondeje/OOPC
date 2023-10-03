#include <oopc.h>
IFNDEF ITERATION_H
DEFINE ITERATION_H
INCLUDE_OOPC

// return types for *_next should be constant pointers

IFNDEF OMIT_STRUCT_DECLS
enum iterator_status {
    ITERATOR_FAIL = -1,
    ITERATOR_GO,
    ITERATOR_STOP,
    ITERATOR_PAUSE,
    ITERATOR_STOP_1
};
ENDIF

// convenience macros to wrap calls to the interface
DEFINE ITER(IterableType, pinst, piterator) OOPC(INTERFACE)(IterableType, *pinst, Iterable).iter(pinst, piterator)
DEFINE NEXT(IteratorType, pinst) OOPC(INTERFACE)(IteratorType, *pinst, Iterator).next(pinst)
DEFINE STOP(IteratorType, pinst) OOPC(INTERFACE)(IteratorType, *pinst, Iterator).stop(pinst)

// this is a convenience macro, but like many conveniences, it comes with some fairly significant limitations. Most significantly, the iterator cannot be configured
// probably going to change this to accept only IteratorType and pIteratorInstance. If you already have an iterator...just make a for loop. It's super easy
DEFINE FOR_EACH(el_type, el_name, IterableType, pIterableInstance, IteratorType) IteratorType SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)); SPLIT(OOP_INTERFACE)(IterableType, *pIterableInstance, Iterable).iter(pIterableInstance, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _))); for (el_type * el_name = (el_type *) NEXT(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _))); STOP(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _))) != ITERATOR_STOP; el_name = (el_type *) NEXT(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _))))

// iter takes two arguments. the first is the Iterable object 'self' and the second is the iterator to initialize. The remainder are initialization arguments
CLASS(Iterable,
    FUNCTION(NULL, int, iter, void *, void *)
)

// both next and stop only take a single argument, that being the Iterator object 'self'
// next returns a pointer to the next object in the Iterable
// stop returns an iterator status. Mostly for use in constructs like FOREACH
CLASS(Iterator,
    FUNCTION(NULL, void *, next, void *)
    FUNCTION(NULL, int, stop, void *)
    EXTENDS(Iterable)
)

ENDIF // ITERATION_H
