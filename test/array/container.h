 # ifndef CONTAINER_H   
 # define CONTAINER_H   
 # include <stdbool.h>   
 # include <creatable.h>   
 # include <oopc.h>   
 # define CONTAINS(type, pinst, parg) OOP_INTERFACE (type, *pinst, Container).contains(pinst, parg)   
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
 
 # define OOP_CLASS_G_PARENT_Container 
 # define OOP_CLASS_G_HIER_Container Container) OOP_CLASS_G_HIER_Container_CLASS OOP_CLASS_G_PARENT_Container 
 # define OOP_CLASS_G_PARENT_Container_CLASS 
 # define OOP_CLASS_G_HIER_Container_CLASS Container_CLASS) OOP_CLASS_G_PARENT_Container_CLASS 
 # define OOP_MEMBERS_G_Container MEMBER_TYPE, (Container_CLASS * class__;, Container_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Container_CLASS *)) ) FUNCTION_TYPE, (bool ( * contains ) ( void *, void * );, ftype_contains_25, contains, (NULL), sizeof(void*), typedef bool ( * ftype_contains_25 ) ( void *, void * );) ) 
 # define OOP_MEMBERS_G_Container_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
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
 
 }; 
 # endif   
 # endif   
