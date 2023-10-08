 # ifndef TEMPLATE_VECTOR_H
 # define TEMPLATE_VECTOR_H
 # include <oopc.h>
 # include <array.h>
 # define Vector(el_type) Vector##el_type
 # ifndef TYPEDEF_pvoid 
 	 # define TYPEDEF_pvoid 
 typedef void * pvoid; 
 # endif
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Vectorpvoid 
 	 # define TYPEDEF_Vectorpvoid 
 typedef struct Vectorpvoid Vectorpvoid; 
 # endif 
 # ifndef TYPEDEF_VectorpvoidIterator 
 	 # define TYPEDEF_VectorpvoidIterator 
 typedef struct VectorpvoidIterator VectorpvoidIterator; 
 # endif 
 size_t Vectorpvoid_capacity(void * vector); int Vectorpvoid_push(void * vector, void * el); int Vectorpvoid_insert(void * vector, size_t loc, void * in); int Vectorpvoid_extend(void * vector_dest, void * vector_src); int Vectorpvoid_peek(void * vector, void * out); int Vectorpvoid_pop(void * vector, void * out); int Vectorpvoid_remove(void * vector, size_t loc, void * out); int Vectorpvoid_resize(void * vector, size_t new_cap); int Vectorpvoid_next(void * vector, void * out); void Vectorpvoid_init_(Vectorpvoid * vector); 
 int Vectorpvoid_init(void * vector, unsigned int n, ...); 
 Vectorpvoid * Vectorpvoid_new_(void * vector); 
 void * Vectorpvoid_new(unsigned int, ...); 
 int Vectorpvoid_del(void * vector); 
 # endif 
 # ifndef OOP_MEMBER_Vectorpvoid 
 	 # define OOP_MEMBER_Vectorpvoid( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Vectorpvoid_CLASS 
 	 # define OOP_MEMBER_Vectorpvoid_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_cap 
 	 # define OOP_MEMBER_cap( x ) x 
 # endif 
 # ifndef OOP_MEMBER_resize_factor 
 	 # define OOP_MEMBER_resize_factor( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Arraypvoid__ 
 	 # define OOP_MEMBER_Arraypvoid__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_MutableSequence__ 
 	 # define OOP_MEMBER_MutableSequence__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Creatable__ 
 	 # define OOP_MEMBER_Creatable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Initializable__ 
 	 # define OOP_MEMBER_Initializable__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Vectorpvoid OOP_CLASS_G_HIER_Arraypvoid 
 # define OOP_CLASS_G_HIER_Vectorpvoid Vectorpvoid) OOP_CLASS_G_HIER_Vectorpvoid_CLASS OOP_CLASS_G_PARENT_Vectorpvoid 
 # define OOP_CLASS_G_PARENT_Vectorpvoid_CLASS MutableSequence) MutableSequence_CLASS) Creatable) Creatable_CLASS) Initializable) Initializable_CLASS) 
 # define OOP_CLASS_G_HIER_Vectorpvoid_CLASS Vectorpvoid_CLASS) OOP_CLASS_G_PARENT_Vectorpvoid_CLASS 
 # define OOP_MEMBERS_G_Vectorpvoid MEMBER_TYPE, (Vectorpvoid_CLASS * class__;, Vectorpvoid_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Vectorpvoid_CLASS *)) ) MEMBER_TYPE, (size_t cap;, size_t, cap, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (size_t resize_factor;, size_t, resize_factor, (OOP_NO_DEFAULT), sizeof(size_t)) ) PARENT_TYPE, (Arraypvoid Arraypvoid__;, Arraypvoid, Arraypvoid__, (OOP_NO_DEFAULT), sizeof(Arraypvoid)) ) 
 # define OOP_MEMBERS_G_Vectorpvoid_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (MutableSequence MutableSequence__;, MutableSequence, MutableSequence__, ({ . push = Vectorpvoid_push, . insert = Vectorpvoid_insert, . extend = Vectorpvoid_extend, . peek = Vectorpvoid_peek, . pop = Vectorpvoid_pop, . remove = Vectorpvoid_remove, . capacity = Vectorpvoid_capacity, . resize = Vectorpvoid_resize, }), sizeof(MutableSequence)) ) INTERFACE_TYPE, (Creatable Creatable__;, Creatable, Creatable__, ({ . new = Vectorpvoid_new, . del = Vectorpvoid_del, }), sizeof(Creatable)) ) INTERFACE_TYPE, (Initializable Initializable__;, Initializable, Initializable__, ({ . init = Vectorpvoid_init, }), sizeof(Initializable)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Vectorpvoid 
 	 # define TYPEDEF_Vectorpvoid 
 typedef struct Vectorpvoid Vectorpvoid; 
 # endif 
 # ifndef TYPEDEF_Vectorpvoid_CLASS 
 	 # define TYPEDEF_Vectorpvoid_CLASS 
 typedef struct Vectorpvoid_CLASS Vectorpvoid_CLASS; 
 # endif 
 struct Vectorpvoid_CLASS { 
 	 void * class__; 
 	 MutableSequence MutableSequence__; 
 	 Creatable Creatable__; 
 	 Initializable Initializable__; 
 }; 
 static Vectorpvoid_CLASS Vectorpvoid_CLASS__ = {.class__ = NULL, .MutableSequence__ = { . push = Vectorpvoid_push, . insert = Vectorpvoid_insert, . extend = Vectorpvoid_extend, . peek = Vectorpvoid_peek, . pop = Vectorpvoid_pop, . remove = Vectorpvoid_remove, . capacity = Vectorpvoid_capacity, . resize = Vectorpvoid_resize, }, .Creatable__ = { . new = Vectorpvoid_new, . del = Vectorpvoid_del, }, .Initializable__ = { . init = Vectorpvoid_init, }, }; 
 struct Vectorpvoid { 
 	 Vectorpvoid_CLASS * class__; 
 	 size_t cap; 
 	 size_t resize_factor; 
 	 Arraypvoid Arraypvoid__; 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                