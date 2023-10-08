 # ifndef COLLECTION_H
 # define COLLECTION_H
 # include <sized.h>
 # include <iteration.h>
 # include <container.h>
 # include <oopc.h>
 # ifndef OOP_MEMBER_Collection 
 	 # define OOP_MEMBER_Collection( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Collection_CLASS 
 	 # define OOP_MEMBER_Collection_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterable__ 
 	 # define OOP_MEMBER_Iterable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Container__ 
 	 # define OOP_MEMBER_Container__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sized__ 
 	 # define OOP_MEMBER_Sized__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Collection OOP_CLASS_G_HIER_Iterable OOP_CLASS_G_HIER_Container OOP_CLASS_G_HIER_Sized 
 # define OOP_CLASS_G_HIER_Collection Collection) OOP_CLASS_G_HIER_Collection_CLASS OOP_CLASS_G_PARENT_Collection 
 # define OOP_CLASS_G_PARENT_Collection_CLASS 
 # define OOP_CLASS_G_HIER_Collection_CLASS Collection_CLASS) OOP_CLASS_G_PARENT_Collection_CLASS 
 # define OOP_MEMBERS_G_Collection MEMBER_TYPE, (Collection_CLASS * class__;, Collection_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Collection_CLASS *)) ) PARENT_TYPE, (Iterable Iterable__;, Iterable, Iterable__, (OOP_NO_DEFAULT), sizeof(Iterable)) ) PARENT_TYPE, (Container Container__;, Container, Container__, (OOP_NO_DEFAULT), sizeof(Container)) ) PARENT_TYPE, (Sized Sized__;, Sized, Sized__, (OOP_NO_DEFAULT), sizeof(Sized)) ) 
 # define OOP_MEMBERS_G_Collection_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Collection 
 	 # define TYPEDEF_Collection 
 typedef struct Collection Collection; 
 # endif 
 # ifndef TYPEDEF_Collection_CLASS 
 	 # define TYPEDEF_Collection_CLASS 
 typedef struct Collection_CLASS Collection_CLASS; 
 # endif 
 struct Collection_CLASS { 
 	 void * class__; 
 }; 
 static Collection_CLASS Collection_CLASS__ = {.class__ = NULL, }; 
 struct Collection { 
 	 Collection_CLASS * class__; 
 	 Iterable Iterable__; 
 	 Container Container__; 
 	 Sized Sized__; 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              