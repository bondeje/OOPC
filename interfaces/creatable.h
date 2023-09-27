 # include <oopc.h> 
 # include <stdlib.h> 
 # include <stdio.h>   
 # define NEW(type, ...) (type *) TYPE_NAME (CLASS_MANGLE (type)).Creatable__.new(VARIADIC_SIZE (__VA_ARGS__), __VA_ARGS__)   
 # define INIT(type, pinst, ...) TYPE_NAME (CLASS_MANGLE (type)).Creatable__.init(pinst, VARIADIC_SIZE (__VA_ARGS__), __VA_ARGS__)   
 # define DEL(type, pinst) TYPE_NAME (CLASS_MANGLE (type)).Creatable__.del(pinst)   
 # ifndef OOP_MEMBER_Creatable 
     # define OOP_MEMBER_Creatable( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Creatable_CLASS 
     # define OOP_MEMBER_Creatable_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_new 
     # define OOP_MEMBER_new( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Creatable 
 # define OOP_CLASS_G_HIER_Creatable Creatable) OOP_CLASS_G_HIER_Creatable_CLASS OOP_CLASS_G_PARENT_Creatable 
 # define OOP_CLASS_G_PARENT_Creatable_CLASS 
 # define OOP_CLASS_G_HIER_Creatable_CLASS Creatable_CLASS) OOP_CLASS_G_PARENT_Creatable_CLASS 
 # define OOP_MEMBERS_G_Creatable MEMBER_TYPE, (Creatable_CLASS * class__;, Creatable_CLASS *, class__, OOP_NO_DEFAULT, sizeof(Creatable_CLASS *)) ) FUNCTION_TYPE, (void * ( * new ) ( unsigned int, ... );, ftype_new_36, new, (NULL), sizeof(void*), typedef void * ( * ftype_new_36 ) ( unsigned int, ... );) ) FUNCTION_TYPE, (void ( * init ) ( void *, unsigned int, ... );, ftype_init_37, init, (NULL), sizeof(void*), typedef void ( * ftype_init_37 ) ( void *, unsigned int, ... );) ) FUNCTION_TYPE, (void ( * del ) ( void * );, ftype_del_38, del, (NULL), sizeof(void*), typedef void ( * ftype_del_38 ) ( void * );) ) 
 # define OOP_MEMBERS_G_Creatable_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef TYPEDEF_Creatable 
     # define TYPEDEF_Creatable 
     typedef struct Creatable Creatable; 
 # endif 
 # ifndef TYPEDEF_Creatable_CLASS 
     # define TYPEDEF_Creatable_CLASS 
     typedef struct Creatable_CLASS Creatable_CLASS; 
 # endif 
 struct Creatable_CLASS { 
     void * class__; 
 }; 
 struct Creatable { 
     Creatable_CLASS * class__; 
     void * ( * new ) ( unsigned int, ... ); 
     void ( * init ) ( void *, unsigned int, ... ); 
     void ( * del ) ( void * ); 
 
 }; 
 static Creatable_CLASS Creatable_CLASS__ = {.class__ = NULL, }; 
   
