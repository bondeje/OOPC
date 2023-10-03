// very much in works!

// to be sliceable is a specific type of iteration, mostly for sequences, where a subset of (start, stop, step) are used to control access
// to an underlying container

// CONSIDER: this should just be put inside sequence.def.h since it can only act on sequences
#include <oopc.h>
IFNDEF SLICEABLE_H
DEFINE SLICEABLE_H

INCLUDE <sized.h> // the Sized interface is potentially used if SLICE() is called with 4 arguments
INCLUDE_OOPC

// In order to use SLICE with 3 or 4 variable arguments (only specifying start or no parts of the slice), the object must also satisfy the Sized interface
DEFINE SLICE_1(SliceableType, psrc, pdest, start) SLICE_4(SliceableType, psrc, pdest, 0, OOPC(INTERFACE)(SliceableType, *psrc, Sized).len(psrc), 1)
DEFINE SLICE_2(SliceableType, psrc, pdest, start) SLICE_4(SliceableType, psrc, pdest, start, OOPC(INTERFACE)(SliceableType, *psrc, Sized).len(psrc), 1)
DEFINE SLICE_3(SliceableType, psrc, pdest, start, stop) SLICE_4(SliceableType, psrc, pdest, start, stop, (stop >= start ? 1 : -1))
DEFINE SLICE_4(SliceableType, psrc, pdest, start, stop, step) OOPC(INTERFACE)(SliceableType, *psrc, Sliceable).slice(psrc, pdest, 3, start, stop, step)
DEFINE SLICE(SliceableType, psrc, ...) SPLIT(CAT)(SLICE_, SPLIT(VARIADIC_SIZE)(__VA_ARGS__))(SliceableType, psrc, __VA_ARGS__)

// semantics of slice function is that it takes a collection and initializes another object with a copy of that collection using only the elements defined by a Slice (start, [stop, [step]])
// since Slice takes indices, this is mostly applicable to collections that satisify the Sequence interface, but could be more general, e.g. every other item in a LinkedList could be collected this way
CLASS(Sliceable,
    FUNCTION(NULL, int slice(void *, void *, unsigned int, ...))
)

ENDIF // SLICEABLE_H
