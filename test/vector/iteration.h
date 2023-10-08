 # ifndef ITERATION_H
 # define ITERATION_H
 # include <oopc.h>
 # ifndef IMPORT_CLASS_DEFS_ONLY
enum iterator_status {
    ITERATOR_FAIL = -1,
    ITERATOR_GO,
    ITERATOR_STOP,
    ITERATOR_PAUSE,
    ITERATOR_STOP_1
};
 # endif
 # define ITER(IterableType, pinst, piterator) OOP_GET (IterableType, *pinst, iter)(pinst, piterator)
 # define NEXT(IteratorType, pinst, pdest) OOP_GET (IteratorType, *pinst, next)(pinst, pdest)
 # define FOR_EACH(el_type, el_name, IterableType, pIterableInstance, IteratorType) el_type el_name; IteratorType OOP_UNIQUE_VAR_NAME (CATD (IteratorType, el_name, _)); ITER(IterableType, pIterableInstance, &(OOP_UNIQUE_VAR_NAME (CATD (IteratorType, el_name, _)))); for (; !NEXT(IteratorType, &OOP_UNIQUE_VAR_NAME (CATD (IteratorType, el_name, _)), &el_name); )
 # ifndef OOP_MEMBER_Iterable 
 	 # define OOP_MEMBER_Iterable( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterable_CLASS 
 	 # define OOP_MEMBER_Iterable_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_iter 
 	 # define OOP_MEMBER_iter( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Iterable 
 # define OOP_CLASS_G_HIER_Iterable Iterable) OOP_CLASS_G_HIER_Iterable_CLASS OOP_CLASS_G_PARENT_Iterable 
 # define OOP_CLASS_G_PARENT_Iterable_CLASS 
 # define OOP_CLASS_G_HIER_Iterable_CLASS Iterable_CLASS) OOP_CLASS_G_PARENT_Iterable_CLASS 
 # define OOP_MEMBERS_G_Iterable MEMBER_TYPE, (Iterable_CLASS * class__;, Iterable_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Iterable_CLASS *)) ) FUNCTION_TYPE, (int ( * iter ) ( void *, void * );, ftype_iter_28, iter, (NULL), sizeof(void*), typedef int ( * ftype_iter_28 ) ( void *, void * );) ) 
 # define OOP_MEMBERS_G_Iterable_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Iterable 
 	 # define TYPEDEF_Iterable 
 typedef struct Iterable Iterable; 
 # endif 
 # ifndef TYPEDEF_Iterable_CLASS 
 	 # define TYPEDEF_Iterable_CLASS 
 typedef struct Iterable_CLASS Iterable_CLASS; 
 # endif 
 struct Iterable_CLASS { 
 	 void * class__; 
 }; 
 static Iterable_CLASS Iterable_CLASS__ = {.class__ = NULL, }; 
 struct Iterable { 
 	 Iterable_CLASS * class__; 
 	 int ( * iter ) ( void *, void * ); 
 
 }; 
 # endif
 # ifndef OOP_MEMBER_Iterator 
 	 # define OOP_MEMBER_Iterator( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterator_CLASS 
 	 # define OOP_MEMBER_Iterator_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
 	 # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_next 
 	 # define OOP_MEMBER_next( x ) x 
 # endif 
 # ifndef OOP_MEMBER_Iterable__ 
 	 # define OOP_MEMBER_Iterable__( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_Iterator OOP_CLASS_G_HIER_Iterable 
 # define OOP_CLASS_G_HIER_Iterator Iterator) OOP_CLASS_G_HIER_Iterator_CLASS OOP_CLASS_G_PARENT_Iterator 
 # define OOP_CLASS_G_PARENT_Iterator_CLASS 
 # define OOP_CLASS_G_HIER_Iterator_CLASS Iterator_CLASS) OOP_CLASS_G_PARENT_Iterator_CLASS 
 # define OOP_MEMBERS_G_Iterator MEMBER_TYPE, (Iterator_CLASS * class__;, Iterator_CLASS *, class__, (OOP_NO_DEFAULT), sizeof(Iterator_CLASS *)) ) FUNCTION_TYPE, (int ( * next ) ( void *, void * );, ftype_next_35, next, (NULL), sizeof(void*), typedef int ( * ftype_next_35 ) ( void *, void * );) ) PARENT_TYPE, (Iterable Iterable__;, Iterable, Iterable__, (OOP_NO_DEFAULT), sizeof(Iterable)) ) 
 # define OOP_MEMBERS_G_Iterator_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef IMPORT_CLASS_DEFS_ONLY 
 # ifndef TYPEDEF_Iterator 
 	 # define TYPEDEF_Iterator 
 typedef struct Iterator Iterator; 
 # endif 
 # ifndef TYPEDEF_Iterator_CLASS 
 	 # define TYPEDEF_Iterator_CLASS 
 typedef struct Iterator_CLASS Iterator_CLASS; 
 # endif 
 struct Iterator_CLASS { 
 	 void * class__; 
 }; 
 static Iterator_CLASS Iterator_CLASS__ = {.class__ = NULL, }; 
 struct Iterator { 
 	 Iterator_CLASS * class__; 
 	 int ( * next ) ( void *, void * ); 
 	 Iterable Iterable__; 
 
 }; 
 # endif
 # endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                