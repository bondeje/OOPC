 # include <stddef.h>   
 # include <iteration.h>   
 # include <oopc.h>   
 # ifndef TYPEDEF_Slice 
     # define TYPEDEF_Slice 
 typedef struct Slice Slice; 
 # endif   
 # ifndef TYPEDEF_SliceIterator 
     # define TYPEDEF_SliceIterator 
 typedef struct SliceIterator SliceIterator; 
 # endif   
int SliceIterator_iter(void *, void *);   
int SliceIterator_stop(void *);   
void * SliceIterator_next(void *);   
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
 # ifndef OOP_MEMBER_stop 
     # define x x 
 # endif 
 # ifndef OOP_MEMBER_step 
     # define OOP_MEMBER_step( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Slice 
 # define OOP_CLASS_G_HIER_Slice Slice) OOP_CLASS_G_HIER_Slice_CLASS OOP_CLASS_G_PARENT_Slice 
 # define OOP_CLASS_G_PARENT_Slice_CLASS 
 # define OOP_CLASS_G_HIER_Slice_CLASS Slice_CLASS) OOP_CLASS_G_PARENT_Slice_CLASS 
 # define OOP_MEMBERS_G_Slice MEMBER_TYPE, (Slice_CLASS * class__;, Slice_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Slice_CLASS *)) ) MEMBER_TYPE, (size_t start;, size_t, start, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (size_t stop;, size_t, stop, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (long long int step;, long long int, step, (OOP_NO_DEFAULT), sizeof(long long int)) ) 
 # define OOP_MEMBERS_G_Slice_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
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
     size_t stop; 
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
 # ifndef OOP_MEMBER_stop 
     # define x x 
 # endif 
 # ifndef OOP_MEMBER_Iterator__ 
     # define OOP_MEMBER_Iterator__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_SliceIterator 
 # define OOP_CLASS_G_HIER_SliceIterator SliceIterator) OOP_CLASS_G_HIER_SliceIterator_CLASS OOP_CLASS_G_PARENT_SliceIterator 
 # define OOP_CLASS_G_PARENT_SliceIterator_CLASS Iterator) Iterator_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_SliceIterator_CLASS SliceIterator_CLASS) OOP_CLASS_G_PARENT_SliceIterator_CLASS 
 # define OOP_MEMBERS_G_SliceIterator MEMBER_TYPE, (SliceIterator_CLASS * class__;, SliceIterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(SliceIterator_CLASS *)) ) MEMBER_TYPE, (Slice sl;, Slice, sl, (OOP_NO_DEFAULT), sizeof(Slice)) ) MEMBER_TYPE, (size_t loc;, size_t, loc, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (int stop;, int, stop, (OOP_NO_DEFAULT), sizeof(int)) ) 
 # define OOP_MEMBERS_G_SliceIterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Iterator Iterator__;, Iterator, Iterator__, ({ .Iterable__. iter = SliceIterator_iter, . next = SliceIterator_next, . stop = SliceIterator_stop, }), sizeof(Iterator)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
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
 static SliceIterator_CLASS SliceIterator_CLASS__ = {.class__ = NULL, .Iterator__ = { .Iterable__. iter = SliceIterator_iter, . next = SliceIterator_next, . stop = SliceIterator_stop, }, }; 
 struct SliceIterator { 
     SliceIterator_CLASS * class__; 
     Slice sl; 
     size_t loc; 
     int stop; 
 
 }; 
 # endif   
