 # ifndef CREATABLE_H   
 # define CREATABLE_H   
 # include <initializable.h>   
 # include <oopc.h>   
 # define NEW(type, ...) OOP_INTERFACE (CLASS_MANGLE (type), TYPE_NAME (CLASS_MANGLE (type)), Creatable).new(VARIADIC_SIZE_T (__VA_ARGS__), __VA_ARGS__)   
 # define DEL(type, pinst) OOP_INTERFACE (type, *pinst, Creatable).del(pinst)   
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
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Creatable 
 # define OOP_CLASS_G_HIER_Creatable Creatable) OOP_CLASS_G_HIER_Creatable_CLASS OOP_CLASS_G_PARENT_Creatable 
 # define OOP_CLASS_G_PARENT_Creatable_CLASS 
 # define OOP_CLASS_G_HIER_Creatable_CLASS Creatable_CLASS) OOP_CLASS_G_PARENT_Creatable_CLASS 
 # define OOP_MEMBERS_G_Creatable MEMBER_TYPE, (Creatable_CLASS * class__;, Creatable_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Creatable_CLASS *)) ) FUNCTION_TYPE, (void * ( * new ) ( unsigned int, ... );, ftype_new_34, new, (NULL), sizeof(void*), typedef void * ( * ftype_new_34 ) ( unsigned int, ... );) ) FUNCTION_TYPE, (int ( * del ) ( void * );, ftype_del_35, del, (NULL), sizeof(void*), typedef int ( * ftype_del_35 ) ( void * );) ) 
 # define OOP_MEMBERS_G_Creatable_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
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
 static Creatable_CLASS Creatable_CLASS__ = {.class__ = NULL, }; 
 struct Creatable { 
     Creatable_CLASS * class__; 
     void * ( * new ) ( unsigned int, ... ); 
     int ( * del ) ( void * ); 
 
 }; 
 # endif   
 # endif   
