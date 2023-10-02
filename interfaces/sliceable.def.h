// very much in works!

// to be sliceable is a specific type of iteration, mostly for sequences, where a subset of (start, stop, step) are used to control access
// to an underlying container

// CONSIDER: this should just be put inside sequence.def.h since it can only act on sequences
#include <oopc.h>
IFNDEF SLICEABLE_H
DEFINE SLICEABLE_H

INCLUDE <sequence.h>
INCLUDE_OOPC


// slices themselves are Iterable Iterators and can only be created by items satisfying the Sequence interface
// These macros instantiate a sequence with another sequence
// if pseq_dest is NULL, return a new Sequence using the SequenceType's implementation of new
DEFINE SLICE_1(SequenceType, pseq_dest, pseq_src, start) SLICE_3(SequenceType, pseq_dest, pseq_src, start, OOPC(INTERFACE)(SequenceType, *pseq_src, Sized).len(pseq_src), 1)
DEFINE SLICE_2(SequenceType, pseq_dest, pseq_src, start, stop) SLICE_3(SequenceType, pseq_dest, pseq_src, start, stop, 1)
DEFINE SLICE_3(SequenceType, pseq_dest, pseq_src, start, stop, step) // TODO: copy elements iterating over slice from src into destination
DEFINE SLICE(SequenceType, pseq_dest, pseq_src, ...) CATD(SLICE, VARIADIC_SIZE(__VA_ARGS__), _)(SequenceType, pseq_inst, __VA_ARGS__)

CLASS(Slice,
    MEMBER(size_t, loc)
    MEMBER(size_t, start)
    MEMBER(size_t, stop)
    MEMBER(long long, step)
    IMPLEMENTS(Iterator, next, [insert next implementation], stop, [insert stop implementation])
    IMPLEMENTS(Iterable, iter, [insert iter implementation])
)

ENDIF // SLICEABLE_H
