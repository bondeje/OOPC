 # ifndef TEMPLATE_ARRAY_H
 # define TEMPLATE_ARRAY_H
 # include <oopc.h>
 # ifndef IMPORT_DEFS_ONLY
 # include <stddef.h>
 # include <stdarg.h>
 # include <stdlib.h>
 # include <stdbool.h>
 # include <creatable.h>
 # include <initializable.h>
 # include <sequence.h>
 # include <slice.h>
 # define ARRAY_DEFAULT_FLAGS 0x00
 # define ARRAY_MALLOC_ARRAY 0x01
 # define ARRAY_SUCCESS 0
 # define ARRAY_FAILURE 1
 # ifndef TYPEDEF_pvoid 
 	 # define TYPEDEF_pvoid 
 typedef void * pvoid; 
 # endif
 # endif
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Arraypvoid 
 	 # define TYPEDEF_Arraypvoid 
 typedef struct Arraypvoid Arraypvoid; 
 # endif 
 # ifndef TYPEDEF_ArraypvoidIterator 
 	 # define TYPEDEF_ArraypvoidIterator 
 typedef struct ArraypvoidIterator ArraypvoidIterator; 
 # endif 
 void Arraypvoid_init_(Arraypvoid *, pvoid *, size_t, unsigned int, size_t); 
 int Arraypvoid_init(void *, unsigned int, ...); 
 Arraypvoid * Arraypvoid_new_(pvoid *, size_t, unsigned int, size_t); 
 void * Arraypvoid_new(unsigned int, ...); 
 int Arraypvoid_del(void *); 
 int Arraypvoid_get(void *, size_t, void *); 
 bool Arraypvoid_contains(void *, pvoid); 
 int Arraypvoid_iter(void *, void *); 
 int ArraypvoidIterator_iter(void *, void *); 
 int ArraypvoidIterator_next(void *, void *); 
 size_t Arraypvoid_len(void *); 
 bool Arraypvoid_is_empty(void *); 
 int Arraypvoid_reverse(void *); 
 int Arraypvoid_reversed(void *, void *); 
 # endif 
 
 # ifndef OOP_MEMBER_Arraypvoid 
 	 # define OOP_MEMBER_Arraypvoid( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Arraypvoid_CLASS 
 	 # define OOP_MEMBER_Arraypvoid_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_arr 
 	 # define OOP_MEMBER_arr( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 	 # define OOP_MEMBER_size( x ) x 
 # endif 
 # ifndef OOP_MEMBER_reversed 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_flags 
 	 # define OOP_MEMBER_flags( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Creatable__ 
 	 # define OOP_MEMBER_Creatable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Initializable__ 
 	 # define OOP_MEMBER_Initializable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sequence__ 
 	 # define OOP_MEMBER_Sequence__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Arraypvoid 
 # define OOP_CLASS_G_HIER_Arraypvoid Arraypvoid) OOP_CLASS_G_HIER_Arraypvoid_CLASS OOP_CLASS_G_PARENT_Arraypvoid 
 # define OOP_CLASS_G_PARENT_Arraypvoid_CLASS Creatable) Creatable_CLASS) Initializable) Initializable_CLASS) Sequence) Sequence_CLASS) Collection) Collection_CLASS) Iterable) Iterable_CLASS) Container) Container_CLASS) Sized) Sized_CLASS) Reversible) Reversible_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_Arraypvoid_CLASS Arraypvoid_CLASS) OOP_CLASS_G_PARENT_Arraypvoid_CLASS 
 # define OOP_MEMBERS_G_Arraypvoid MEMBER_TYPE, (Arraypvoid_CLASS * class__;, Arraypvoid_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Arraypvoid_CLASS *)) ) MEMBER_TYPE, (pvoid * arr;, pvoid *, arr, (OOP_NO_DEFAULT), sizeof(pvoid *)) ) MEMBER_TYPE, (size_t size;, size_t, size, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (unsigned int reversed;, unsigned int, reversed, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) MEMBER_TYPE, (unsigned int flags;, unsigned int, flags, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) 
 # define OOP_MEMBERS_G_Arraypvoid_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Creatable Creatable__;, Creatable, Creatable__, ({ . new = Arraypvoid_new, . del = Arraypvoid_del, }), sizeof(Creatable)) ) INTERFACE_TYPE, (Initializable Initializable__;, Initializable, Initializable__, ({ . init = Arraypvoid_init, }), sizeof(Initializable)) ) INTERFACE_TYPE, (Sequence Sequence__;, Sequence, Sequence__, ({ . get = Arraypvoid_get, .Collection__.Iterable__. iter = Arraypvoid_iter, .Collection__.Container__. contains = Arraypvoid_contains, .Collection__.Container__. is_empty = Arraypvoid_is_empty, .Collection__.Sized__. len = Arraypvoid_len, .Reversible__. reverse = Arraypvoid_reverse, .Reversible__. reversed = Arraypvoid_reversed, }), sizeof(Sequence)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Arraypvoid 
 	 # define TYPEDEF_Arraypvoid 
 typedef struct Arraypvoid Arraypvoid; 
 # endif 
 # ifndef TYPEDEF_Arraypvoid_CLASS 
 	 # define TYPEDEF_Arraypvoid_CLASS 
 typedef struct Arraypvoid_CLASS Arraypvoid_CLASS; 
 # endif 
 struct Arraypvoid_CLASS { 
 	 void * class__; 
 	 Creatable Creatable__; 
 	 Initializable Initializable__; 
 	 Sequence Sequence__; 
 }; 
 static Arraypvoid_CLASS Arraypvoid_CLASS__ = {.class__ = NULL, .Creatable__ = { . new = Arraypvoid_new, . del = Arraypvoid_del, }, .Initializable__ = { . init = Arraypvoid_init, }, .Sequence__ = { . get = Arraypvoid_get, .Collection__.Iterable__. iter = Arraypvoid_iter, .Collection__.Container__. contains = Arraypvoid_contains, .Collection__.Container__. is_empty = Arraypvoid_is_empty, .Collection__.Sized__. len = Arraypvoid_len, .Reversible__. reverse = Arraypvoid_reverse, .Reversible__. reversed = Arraypvoid_reversed, }, }; 
 struct Arraypvoid { 
 	 Arraypvoid_CLASS * class__; 
 	 pvoid * arr; 
 	 size_t size; 
 	 unsigned int reversed; 
 	 unsigned int flags; 
 
 }; 
 # endif 
 # ifndef OOP_MEMBER_ArraypvoidIterator 
 	 # define OOP_MEMBER_ArraypvoidIterator( x ) x 
 # endif 
 # ifndef OOP_MEMBER_ArraypvoidIterator_CLASS 
 	 # define OOP_MEMBER_ArraypvoidIterator_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_iable 
 	 # define OOP_MEMBER_iable( x ) x 
 # endif 
 # ifndef OOP_MEMBER_isl 
 	 # define OOP_MEMBER_isl( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterator__ 
 	 # define OOP_MEMBER_Iterator__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_ArraypvoidIterator 
 # define OOP_CLASS_G_HIER_ArraypvoidIterator ArraypvoidIterator) OOP_CLASS_G_HIER_ArraypvoidIterator_CLASS OOP_CLASS_G_PARENT_ArraypvoidIterator 
 # define OOP_CLASS_G_PARENT_ArraypvoidIterator_CLASS Iterator) Iterator_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_ArraypvoidIterator_CLASS ArraypvoidIterator_CLASS) OOP_CLASS_G_PARENT_ArraypvoidIterator_CLASS 
 # define OOP_MEMBERS_G_ArraypvoidIterator MEMBER_TYPE, (ArraypvoidIterator_CLASS * class__;, ArraypvoidIterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(ArraypvoidIterator_CLASS *)) ) MEMBER_TYPE, (Arraypvoid * iable;, Arraypvoid *, iable, (OOP_NO_DEFAULT), sizeof(Arraypvoid *)) ) MEMBER_TYPE, (SliceIterator isl;, SliceIterator, isl, (OOP_NO_DEFAULT), sizeof(SliceIterator)) ) 
 # define OOP_MEMBERS_G_ArraypvoidIterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Iterator Iterator__;, Iterator, Iterator__, ({ .Iterable__. iter = ArraypvoidIterator_iter, . next = ArraypvoidIterator_next, }), sizeof(Iterator)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_ArraypvoidIterator 
 	 # define TYPEDEF_ArraypvoidIterator 
 typedef struct ArraypvoidIterator ArraypvoidIterator; 
 # endif 
 # ifndef TYPEDEF_ArraypvoidIterator_CLASS 
 	 # define TYPEDEF_ArraypvoidIterator_CLASS 
 typedef struct ArraypvoidIterator_CLASS ArraypvoidIterator_CLASS; 
 # endif 
 struct ArraypvoidIterator_CLASS { 
 	 void * class__; 
 	 Iterator Iterator__; 
 }; 
 static ArraypvoidIterator_CLASS ArraypvoidIterator_CLASS__ = {.class__ = NULL, .Iterator__ = { .Iterable__. iter = ArraypvoidIterator_iter, . next = ArraypvoidIterator_next, }, }; 
 struct ArraypvoidIterator { 
 	 ArraypvoidIterator_CLASS * class__; 
 	 Arraypvoid * iable; 
 	 SliceIterator isl; 
 
 }; 
 # endif
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Arraydouble 
 	 # define TYPEDEF_Arraydouble 
 typedef struct Arraydouble Arraydouble; 
 # endif 
 # ifndef TYPEDEF_ArraydoubleIterator 
 	 # define TYPEDEF_ArraydoubleIterator 
 typedef struct ArraydoubleIterator ArraydoubleIterator; 
 # endif 
 void Arraydouble_init_(Arraydouble *, double *, size_t, unsigned int, size_t); 
 int Arraydouble_init(void *, unsigned int, ...); 
 Arraydouble * Arraydouble_new_(double *, size_t, unsigned int, size_t); 
 void * Arraydouble_new(unsigned int, ...); 
 int Arraydouble_del(void *); 
 int Arraydouble_get(Arraydouble *, size_t, double *); 
 bool Arraydouble_contains(Arraydouble *, double); 
 int Arraydouble_iter(void *, void *); 
 int ArraydoubleIterator_iter(void *, void *); 
 int ArraydoubleIterator_next(ArraydoubleIterator *, double *); 
 size_t Arraydouble_len(void *); 
 bool Arraydouble_is_empty(void *); 
 int Arraydouble_reverse(void *); 
 int Arraydouble_reversed(void *, void *); 
 # endif 
 
 # ifndef OOP_MEMBER_Arraydouble 
 	 # define OOP_MEMBER_Arraydouble( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Arraydouble_CLASS 
 	 # define OOP_MEMBER_Arraydouble_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_arr 
 	 # define OOP_MEMBER_arr( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 	 # define OOP_MEMBER_size( x ) x 
 # endif 
 # ifndef OOP_MEMBER_reversed 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_flags 
 	 # define OOP_MEMBER_flags( x ) x 
 # endif 
 # ifndef OOP_MEMBER_get 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_contains 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_Creatable__ 
 	 # define OOP_MEMBER_Creatable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Initializable__ 
 	 # define OOP_MEMBER_Initializable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sequence__ 
 	 # define OOP_MEMBER_Sequence__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Arraydouble 
 # define OOP_CLASS_G_HIER_Arraydouble Arraydouble) OOP_CLASS_G_HIER_Arraydouble_CLASS OOP_CLASS_G_PARENT_Arraydouble 
 # define OOP_CLASS_G_PARENT_Arraydouble_CLASS Creatable) Creatable_CLASS) Initializable) Initializable_CLASS) Sequence) Sequence_CLASS) Collection) Collection_CLASS) Iterable) Iterable_CLASS) Container) Container_CLASS) Sized) Sized_CLASS) Reversible) Reversible_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_Arraydouble_CLASS Arraydouble_CLASS) OOP_CLASS_G_PARENT_Arraydouble_CLASS 
 # define OOP_MEMBERS_G_Arraydouble MEMBER_TYPE, (Arraydouble_CLASS * class__;, Arraydouble_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Arraydouble_CLASS *)) ) MEMBER_TYPE, (double * arr;, double *, arr, (OOP_NO_DEFAULT), sizeof(double *)) ) MEMBER_TYPE, (size_t size;, size_t, size, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (unsigned int reversed;, unsigned int, reversed, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) MEMBER_TYPE, (unsigned int flags;, unsigned int, flags, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) 
 # define OOP_MEMBERS_G_Arraydouble_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (int ( * get ) ( Arraydouble *, size_t, double * );, ftype_get_37, get, (Arraydouble_get), sizeof(void *), typedef int ( * ftype_get_37 ) ( Arraydouble *, size_t, double * );) ) CLASS_FUNCTION_TYPE, (bool ( * contains ) ( Arraydouble *, double );, ftype_contains_37, contains, (Arraydouble_contains), sizeof(void *), typedef bool ( * ftype_contains_37 ) ( Arraydouble *, double );) ) INTERFACE_TYPE, (Creatable Creatable__;, Creatable, Creatable__, ({ . new = Arraydouble_new, . del = Arraydouble_del, }), sizeof(Creatable)) ) INTERFACE_TYPE, (Initializable Initializable__;, Initializable, Initializable__, ({ . init = Arraydouble_init, }), sizeof(Initializable)) ) INTERFACE_TYPE, (Sequence Sequence__;, Sequence, Sequence__, ({ . get = NULL, .Collection__.Iterable__. iter = Arraydouble_iter, .Collection__.Container__. contains = NULL, .Collection__.Container__. is_empty = Arraydouble_is_empty, .Collection__.Sized__. len = Arraydouble_len, .Reversible__. reverse = Arraydouble_reverse, .Reversible__. reversed = Arraydouble_reversed, }), sizeof(Sequence)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Arraydouble 
 	 # define TYPEDEF_Arraydouble 
 typedef struct Arraydouble Arraydouble; 
 # endif 
 # ifndef TYPEDEF_Arraydouble_CLASS 
 	 # define TYPEDEF_Arraydouble_CLASS 
 typedef struct Arraydouble_CLASS Arraydouble_CLASS; 
 # endif 
 struct Arraydouble_CLASS { 
 	 void * class__; 
 	 int ( * get ) ( Arraydouble *, size_t, double * ); 
 	 bool ( * contains ) ( Arraydouble *, double ); 
 	 Creatable Creatable__; 
 	 Initializable Initializable__; 
 	 Sequence Sequence__; 
 }; 
 static Arraydouble_CLASS Arraydouble_CLASS__ = {.class__ = NULL, .get = Arraydouble_get, .contains = Arraydouble_contains, .Creatable__ = { . new = Arraydouble_new, . del = Arraydouble_del, }, .Initializable__ = { . init = Arraydouble_init, }, .Sequence__ = { . get = NULL, .Collection__.Iterable__. iter = Arraydouble_iter, .Collection__.Container__. contains = NULL, .Collection__.Container__. is_empty = Arraydouble_is_empty, .Collection__.Sized__. len = Arraydouble_len, .Reversible__. reverse = Arraydouble_reverse, .Reversible__. reversed = Arraydouble_reversed, }, }; 
 struct Arraydouble { 
 	 Arraydouble_CLASS * class__; 
 	 double * arr; 
 	 size_t size; 
 	 unsigned int reversed; 
 	 unsigned int flags; 
 
 }; 
 # endif 
 # ifndef OOP_MEMBER_ArraydoubleIterator 
 	 # define OOP_MEMBER_ArraydoubleIterator( x ) x 
 # endif 
 # ifndef OOP_MEMBER_ArraydoubleIterator_CLASS 
 	 # define OOP_MEMBER_ArraydoubleIterator_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_iable 
 	 # define OOP_MEMBER_iable( x ) x 
 # endif 
 # ifndef OOP_MEMBER_isl 
 	 # define OOP_MEMBER_isl( x ) x 
 # endif 
 # ifndef OOP_MEMBER_next 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_Iterator__ 
 	 # define OOP_MEMBER_Iterator__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_ArraydoubleIterator 
 # define OOP_CLASS_G_HIER_ArraydoubleIterator ArraydoubleIterator) OOP_CLASS_G_HIER_ArraydoubleIterator_CLASS OOP_CLASS_G_PARENT_ArraydoubleIterator 
 # define OOP_CLASS_G_PARENT_ArraydoubleIterator_CLASS Iterator) Iterator_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_ArraydoubleIterator_CLASS ArraydoubleIterator_CLASS) OOP_CLASS_G_PARENT_ArraydoubleIterator_CLASS 
 # define OOP_MEMBERS_G_ArraydoubleIterator MEMBER_TYPE, (ArraydoubleIterator_CLASS * class__;, ArraydoubleIterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(ArraydoubleIterator_CLASS *)) ) MEMBER_TYPE, (Arraydouble * iable;, Arraydouble *, iable, (OOP_NO_DEFAULT), sizeof(Arraydouble *)) ) MEMBER_TYPE, (SliceIterator isl;, SliceIterator, isl, (OOP_NO_DEFAULT), sizeof(SliceIterator)) ) 
 # define OOP_MEMBERS_G_ArraydoubleIterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (int ( * next ) ( ArraydoubleIterator *, double * );, ftype_next_37, next, (ArraydoubleIterator_next), sizeof(void *), typedef int ( * ftype_next_37 ) ( ArraydoubleIterator *, double * );) ) INTERFACE_TYPE, (Iterator Iterator__;, Iterator, Iterator__, ({ .Iterable__. iter = ArraydoubleIterator_iter, . next = NULL, }), sizeof(Iterator)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_ArraydoubleIterator 
 	 # define TYPEDEF_ArraydoubleIterator 
 typedef struct ArraydoubleIterator ArraydoubleIterator; 
 # endif 
 # ifndef TYPEDEF_ArraydoubleIterator_CLASS 
 	 # define TYPEDEF_ArraydoubleIterator_CLASS 
 typedef struct ArraydoubleIterator_CLASS ArraydoubleIterator_CLASS; 
 # endif 
 struct ArraydoubleIterator_CLASS { 
 	 void * class__; 
 	 int ( * next ) ( ArraydoubleIterator *, double * ); 
 	 Iterator Iterator__; 
 }; 
 static ArraydoubleIterator_CLASS ArraydoubleIterator_CLASS__ = {.class__ = NULL, .next = ArraydoubleIterator_next, .Iterator__ = { .Iterable__. iter = ArraydoubleIterator_iter, . next = NULL, }, }; 
 struct ArraydoubleIterator { 
 	 ArraydoubleIterator_CLASS * class__; 
 	 Arraydouble * iable; 
 	 SliceIterator isl; 
 
 }; 
 # endif
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Arrayvoid 
 	 # define TYPEDEF_Arrayvoid 
 typedef struct Arrayvoid Arrayvoid; 
 # endif 
 # ifndef TYPEDEF_ArrayvoidIterator 
 	 # define TYPEDEF_ArrayvoidIterator 
 typedef struct ArrayvoidIterator ArrayvoidIterator; 
 # endif 
 void Arrayvoid_init_(Arrayvoid *, void *, size_t, unsigned int, size_t); 
 int Arrayvoid_init(void *, unsigned int, ...); 
 Arrayvoid * Arrayvoid_new_(void *, size_t, unsigned int, size_t); 
 void * Arrayvoid_new(unsigned int, ...); 
 int Arrayvoid_del(void *); 
 int Arrayvoid_get(void *, size_t, void *); 
 bool Arrayvoid_contains(void *, void *); 
 int Arrayvoid_iter(void *, void *); 
 int ArrayvoidIterator_iter(void *, void *); 
 int ArrayvoidIterator_next(void *, void *); 
 size_t Arrayvoid_len(void *); 
 bool Arrayvoid_is_empty(void *); 
 int Arrayvoid_reverse(void *); 
 int Arrayvoid_reversed(void *, void *); 
 # endif 
 
 # ifndef OOP_MEMBER_Arrayvoid 
 	 # define OOP_MEMBER_Arrayvoid( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Arrayvoid_CLASS 
 	 # define OOP_MEMBER_Arrayvoid_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_arr 
 	 # define OOP_MEMBER_arr( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 	 # define OOP_MEMBER_size( x ) x 
 # endif 
 # ifndef OOP_MEMBER_el_size 
 	 # define OOP_MEMBER_el_size( x ) x 
 # endif 
 # ifndef OOP_MEMBER_reversed 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_flags 
 	 # define OOP_MEMBER_flags( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Creatable__ 
 	 # define OOP_MEMBER_Creatable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Initializable__ 
 	 # define OOP_MEMBER_Initializable__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Sequence__ 
 	 # define OOP_MEMBER_Sequence__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Arrayvoid 
 # define OOP_CLASS_G_HIER_Arrayvoid Arrayvoid) OOP_CLASS_G_HIER_Arrayvoid_CLASS OOP_CLASS_G_PARENT_Arrayvoid 
 # define OOP_CLASS_G_PARENT_Arrayvoid_CLASS Creatable) Creatable_CLASS) Initializable) Initializable_CLASS) Sequence) Sequence_CLASS) Collection) Collection_CLASS) Iterable) Iterable_CLASS) Container) Container_CLASS) Sized) Sized_CLASS) Reversible) Reversible_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_Arrayvoid_CLASS Arrayvoid_CLASS) OOP_CLASS_G_PARENT_Arrayvoid_CLASS 
 # define OOP_MEMBERS_G_Arrayvoid MEMBER_TYPE, (Arrayvoid_CLASS * class__;, Arrayvoid_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Arrayvoid_CLASS *)) ) MEMBER_TYPE, (void * arr;, void *, arr, (OOP_NO_DEFAULT), sizeof(void *)) ) MEMBER_TYPE, (size_t size;, size_t, size, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (size_t el_size;, size_t, el_size, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (unsigned int reversed;, unsigned int, reversed, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) MEMBER_TYPE, (unsigned int flags;, unsigned int, flags, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) 
 # define OOP_MEMBERS_G_Arrayvoid_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Creatable Creatable__;, Creatable, Creatable__, ({ . new = Arrayvoid_new, . del = Arrayvoid_del, }), sizeof(Creatable)) ) INTERFACE_TYPE, (Initializable Initializable__;, Initializable, Initializable__, ({ . init = Arrayvoid_init, }), sizeof(Initializable)) ) INTERFACE_TYPE, (Sequence Sequence__;, Sequence, Sequence__, ({ . get = Arrayvoid_get, .Collection__.Iterable__. iter = Arrayvoid_iter, .Collection__.Container__. contains = Arrayvoid_contains, .Collection__.Container__. is_empty = Arrayvoid_is_empty, .Collection__.Sized__. len = Arrayvoid_len, .Reversible__. reverse = Arrayvoid_reverse, .Reversible__. reversed = Arrayvoid_reversed, }), sizeof(Sequence)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Arrayvoid 
 	 # define TYPEDEF_Arrayvoid 
 typedef struct Arrayvoid Arrayvoid; 
 # endif 
 # ifndef TYPEDEF_Arrayvoid_CLASS 
 	 # define TYPEDEF_Arrayvoid_CLASS 
 typedef struct Arrayvoid_CLASS Arrayvoid_CLASS; 
 # endif 
 struct Arrayvoid_CLASS { 
 	 void * class__; 
 	 Creatable Creatable__; 
 	 Initializable Initializable__; 
 	 Sequence Sequence__; 
 }; 
 static Arrayvoid_CLASS Arrayvoid_CLASS__ = {.class__ = NULL, .Creatable__ = { . new = Arrayvoid_new, . del = Arrayvoid_del, }, .Initializable__ = { . init = Arrayvoid_init, }, .Sequence__ = { . get = Arrayvoid_get, .Collection__.Iterable__. iter = Arrayvoid_iter, .Collection__.Container__. contains = Arrayvoid_contains, .Collection__.Container__. is_empty = Arrayvoid_is_empty, .Collection__.Sized__. len = Arrayvoid_len, .Reversible__. reverse = Arrayvoid_reverse, .Reversible__. reversed = Arrayvoid_reversed, }, }; 
 struct Arrayvoid { 
 	 Arrayvoid_CLASS * class__; 
 	 void * arr; 
 	 size_t size; 
 	 size_t el_size; 
 	 unsigned int reversed; 
 	 unsigned int flags; 
 
 }; 
 # endif 
 # ifndef OOP_MEMBER_ArrayvoidIterator 
 	 # define OOP_MEMBER_ArrayvoidIterator( x ) x 
 # endif 
 # ifndef OOP_MEMBER_ArrayvoidIterator_CLASS 
 	 # define OOP_MEMBER_ArrayvoidIterator_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define x x 
 # endif 
 # ifndef OOP_MEMBER_iable 
 	 # define OOP_MEMBER_iable( x ) x 
 # endif 
 # ifndef OOP_MEMBER_isl 
 	 # define OOP_MEMBER_isl( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterator__ 
 	 # define OOP_MEMBER_Iterator__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_ArrayvoidIterator 
 # define OOP_CLASS_G_HIER_ArrayvoidIterator ArrayvoidIterator) OOP_CLASS_G_HIER_ArrayvoidIterator_CLASS OOP_CLASS_G_PARENT_ArrayvoidIterator 
 # define OOP_CLASS_G_PARENT_ArrayvoidIterator_CLASS Iterator) Iterator_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_ArrayvoidIterator_CLASS ArrayvoidIterator_CLASS) OOP_CLASS_G_PARENT_ArrayvoidIterator_CLASS 
 # define OOP_MEMBERS_G_ArrayvoidIterator MEMBER_TYPE, (ArrayvoidIterator_CLASS * class__;, ArrayvoidIterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(ArrayvoidIterator_CLASS *)) ) MEMBER_TYPE, (Arrayvoid * iable;, Arrayvoid *, iable, (OOP_NO_DEFAULT), sizeof(Arrayvoid *)) ) MEMBER_TYPE, (SliceIterator isl;, SliceIterator, isl, (OOP_NO_DEFAULT), sizeof(SliceIterator)) ) 
 # define OOP_MEMBERS_G_ArrayvoidIterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Iterator Iterator__;, Iterator, Iterator__, ({ .Iterable__. iter = ArrayvoidIterator_iter, . next = ArrayvoidIterator_next, }), sizeof(Iterator)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_ArrayvoidIterator 
 	 # define TYPEDEF_ArrayvoidIterator 
 typedef struct ArrayvoidIterator ArrayvoidIterator; 
 # endif 
 # ifndef TYPEDEF_ArrayvoidIterator_CLASS 
 	 # define TYPEDEF_ArrayvoidIterator_CLASS 
 typedef struct ArrayvoidIterator_CLASS ArrayvoidIterator_CLASS; 
 # endif 
 struct ArrayvoidIterator_CLASS { 
 	 void * class__; 
 	 Iterator Iterator__; 
 }; 
 static ArrayvoidIterator_CLASS ArrayvoidIterator_CLASS__ = {.class__ = NULL, .Iterator__ = { .Iterable__. iter = ArrayvoidIterator_iter, . next = ArrayvoidIterator_next, }, }; 
 struct ArrayvoidIterator { 
 	 ArrayvoidIterator_CLASS * class__; 
 	 Arrayvoid * iable; 
 	 SliceIterator isl; 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        