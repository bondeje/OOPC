 # ifndef SEQUENCE_H   
 # define SEQUENCE_H   
 # include <collection.h>   
 # include <reversible.h>   
 # ifndef OMIT_STRUCT_DECLS   
 # include <stddef.h>   
 # endif   
 # include <oopc.h>   
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
 # define OOP_MEMBERS_G_Sequence MEMBER_TYPE, (Sequence_CLASS * class__;, Sequence_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Sequence_CLASS *)) ) FUNCTION_TYPE, (void * ( * get ) ( void *, size_t );, ftype_get_17, get, (NULL), sizeof(void*), typedef void * ( * ftype_get_17 ) ( void *, size_t );) ) PARENT_TYPE, (Collection Collection__;, Collection, Collection__, (OOP_NO_DEFAULT), sizeof(Collection)) ) PARENT_TYPE, (Reversible Reversible__;, Reversible, Reversible__, (OOP_NO_DEFAULT), sizeof(Reversible)) ) 
 # define OOP_MEMBERS_G_Sequence_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
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
     void * ( * get ) ( void *, size_t ); 
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
 # ifndef OOP_MEMBER_Sequence__ 
     # define OOP_MEMBER_Sequence__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_MutableSequence OOP_CLASS_G_HIER_Sequence 
 # define OOP_CLASS_G_HIER_MutableSequence MutableSequence) OOP_CLASS_G_HIER_MutableSequence_CLASS OOP_CLASS_G_PARENT_MutableSequence 
 # define OOP_CLASS_G_PARENT_MutableSequence_CLASS 
 # define OOP_CLASS_G_HIER_MutableSequence_CLASS MutableSequence_CLASS) OOP_CLASS_G_PARENT_MutableSequence_CLASS 
 # define OOP_MEMBERS_G_MutableSequence MEMBER_TYPE, (MutableSequence_CLASS * class__;, MutableSequence_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(MutableSequence_CLASS *)) ) FUNCTION_TYPE, (int ( * push ) ( void *, void * );, ftype_push_28, push, (NULL), sizeof(void*), typedef int ( * ftype_push_28 ) ( void *, void * );) ) FUNCTION_TYPE, (int ( * insert ) ( void *, void *, size_t );, ftype_insert_29, insert, (NULL), sizeof(void*), typedef int ( * ftype_insert_29 ) ( void *, void *, size_t );) ) FUNCTION_TYPE, (int ( * extend ) ( void *, void * );, ftype_extend_30, extend, (NULL), sizeof(void*), typedef int ( * ftype_extend_30 ) ( void *, void * );) ) FUNCTION_TYPE, (void * ( * peek ) ( void * );, ftype_peek_31, peek, (NULL), sizeof(void*), typedef void * ( * ftype_peek_31 ) ( void * );) ) FUNCTION_TYPE, (void * ( * pop ) ( void * );, ftype_pop_32, pop, (NULL), sizeof(void*), typedef void * ( * ftype_pop_32 ) ( void * );) ) FUNCTION_TYPE, (void * ( * remove ) ( void *, size_t );, ftype_remove_33, remove, (NULL), sizeof(void*), typedef void * ( * ftype_remove_33 ) ( void *, size_t );) ) PARENT_TYPE, (Sequence Sequence__;, Sequence, Sequence__, (OOP_NO_DEFAULT), sizeof(Sequence)) ) 
 # define OOP_MEMBERS_G_MutableSequence_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
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
     int ( * insert ) ( void *, void *, size_t ); 
     int ( * extend ) ( void *, void * ); 
     void * ( * peek ) ( void * ); 
     void * ( * pop ) ( void * ); 
     void * ( * remove ) ( void *, size_t ); 
     Sequence Sequence__; 
 
 }; 
 # endif   
 # endif   
