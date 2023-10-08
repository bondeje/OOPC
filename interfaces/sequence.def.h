#include <oopc.h>
IFNDEF SEQUENCE_H
DEFINE SEQUENCE_H

INCLUDE <collection.h>
INCLUDE <reversible.h>

IFNDEF OMIT_STRUCT_DECLS
INCLUDE <stddef.h>
ENDIF
INCLUDE_OOPC

// some of these would belong in a utility setup or just push to oopc.h. They are also defined in slice.h
DEFINE IS_NEG(x) (!((x) > 0) && ((x) != 0))
DEFINE CYCLE_TO_POS(x, size) (IS_NEG(x) ? size - (-x) : x)

// accepts negative indices
DEFINE GET(SequenceType, pseq, index) OOPC(GET)(SequenceType, *pseq, get)(pseq, CYCLE_TO_POS(index, OOPC(INTERFACE)(SequenceType, *pseq, Sized).len(pseq)))

// Sequence interface
CLASS(Sequence,
    FUNCTION(NULL, int, get, void *, size_t, void *)
    EXTENDS(Collection)
    EXTENDS(Reversible)
)

// interface for MutableSequence subject to change
// semantics of push and pop are defined by the implementation. E.G. for Queue, push is to the end, pop is from the front. For stack, push and pop are both at the end. For deque, they are aliases for push_back and pop_back
// the semantics for peek is that it gets the next element that pop would remove
// insert and remove work the same as push, pop, but additionally specify an index
// extend adds the 2nd MutableSequence to the First
CLASS(MutableSequence,
    FUNCTION(NULL, int, push, void *, void *)
    FUNCTION(NULL, int, insert, void *, size_t, void *)
    FUNCTION(NULL, int, extend, void *, void *)
    FUNCTION(NULL, int, peek, void *, void *)
    FUNCTION(NULL, int, pop, void *, void *)
    FUNCTION(NULL, int, remove, void *, size_t, void *)
    FUNCTION(NULL, size_t, capacity, void *)
    FUNCTION(NULL, int, resize, void *, size_t)
)

ENDIF // SEQUENCE_H
