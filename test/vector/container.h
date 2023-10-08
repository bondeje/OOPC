 # ifndef CONTAINER_H
 # define CONTAINER_H
 # ifndef IMPORT_CLASS_DEFS_ONLY
 # include <stdbool.h>
 # endif
 # include <oopc.h>
 # define CONTAINS(type, pinst, parg) OOP_INTERFACE (type, *pinst, Container).contains(pinst, parg)
 # define IS_EMPTY(type, pinst) OOP_INTERFACE (type, *pinst, Container).is_empty(pinst)
 # define IN(parg, type, pinst) CONTAINS(type, pinst, parg)
 # ifndef OOP_MEMBER_Container 
 	 # define OOP_MEMBER_Container( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Container_CLASS 
 	 # define OOP_MEMBER_Container_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_contains 
 	 # define OOP_MEMBER_contains( x ) x 
 # endif 
 # ifndef OOP_MEMBER_is_empty 
 	 # define OOP_MEMBER_is_empty( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Container 
 # define OOP_CLASS_G_HIER_Container Container) OOP_CLASS_G_HIER_Container_CLASS OOP_CLASS_G_PARENT_Container 
 # define OOP_CLASS_G_PARENT_Container_CLASS 
 # define OOP_CLASS_G_HIER_Container_CLASS Container_CLASS) OOP_CLASS_G_PARENT_Container_CLASS 
 # define OOP_MEMBERS_G_Container MEMBER_TYPE, (Container_CLASS * class__;, Container_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Container_CLASS *)) ) FUNCTION_TYPE, (bool ( * contains ) ( void *, void * );, ftype_contains_21, contains, (NULL), sizeof(void*), typedef bool ( * ftype_contains_21 ) ( void *, void * );) ) FUNCTION_TYPE, (bool ( * is_empty ) ( void * );, ftype_is_empty_22, is_empty, (NULL), sizeof(void*), typedef bool ( * ftype_is_empty_22 ) ( void * );) ) 
 # define OOP_MEMBERS_G_Container_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Container 
 	 # define TYPEDEF_Container 
 typedef struct Container Container; 
 # endif 
 # ifndef TYPEDEF_Container_CLASS 
 	 # define TYPEDEF_Container_CLASS 
 typedef struct Container_CLASS Container_CLASS; 
 # endif 
 struct Container_CLASS { 
 	 void * class__; 
 }; 
 static Container_CLASS Container_CLASS__ = {.class__ = NULL, }; 
 struct Container { 
 	 Container_CLASS * class__; 
 	 bool ( * contains ) ( void *, void * ); 
 	 bool ( * is_empty ) ( void * ); 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          