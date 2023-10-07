#include <oopc.h>
IFNDEF ITERATION_H
DEFINE ITERATION_H
INCLUDE_OOPC

/*
because  .next now gives a failure, can use that to completely replace .stop and STOP. FOR_EACH would simply have the form:
    for ( ; NEXT(IteratorType, pinst, pdest) ; )
*/

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
DEFINE ITER(IterableType, pinst, piterator) OOPC(GET)(IterableType, *pinst, iter)(pinst, piterator)
DEFINE NEXT(IteratorType, pinst, pdest) OOPC(GET)(IteratorType, *pinst, next)(pinst, pdest)
//DEFINE STOP(IteratorType, pinst) OOPC(GET)(IteratorType, *pinst, stop)(pinst)

// this is a convenience macro, but like many conveniences, it comes with some fairly significant limitations. Most significantly, the iterator cannot be configured
// probably going to change this to accept only IteratorType and pIteratorInstance. If you already have an iterator...just make a for loop. It's super easy
//DEFINE FOR_EACH(el_type, el_name, IterableType, pIterableInstance, IteratorType) el_type el_name; IteratorType SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)); ITER(IterableType, pIterableInstance, &(SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)))); for (NEXT(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)), &el_name); STOP(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _))) != ITERATOR_STOP; NEXT(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)), &el_name))
DEFINE FOR_EACH(el_type, el_name, IterableType, pIterableInstance, IteratorType) el_type el_name; IteratorType SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)); ITER(IterableType, pIterableInstance, &(SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)))); for (; !NEXT(IteratorType, &SPLIT(OOP_UNIQUE_VAR_NAME)(SPLIT(CATD)(IteratorType, el_name, _)), &el_name); )

// iter takes two arguments. the first is the Iterable object 'self' and the second is the iterator to initialize. The remainder are initialization arguments
CLASS(Iterable,
    FUNCTION(NULL, int, iter, void *, void *)
)

// both next and stop only take a single argument, that being the Iterator object 'self'
// next returns a pointer to the next object in the Iterable
// stop returns an iterator status. Mostly for use in constructs like FOREACH
CLASS(Iterator,
    FUNCTION(NULL, int, next, void *, void *)
    EXTENDS(Iterable)
)
//FUNCTION(NULL, int, stop, void *)

ENDIF // ITERATION_H
