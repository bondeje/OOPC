#include <oopc.h>
IFNDEF CREATABLE_H
DEFINE CREATABLE_H

INCLUDE <allocatable.h>
INCLUDE <initializable.h>
INCLUDE_OOPC

/** convenience macros for creating, instantiating, and deleting an instance. Only works if type implements creatable as an interface */
DEFINE NEW(type, ...) (type *) SPLIT(OOP_INTERFACE)(type, inst, Creatable).new(SPLIT(VARIADIC_SIZE)(CATD(__VA, ARGS__, _)), CATD(__VA, ARGS__, _))
DEFINE INIT(type, pinst, ...) SPLIT(OOP_INTERFACE)(type, inst, Creatable).init(pinst, SPLIT(VARIADIC_SIZE)(CATD(__VA, ARGS__, _)), CATD(__VA, ARGS__, _))
DEFINE DEL(type, pinst) SPLIT(OOP_INTERFACE)(type, inst, Creatable).del(pinst)

/**
 * @interface Creatable creatable.h
 * @brief interface for creatable structs.
 * 
 * @fn void * new(void * self, unsigned int n, ...)
 * @brief create a new object on the heap
 * @param[in] n - the number of arguments passed in the variadic
 * @param[in, out] ... - variable number of arguments to instantiate object *  
 * @return new object
 * 
 * @fn void init(unsigned int n, ...)
 * @brief instantiate a new object
 * @param[in, out] self - the object
 * @param[in] n - the number of arguments passed in the variadic
 * @param[in, out] ... - variable number of arguments to instantiate an object
 *  
 * @fn void del(void * self)
 * @brief delete an object created with new
 * @param[in] self - the object
 * 
 * @details functions for creating, instantiating and cleaning up objects on the heap. The init is 
 * also useful for non-heap application. This is meant to be an interface and never part of an 
 * instantiable object. If the object you are defining is an interface, OK to put in as an object 
 * member, but if it is instantiable, implement as interface.
 *  
 */
CLASS(Creatable,
    FUNCTION(NULL, void *, new, unsigned int, ...)
    FUNCTION(NULL, void, init, void *, unsigned int, ...)
    FUNCTION(NULL, void, del, void *)
    EXTENDS(Allocatable)
    EXTENDS(Initializable)
)

ENDIF // CREATABLE_H