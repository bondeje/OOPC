#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <iteration.h>
#undef OMIT_STRUCT_DECLS

INCLUDE <stddef.h>
INCLUDE <iteration.h>
INCLUDE_OOPC

TYPEDEF(struct Slice, Slice)
TYPEDEF(struct SliceIterator, SliceIterator)
int SliceIterator_iter(void *, void *);
int SliceIterator_stop(void *);
int SliceIterator_next(void *, void *);

// some of these would belong in a utility setup or just push to oopc.h. Some are also defined in sequence.h
DEFINE IS_NEG(x) (!((x) > 0) && ((x) != 0))
DEFINE CYCLE_TO_POS(x, size) (IS_NEG(x) ? size - (-x) : x)
DEFINE REFLECT_TO_POS(x) (IS_NEG(x) ? -1 * x : x)
DEFINE MINIMUM2(x, y) (x > y ? y : x)
DEFINE MAXIMUM2(x, y) (x > y ? x : y)

DEFINE MAKE_SLICE_1(len) MAKE_SLICE_4(0, len, 1, len)
DEFINE MAKE_SLICE_2(start, len) MAKE_SLICE_4(start, len, 1, len)
DEFINE MAKE_SLICE_3(start, stop, len) MAKE_SLICE_4(start, stop, (stop >= start ? 1 : -1), len)
DEFINE MAKE_SLICE_4__(start_, stop__, step_, len) {.class__ = &TYPE_NAME(CLASS_MANGLE(Slice)), .start = start_, .stop_ = stop__, .step = step_}
DEFINE MAKE_SLICE_4_(start_, stop_, step_, len) MAKE_SLICE_4__(start_ + (stop_ >= start_ && step_ > 0 ? 0 : 1), stop_, step_, len)
DEFINE MAKE_SLICE_4(start_, stop_, step_, len) MAKE_SLICE_4_(MINIMUM2(len, CYCLE_TO_POS(start_, len)), MINIMUM2(len, CYCLE_TO_POS(stop_, len)), step_, len)
DEFINE MAKE_SLICE(...) SPLIT(CAT)(MAKE_SLICE, SPLIT(VARIADIC_SIZE)(__VA_ARGS__))(__VA_ARGS__)

DEFINE MAKE_SLICE_ITERATOR_1(len) MAKE_SLICE_ITERATOR_4(0, len, 1, len)
DEFINE MAKE_SLICE_ITERATOR_2(start, len) MAKE_SLICE_ITERATOR_4(start, len, 1, len)
DEFINE MAKE_SLICE_ITERATOR_3(start, stop, len) MAKE_SLICE_ITERATOR_4(start, stop, (stop >= start ? 1 : -1), len)
DEFINE MAKE_SLICE_ITERATOR_4__(start_, stop__, step_, len) (SliceIterator) {.class__ = &TYPE_NAME(CLASS_MANGLE(SliceIterator)), .sl = MAKE_SLICE_4__(start_, stop__, step_, len), .loc = start_, .stop_ = ITERATOR_PAUSE}
DEFINE MAKE_SLICE_ITERATOR_4_(start_, stop_, step_, len) MAKE_SLICE_ITERATOR_4__(start_ + (stop_ >= start_ && step_ > 0 ? 0 : 1), stop_, step_, len)
DEFINE MAKE_SLICE_ITERATOR_4(start_, stop_, step_, len) MAKE_SLICE_ITERATOR_4_(MINIMUM2(len, CYCLE_TO_POS(start_, len)), MINIMUM2(len, CYCLE_TO_POS(stop_, len)), step_, len)
DEFINE MAKE_SLICE_ITERATOR(...) SPLIT(CAT)(MAKE_SLICE_ITERATOR, SPLIT(VARIADIC_SIZE)(__VA_ARGS__))(__VA_ARGS__)

// note that Slices are NOT iterable
CLASS(Slice, 
    MEMBER(size_t, start)
    MEMBER(size_t, stop_)
    MEMBER(long long int, step)
)

// note that SliceIterator has a member 'stop', it's internal Slice member has a member 'stop', and its interface implementation of Iterator has a member 'stop'
// note that since SliceIterator does not "Extend", searching for stop will get the iterator function, searching for stop_ will only find the SliceIterator member and cannot get Slice's stop_ member
CLASS(SliceIterator,
    MEMBER(Slice, sl)
    MEMBER(size_t, loc)
    MEMBER(int, stop_)
    IMPLEMENTS(Iterator, iter, SliceIterator_iter, next, SliceIterator_next, stop, SliceIterator_stop)
)