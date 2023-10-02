#include <oopc.h>
IFNDEF SEQUENCE_H
DEFINE SEQUENCE_H

INCLUDE <collection.h>
INCLUDE <reversible.h>

IFNDEF OMIT_STRUCT_DECLS
INCLUDE <stddef.h>
ENDIF
INCLUDE_OOPC

// Sequence interface
CLASS(Sequence,
    FUNCTION(NULL, void *, get, void *, size_t)
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
    FUNCTION(NULL, int, insert, void *, void *, size_t)
    FUNCTION(NULL, int, extend, void *, void *)
    FUNCTION(NULL, void *, peek, void *)
    FUNCTION(NULL, void *, pop, void *)
    FUNCTION(NULL, void *, remove, void *, size_t)
    EXTENDS(Sequence)
)

ENDIF // SEQUENCE_H
