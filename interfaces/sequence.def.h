#include <oopc.h>
IFNDEF SEQUENCE_H
DEFINE SEQUENCE_H

INCLUDE <collection.h>
INCLUDE <reversible.h>

// Sequence interface
CLASS(Sequence,
    FUNCTION(NULL, void *, get, void *, size_t)
    EXTENDS(Collection)
    EXTENDS(Reversible)
)

// interface for MutableSequence subject to change
CLASS(MutableSequence,
    FUNCTION(NULL, int, add, void *, void *)
    FUNCTION(NULL, int, discard, void *, void *)
    FUNCTION(NULL, int, remove, void *, void *)
    EXTENDS(Sequence)
)

ENDIF // SEQUENCE_H
