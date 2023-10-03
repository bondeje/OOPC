 # ifndef TEMPLATE_ARRAY_H   
 # define TEMPLATE_ARRAY_H   
 # include <oopc.h>   
 # include <stddef.h>   
 # include <stdarg.h>   
 # include <stdlib.h>   
 # include <stdbool.h>   
 # include <string.h>   
 # include <creatable.h>   
 # include <initializable.h>   
 # include <sequence.h>   
 # define ARRAY_DEFAULT_FLAGS 0x00   
 # define ARRAY_MALLOC_ARRAY 0x01   
 # define ARRAY_SUCCESS 0   
 # define ARRAY_FAILURE 1   
 # ifndef TYPEDEF_Array 
     # define TYPEDEF_Array 
 typedef struct Array Array; 
 # endif 
 void Array_init_(Array *, void * *, size_t, size_t, unsigned int); 
 int Array_init(void *, unsigned int, ...); 
 Array * Array_new_(void * *, size_t, size_t, unsigned int); 
 void * Array_new(unsigned int, ...); 
 int Array_del(void *); 
 void * Array_get(void *, size_t); 
 _Bool Array_contains(void *, void*); 
 int Array_iter(void *, void *); 
 int ArrayIterator_iter(void *, void *); 
 void * ArrayIterator_next(void *); 
 int ArrayIterator_stop(void *); 
 size_t Array_len(void *); 
 int Array_reverse(void *); 
 int Array_reversed(void *, void *); 
 
 # define Array(type) Arraytype 
 # ifndef OOP_MEMBER_Array 
     # define OOP_MEMBER_Array( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Array_CLASS 
     # define OOP_MEMBER_Array_CLASS( x ) x 
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
 # ifndef OOP_MEMBER_cap 
     # define OOP_MEMBER_cap( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
     # define OOP_MEMBER_size( x ) x 
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
     # define x x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Array 
 # define OOP_CLASS_G_HIER_Array Array) OOP_CLASS_G_HIER_Array_CLASS OOP_CLASS_G_PARENT_Array 
 # define OOP_CLASS_G_PARENT_Array_CLASS Creatable) Creatable_CLASS) Initializable) Initializable_CLASS) Sequence) Sequence_CLASS) Collection) Collection_CLASS) Iterable) Iterable_CLASS) Container) Container_CLASS) Sized) Sized_CLASS) Reversible) Reversible_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_Array_CLASS Array_CLASS) OOP_CLASS_G_PARENT_Array_CLASS 
 # define OOP_MEMBERS_G_Array MEMBER_TYPE, (Array_CLASS * class__;, Array_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Array_CLASS *)) ) MEMBER_TYPE, (void * * arr;, void * *, arr, (OOP_NO_DEFAULT), sizeof(void * *)) ) MEMBER_TYPE, (size_t cap;, size_t, cap, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (size_t size;, size_t, size, (OOP_NO_DEFAULT), sizeof(size_t)) ) MEMBER_TYPE, (unsigned int flags;, unsigned int, flags, (OOP_NO_DEFAULT), sizeof(unsigned int)) ) 
 # define OOP_MEMBERS_G_Array_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Creatable Creatable__;, Creatable, Creatable__, ({ . new = Array_new, . del = Array_del, }), sizeof(Creatable)) ) INTERFACE_TYPE, (Initializable Initializable__;, Initializable, Initializable__, ({ . init = Array_init, }), sizeof(Initializable)) ) INTERFACE_TYPE, (Sequence Sequence__;, Sequence, Sequence__, ({ . get = Array_get, .Collection__.Iterable__. iter = Array_iter, .Collection__.Container__. contains = Array_contains, .Collection__.Sized__. len = Array_len, .Reversible__. reverse = Array_reverse, .Reversible__. reversed = Array_reversed, }), sizeof(Sequence)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
 # ifndef TYPEDEF_Array 
     # define TYPEDEF_Array 
 typedef struct Array Array; 
 # endif 
 # ifndef TYPEDEF_Array_CLASS 
     # define TYPEDEF_Array_CLASS 
 typedef struct Array_CLASS Array_CLASS; 
 # endif 
 struct Array_CLASS { 
     void * class__; 
     Creatable Creatable__; 
     Initializable Initializable__; 
     Sequence Sequence__; 
 }; 
 static Array_CLASS Array_CLASS__ = {.class__ = NULL, .Creatable__ = { . new = Array_new, . del = Array_del, }, .Initializable__ = { . init = Array_init, }, .Sequence__ = { . get = Array_get, .Collection__.Iterable__. iter = Array_iter, .Collection__.Container__. contains = Array_contains, .Collection__.Sized__. len = Array_len, .Reversible__. reverse = Array_reverse, .Reversible__. reversed = Array_reversed, }, }; 
 struct Array { 
     Array_CLASS * class__; 
     void * * arr; 
     size_t cap; 
     size_t size; 
     unsigned int flags; 
 
 }; 
 # endif 
 # ifndef OOP_MEMBER_ArrayIterator 
     # define OOP_MEMBER_ArrayIterator( x ) x 
 # endif 
 # ifndef OOP_MEMBER_ArrayIterator_CLASS 
     # define OOP_MEMBER_ArrayIterator_CLASS( x ) x 
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
 # ifndef OOP_MEMBER_Iterator__ 
     # define OOP_MEMBER_Iterator__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_ArrayIterator 
 # define OOP_CLASS_G_HIER_ArrayIterator ArrayIterator) OOP_CLASS_G_HIER_ArrayIterator_CLASS OOP_CLASS_G_PARENT_ArrayIterator 
 # define OOP_CLASS_G_PARENT_ArrayIterator_CLASS Iterator) Iterator_CLASS) Iterable) Iterable_CLASS) 
 # define OOP_CLASS_G_HIER_ArrayIterator_CLASS ArrayIterator_CLASS) OOP_CLASS_G_PARENT_ArrayIterator_CLASS 
 # define OOP_MEMBERS_G_ArrayIterator MEMBER_TYPE, (ArrayIterator_CLASS * class__;, ArrayIterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(ArrayIterator_CLASS *)) ) MEMBER_TYPE, (Array * iable;, Array *, iable, (OOP_NO_DEFAULT), sizeof(Array *)) ) 
 # define OOP_MEMBERS_G_ArrayIterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (Iterator Iterator__;, Iterator, Iterator__, ({ .Iterable__. iter = ArrayIterator_iter, . next = ArrayIterator_next, . stop = ArrayIterator_stop, }), sizeof(Iterator)) ) 
 
 # ifndef OMIT_STRUCT_DECLS 
 # ifndef TYPEDEF_ArrayIterator 
     # define TYPEDEF_ArrayIterator 
 typedef struct ArrayIterator ArrayIterator; 
 # endif 
 # ifndef TYPEDEF_ArrayIterator_CLASS 
     # define TYPEDEF_ArrayIterator_CLASS 
 typedef struct ArrayIterator_CLASS ArrayIterator_CLASS; 
 # endif 
 struct ArrayIterator_CLASS { 
     void * class__; 
     Iterator Iterator__; 
 }; 
 static ArrayIterator_CLASS ArrayIterator_CLASS__ = {.class__ = NULL, .Iterator__ = { .Iterable__. iter = ArrayIterator_iter, . next = ArrayIterator_next, . stop = ArrayIterator_stop, }, }; 
 struct ArrayIterator { 
     ArrayIterator_CLASS * class__; 
     Array * iable; 
 
 }; 
 # endif   
 # endif   
