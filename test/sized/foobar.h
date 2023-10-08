 # include <sized.h>
 # include <oopc.h>
 # ifndef IMPORT_CLASS_DEFS_ONLY
size_t FooBar_len(void *);
 # endif
 # ifndef OOP_MEMBER_FooBar 
 	 # define OOP_MEMBER_FooBar( x ) x 
 # endif 
 # ifndef OOP_MEMBER_FooBar_CLASS 
 	 # define OOP_MEMBER_FooBar_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_str 
 	 # define OOP_MEMBER_str( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sized__ 
 	 # define OOP_MEMBER_Sized__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_FooBar 
 # define OOP_CLASS_G_HIER_FooBar FooBar) OOP_CLASS_G_HIER_FooBar_CLASS OOP_CLASS_G_PARENT_FooBar 
 # define OOP_CLASS_G_PARENT_FooBar_CLASS Sized) Sized_CLASS) 
 # define OOP_CLASS_G_HIER_FooBar_CLASS FooBar_CLASS) OOP_CLASS_G_PARENT_FooBar_CLASS 
 # define OOP_MEMBERS_G_FooBar MEMBER_TYPE, (FooBar_CLASS * class__;, FooBar_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(FooBar_CLASS *)) ) MEMBER_TYPE, (char * str;, char *, str, (OOP_NO_DEFAULT), sizeof(char *)) ) 
 # define OOP_MEMBERS_G_FooBar_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Sized Sized__;, Sized, Sized__, ({ . len = FooBar_len, }), sizeof(Sized)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_FooBar 
 	 # define TYPEDEF_FooBar 
 typedef struct FooBar FooBar; 
 # endif 
 # ifndef TYPEDEF_FooBar_CLASS 
 	 # define TYPEDEF_FooBar_CLASS 
 typedef struct FooBar_CLASS FooBar_CLASS; 
 # endif 
 struct FooBar_CLASS { 
 	 void * class__; 
 	 Sized Sized__; 
 }; 
 static FooBar_CLASS FooBar_CLASS__ = {.class__ = NULL, .Sized__ = { . len = FooBar_len, }, }; 
 struct FooBar { 
 	 FooBar_CLASS * class__; 
 	 char * str; 
 
 }; 
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          