 # ifndef SIZED_H
 # define SIZED_H
 # ifndef IMPORT_CLASS_DEFS_ONLY
 # include <stddef.h>
 # endif
 # include <oopc.h>
 # define LEN(type, pinst) OOP_INTERFACE (type, *pinst, Sized).len(pinst)
 # ifndef OOP_MEMBER_Sized 
 	 # define OOP_MEMBER_Sized( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sized_CLASS 
 	 # define OOP_MEMBER_Sized_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_len 
 	 # define OOP_MEMBER_len( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Sized 
 # define OOP_CLASS_G_HIER_Sized Sized) OOP_CLASS_G_HIER_Sized_CLASS OOP_CLASS_G_PARENT_Sized 
 # define OOP_CLASS_G_PARENT_Sized_CLASS 
 # define OOP_CLASS_G_HIER_Sized_CLASS Sized_CLASS) OOP_CLASS_G_PARENT_Sized_CLASS 
 # define OOP_MEMBERS_G_Sized MEMBER_TYPE, (Sized_CLASS * class__;, Sized_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Sized_CLASS *)) ) FUNCTION_TYPE, (size_t ( * len ) ( void * );, ftype_len_13, len, (NULL), sizeof(void*), typedef size_t ( * ftype_len_13 ) ( void * );) ) 
 # define OOP_MEMBERS_G_Sized_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Sized 
 	 # define TYPEDEF_Sized 
 typedef struct Sized Sized; 
 # endif 
 # ifndef TYPEDEF_Sized_CLASS 
 	 # define TYPEDEF_Sized_CLASS 
 typedef struct Sized_CLASS Sized_CLASS; 
 # endif 
 struct Sized_CLASS { 
 	 void * class__; 
 }; 
 static Sized_CLASS Sized_CLASS__ = {.class__ = NULL, }; 
 struct Sized { 
 	 Sized_CLASS * class__; 
 	 size_t ( * len ) ( void * ); 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      