 # ifndef SEQUENCE_H
 # define SEQUENCE_H
 # include <collection.h>
 # include <reversible.h>
 # ifndef OMIT_STRUCT_DECLS
 # include <stddef.h>
 # endif
 # include <oopc.h>
 # define IS_NEG(x) (!((x) > 0) && ((x) != 0))
 # define CYCLE_TO_POS(x, size) (IS_NEG(x) ? size - (-x) : x)
 # define GET(SequenceType, pseq, index) OOP_GET (SequenceType, *pseq, get)(pseq, CYCLE_TO_POS(index, OOP_INTERFACE (SequenceType, *pseq, Sized).len(pseq)))
 # ifndef OOP_MEMBER_Sequence 
 	 # define OOP_MEMBER_Sequence( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sequence_CLASS 
 	 # define OOP_MEMBER_Sequence_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_get 
 	 # define OOP_MEMBER_get( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Collection__ 
 	 # define OOP_MEMBER_Collection__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Reversible__ 
 	 # define OOP_MEMBER_Reversible__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Sequence OOP_CLASS_G_HIER_Collection OOP_CLASS_G_HIER_Reversible 
 # define OOP_CLASS_G_HIER_Sequence Sequence) OOP_CLASS_G_HIER_Sequence_CLASS OOP_CLASS_G_PARENT_Sequence 
 # define OOP_CLASS_G_PARENT_Sequence_CLASS 
 # define OOP_CLASS_G_HIER_Sequence_CLASS Sequence_CLASS) OOP_CLASS_G_PARENT_Sequence_CLASS 
 # define OOP_MEMBERS_G_Sequence MEMBER_TYPE, (Sequence_CLASS * class__;, Sequence_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Sequence_CLASS *)) ) FUNCTION_TYPE, (int ( * get ) ( void *, size_t, void * );, ftype_get_22, get, (NULL), sizeof(void*), typedef int ( * ftype_get_22 ) ( void *, size_t, void * );) ) PARENT_TYPE, (Collection Collection__;, Collection, Collection__, (OOP_NO_DEFAULT), sizeof(Collection)) ) PARENT_TYPE, (Reversible Reversible__;, Reversible, Reversible__, (OOP_NO_DEFAULT), sizeof(Reversible)) ) 
 # define OOP_MEMBERS_G_Sequence_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Sequence 
 	 # define TYPEDEF_Sequence 
 typedef struct Sequence Sequence; 
 # endif 
 # ifndef TYPEDEF_Sequence_CLASS 
 	 # define TYPEDEF_Sequence_CLASS 
 typedef struct Sequence_CLASS Sequence_CLASS; 
 # endif 
 struct Sequence_CLASS { 
 	 void * class__; 
 }; 
 static Sequence_CLASS Sequence_CLASS__ = {.class__ = NULL, }; 
 struct Sequence { 
 	 Sequence_CLASS * class__; 
 	 int ( * get ) ( void *, size_t, void * ); 
 	 Collection Collection__; 
 	 Reversible Reversible__; 
 
 }; 
 # endif
 # ifndef OOP_MEMBER_MutableSequence 
 	 # define OOP_MEMBER_MutableSequence( x ) x 
 # endif 
 # ifndef OOP_MEMBER_MutableSequence_CLASS 
 	 # define OOP_MEMBER_MutableSequence_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_push 
 	 # define OOP_MEMBER_push( x ) x 
 # endif 
 # ifndef OOP_MEMBER_insert 
 	 # define OOP_MEMBER_insert( x ) x 
 # endif 
 # ifndef OOP_MEMBER_extend 
 	 # define OOP_MEMBER_extend( x ) x 
 # endif 
 # ifndef OOP_MEMBER_peek 
 	 # define OOP_MEMBER_peek( x ) x 
 # endif 
 # ifndef OOP_MEMBER_pop 
 	 # define OOP_MEMBER_pop( x ) x 
 # endif 
 # ifndef OOP_MEMBER_remove 
 	 # define OOP_MEMBER_remove( x ) x 
 # endif 
 # ifndef OOP_MEMBER_capacity 
 	 # define OOP_MEMBER_capacity( x ) x 
 # endif 
 # ifndef OOP_MEMBER_resize 
 	 # define OOP_MEMBER_resize( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_MutableSequence 
 # define OOP_CLASS_G_HIER_MutableSequence MutableSequence) OOP_CLASS_G_HIER_MutableSequence_CLASS OOP_CLASS_G_PARENT_MutableSequence 
 # define OOP_CLASS_G_PARENT_MutableSequence_CLASS 
 # define OOP_CLASS_G_HIER_MutableSequence_CLASS MutableSequence_CLASS) OOP_CLASS_G_PARENT_MutableSequence_CLASS 
 # define OOP_MEMBERS_G_MutableSequence MEMBER_TYPE, (MutableSequence_CLASS * class__;, MutableSequence_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(MutableSequence_CLASS *)) ) FUNCTION_TYPE, (int ( * push ) ( void *, void * );, ftype_push_33, push, (NULL), sizeof(void*), typedef int ( * ftype_push_33 ) ( void *, void * );) ) FUNCTION_TYPE, (int ( * insert ) ( void *, size_t, void * );, ftype_insert_34, insert, (NULL), sizeof(void*), typedef int ( * ftype_insert_34 ) ( void *, size_t, void * );) ) FUNCTION_TYPE, (int ( * extend ) ( void *, void * );, ftype_extend_35, extend, (NULL), sizeof(void*), typedef int ( * ftype_extend_35 ) ( void *, void * );) ) FUNCTION_TYPE, (int ( * peek ) ( void *, void * );, ftype_peek_36, peek, (NULL), sizeof(void*), typedef int ( * ftype_peek_36 ) ( void *, void * );) ) FUNCTION_TYPE, (int ( * pop ) ( void *, void * );, ftype_pop_37, pop, (NULL), sizeof(void*), typedef int ( * ftype_pop_37 ) ( void *, void * );) ) FUNCTION_TYPE, (int ( * remove ) ( void *, size_t, void * );, ftype_remove_38, remove, (NULL), sizeof(void*), typedef int ( * ftype_remove_38 ) ( void *, size_t, void * );) ) FUNCTION_TYPE, (size_t ( * capacity ) ( void * );, ftype_capacity_39, capacity, (NULL), sizeof(void*), typedef size_t ( * ftype_capacity_39 ) ( void * );) ) FUNCTION_TYPE, (int ( * resize ) ( void *, size_t );, ftype_resize_40, resize, (NULL), sizeof(void*), typedef int ( * ftype_resize_40 ) ( void *, size_t );) ) 
 # define OOP_MEMBERS_G_MutableSequence_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_MutableSequence 
 	 # define TYPEDEF_MutableSequence 
 typedef struct MutableSequence MutableSequence; 
 # endif 
 # ifndef TYPEDEF_MutableSequence_CLASS 
 	 # define TYPEDEF_MutableSequence_CLASS 
 typedef struct MutableSequence_CLASS MutableSequence_CLASS; 
 # endif 
 struct MutableSequence_CLASS { 
 	 void * class__; 
 }; 
 static MutableSequence_CLASS MutableSequence_CLASS__ = {.class__ = NULL, }; 
 struct MutableSequence { 
 	 MutableSequence_CLASS * class__; 
 	 int ( * push ) ( void *, void * ); 
 	 int ( * insert ) ( void *, size_t, void * ); 
 	 int ( * extend ) ( void *, void * ); 
 	 int ( * peek ) ( void *, void * ); 
 	 int ( * pop ) ( void *, void * ); 
 	 int ( * remove ) ( void *, size_t, void * ); 
 	 size_t ( * capacity ) ( void * ); 
 	 int ( * resize ) ( void *, size_t ); 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                