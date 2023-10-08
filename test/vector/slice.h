 # include <stddef.h>
 # include <iteration.h>
 # include <oopc.h>
 # ifndef IMPORT_CLASS_DEFS_ONLY
 # ifndef TYPEDEF_Slice 
 	 # define TYPEDEF_Slice 
 typedef struct Slice Slice; 
 # endif
 # ifndef TYPEDEF_SliceIterator 
 	 # define TYPEDEF_SliceIterator 
 typedef struct SliceIterator SliceIterator; 
 # endif
int SliceIterator_iter(void *, void *);
int SliceIterator_next(void *, void *);
 # endif
 # define IS_NEG(x) (!((x) > 0) && ((x) != 0))
 # define CYCLE_TO_POS(x, size) (IS_NEG(x) ? size - (-x) : x)
 # define REFLECT_TO_POS(x) (IS_NEG(x) ? -1 * x : x)
 # define MINIMUM2(x, y) (x > y ? y : x)
 # define MAXIMUM2(x, y) (x > y ? x : y)
 # define MAKE_SLICE_1(len) MAKE_SLICE_4(0, len, 1, len)
 # define MAKE_SLICE_2(start, len) MAKE_SLICE_4(start, len, 1, len)
 # define MAKE_SLICE_3(start, stop, len) MAKE_SLICE_4(start, stop, (stop >= start ? 1 : -1), len)
 # define MAKE_SLICE_4__(start_, stop__, step_, len) {.class__ = &Slice_CLASS__, .start = start_, .stop_ = stop__, .step = step_}
 # define MAKE_SLICE_4_(start_, stop_, step_, len) MAKE_SLICE_4__(start_ + (stop_ >= start_ && step_ > 0 ? 0 : 1), stop_ + (stop_ >= start_ && step_ > 0 ? 0 : 1), step_, len)
 # define MAKE_SLICE_4(start_, stop_, step_, len) MAKE_SLICE_4_(MINIMUM2(len, CYCLE_TO_POS(start_, len)), MINIMUM2(len, CYCLE_TO_POS(stop_, len)), step_, len)
 # define MAKE_SLICE(...) CAT (MAKE_SLICE, VARIADIC_SIZE (__VA_ARGS__))(__VA_ARGS__)
 # define MAKE_SLICE_ITERATOR_1(len) MAKE_SLICE_ITERATOR_4(0, len, 1, len)
 # define MAKE_SLICE_ITERATOR_2(start, len) MAKE_SLICE_ITERATOR_4(start, len, 1, len)
 # define MAKE_SLICE_ITERATOR_3(start, stop, len) MAKE_SLICE_ITERATOR_4(start, stop, (stop >= start ? 1 : -1), len)
 # define MAKE_SLICE_ITERATOR_4__(start_, stop__, step_, len) (SliceIterator) {.class__ = &SliceIterator_CLASS__, .sl = MAKE_SLICE_4__(start_, stop__, step_, len), .loc = start_}
 # define MAKE_SLICE_ITERATOR_4_(start_, stop_, step_, len) MAKE_SLICE_ITERATOR_4__(start_ + (stop_ >= start_ && step_ > 0 ? 0 : 1), stop_, step_, len)
 # define MAKE_SLICE_ITERATOR_4(start_, stop_, step_, len) MAKE_SLICE_ITERATOR_4_(MINIMUM2(len, CYCLE_TO_POS(start_, len)), MINIMUM2(len, CYCLE_TO_POS(stop_, len)), step_, len)
 # define MAKE_SLICE_ITERATOR(...) CAT (MAKE_SLICE_ITERATOR, VARIADIC_SIZE (__VA_ARGS__))(__VA_ARGS__)
 # ifndef OOP_MEMBER_Slice 
 	 # define OOP_MEMBER_Slice( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Slice_CLASS 
 	 # define OOP_MEMBER_Slice_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_start 
 	 # define OOP_MEMBER_start( x ) x 
 # endif 
 # ifndef OOP_MEMBER_stop_ 
 	 # define OOP_MEMBER_stop_( x ) x 
 # endif 
 # ifndef OOP_MEMBER_step 
 	 # define OOP_MEMBER_step( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Slice 
 # define OOP_CLASS_G_HIER_Slice Slice) OOP_CLASS_G_HIER_Slice_CLASS OOP_CLASS_G_PARENT_Slice 
 # define OOP_CLASS_G_PARENT_Slice_CLASS 
 # define OOP_CLASS_G_HIER_Slice_CLASS Slice_CLASS) OOP_CLASS_G_PARENT_Slice_CLASS 
 # define OOP_MEMBERS_G_Slice MEMBER_TYPE, (Slice_CLASS * class__;, Slice_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Slice_CLASS *)) ) MEMBER_TYPE, (size_t start;, size_t, start, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (size_t stop_;, size_t, stop_, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (long long int step;, long long int, step, (OOP_NO_DEFAULT), sizeof(long long int)) ) 
 # define OOP_MEMBERS_G_Slice_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Slice 
 	 # define TYPEDEF_Slice 
 typedef struct Slice Slice; 
 # endif 
 # ifndef TYPEDEF_Slice_CLASS 
 	 # define TYPEDEF_Slice_CLASS 
 typedef struct Slice_CLASS Slice_CLASS; 
 # endif 
 struct Slice_CLASS { 
 	 void * class__; 
 }; 
 static Slice_CLASS Slice_CLASS__ = {.class__ = NULL, }; 
 struct Slice { 
 	 Slice_CLASS * class__; 
 	 size_t start; 
 	 size_t stop_; 
 	 long long int step; 
 
 }; 
 # endif
 # ifndef OOP_MEMBER_SliceIterator 
 	 # define OOP_MEMBER_SliceIterator( x ) x 
 # endif 
 # ifndef OOP_MEMBER_SliceIterator_CLASS 
 	 # define OOP_MEMBER_SliceIterator_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_sl 
 	 # define OOP_MEMBER_sl( x ) x 
 # endif 
 # ifndef OOP_MEMBER_loc 
 	 # define OOP_MEMBER_loc( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterator__ 
 	 # define OOP_MEMBER_Iterator__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_SliceIterator 
 # define OOP_CLASS_G_HIER_SliceIterator SliceIterator) OOP_CLASS_G_HIER_SliceIterator_CLASS OOP_CLASS_G_PARENT_SliceIterator 
 # define OOP_CLASS_G_PARENT_SliceIterator_CLASS Iterator) Iterator_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_SliceIterator_CLASS SliceIterator_CLASS) OOP_CLASS_G_PARENT_SliceIterator_CLASS 
 # define OOP_MEMBERS_G_SliceIterator MEMBER_TYPE, (SliceIterator_CLASS * class__;, SliceIterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(SliceIterator_CLASS *)) ) MEMBER_TYPE, (Slice sl;, Slice, sl, (OOP_NO_DEFAULT), sizeof(Slice)) ) MEMBER_TYPE, (size_t loc;, size_t, loc, (OOP_NO_DEFAULT), sizeof(size_t)) ) 
 # define OOP_MEMBERS_G_SliceIterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Iterator Iterator__;, Iterator, Iterator__, ({ .Iterable__. iter = SliceIterator_iter, . next = SliceIterator_next, }), sizeof(Iterator)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_SliceIterator 
 	 # define TYPEDEF_SliceIterator 
 typedef struct SliceIterator SliceIterator; 
 # endif 
 # ifndef TYPEDEF_SliceIterator_CLASS 
 	 # define TYPEDEF_SliceIterator_CLASS 
 typedef struct SliceIterator_CLASS SliceIterator_CLASS; 
 # endif 
 struct SliceIterator_CLASS { 
 	 void * class__; 
 	 Iterator Iterator__; 
 }; 
 static SliceIterator_CLASS SliceIterator_CLASS__ = {.class__ = NULL, .Iterator__ = { .Iterable__. iter = SliceIterator_iter, . next = SliceIterator_next, }, }; 
 struct SliceIterator { 
 	 SliceIterator_CLASS * class__; 
 	 Slice sl; 
 	 size_t loc; 
 
 }; 
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    