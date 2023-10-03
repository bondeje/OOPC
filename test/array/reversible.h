 # ifndef REVERSIBLE_H   
 # define REVERSIBLE_H   
 # include <iteration.h>   
 # define REVERSED(ReversibleType, pinst, preversible) OOP_INTERFACE (ReversibleType, *pinst, Reversible).reversed(pinst, preversible)   
 # ifndef OOP_MEMBER_Reversible 
     # define OOP_MEMBER_Reversible( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Reversible_CLASS 
     # define OOP_MEMBER_Reversible_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_reverse 
     # define OOP_MEMBER_reverse( x ) x 
 # endif 
 # ifndef OOP_MEMBER_reversed 
     # define OOP_MEMBER_reversed( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterable__ 
     # define OOP_MEMBER_Iterable__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Reversible OOP_CLASS_G_HIER_Iterable 
 # define OOP_CLASS_G_HIER_Reversible Reversible) OOP_CLASS_G_HIER_Reversible_CLASS OOP_CLASS_G_PARENT_Reversible 
 # define OOP_CLASS_G_PARENT_Reversible_CLASS 
 # define OOP_CLASS_G_HIER_Reversible_CLASS Reversible_CLASS) OOP_CLASS_G_PARENT_Reversible_CLASS 
 # define OOP_MEMBERS_G_Reversible MEMBER_TYPE, (Reversible_CLASS * class__;, Reversible_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Reversible_CLASS *)) ) FUNCTION_TYPE, (int ( * reverse ) ( void * );, ftype_reverse_15, reverse, (NULL), sizeof(void*), typedef int ( * ftype_reverse_15 ) ( void * );) ) FUNCTION_TYPE, (int ( * reversed ) ( void *, void * );, ftype_reversed_16, reversed, (NULL), sizeof(void*), typedef int ( * ftype_reversed_16 ) ( void *, void * );) ) PARENT_TYPE, (Iterable Iterable__;, Iterable, Iterable__, (OOP_NO_DEFAULT), sizeof(Iterable)) ) 
 # define OOP_MEMBERS_G_Reversible_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
 # ifndef TYPEDEF_Reversible 
     # define TYPEDEF_Reversible 
 typedef struct Reversible Reversible; 
 # endif 
 # ifndef TYPEDEF_Reversible_CLASS 
     # define TYPEDEF_Reversible_CLASS 
 typedef struct Reversible_CLASS Reversible_CLASS; 
 # endif 
 struct Reversible_CLASS { 
     void * class__; 
 }; 
 static Reversible_CLASS Reversible_CLASS__ = {.class__ = NULL, }; 
 struct Reversible { 
     Reversible_CLASS * class__; 
     int ( * reverse ) ( void * ); 
     int ( * reversed ) ( void *, void * ); 
     Iterable Iterable__; 
 
 }; 
 # endif   
 # endif   
