 # ifndef INITIALIZABLE_H   
 # define INITIALIZABLE_H   
 # include <oopc.h>   
 # define INIT(type, pinst, ...) OOP_INTERFACE (type, *pinst, Initializable).init(pinst, VARIADIC_SIZE_T (__VA_ARGS__), __VA_ARGS__)   
 # ifndef OOP_MEMBER_Initializable 
     # define OOP_MEMBER_Initializable( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Initializable_CLASS 
     # define OOP_MEMBER_Initializable_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Initializable 
 # define OOP_CLASS_G_HIER_Initializable Initializable) OOP_CLASS_G_HIER_Initializable_CLASS OOP_CLASS_G_PARENT_Initializable 
 # define OOP_CLASS_G_PARENT_Initializable_CLASS 
 # define OOP_CLASS_G_HIER_Initializable_CLASS Initializable_CLASS) OOP_CLASS_G_PARENT_Initializable_CLASS 
 # define OOP_MEMBERS_G_Initializable MEMBER_TYPE, (Initializable_CLASS * class__;, Initializable_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Initializable_CLASS *)) ) FUNCTION_TYPE, (int ( * init ) ( void *, unsigned int, ... );, ftype_init_22, init, (NULL), sizeof(void*), typedef int ( * ftype_init_22 ) ( void *, unsigned int, ... );) ) 
 # define OOP_MEMBERS_G_Initializable_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
 # ifndef TYPEDEF_Initializable 
     # define TYPEDEF_Initializable 
 typedef struct Initializable Initializable; 
 # endif 
 # ifndef TYPEDEF_Initializable_CLASS 
     # define TYPEDEF_Initializable_CLASS 
 typedef struct Initializable_CLASS Initializable_CLASS; 
 # endif 
 struct Initializable_CLASS { 
     void * class__; 
 }; 
 static Initializable_CLASS Initializable_CLASS__ = {.class__ = NULL, }; 
 struct Initializable { 
     Initializable_CLASS * class__; 
     int ( * init ) ( void *, unsigned int, ... ); 
 
 }; 
 # endif   
 # endif   
