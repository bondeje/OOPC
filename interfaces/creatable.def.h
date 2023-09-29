#include <oopc.h>
IFNDEF CREATABLE_H
DEFINE CREATABLE_H

INCLUDE <initializable.h>
INCLUDE_OOPC

/** convenience macros for creating, instantiating, and deleting an instance. Only works if type implements creatable as an interface */
DEFINE NEW(type, ...) SPLIT(OOP_INTERFACE)(SPLIT(CLASS_MANGLE)(type), SPLIT(TYPE_NAME)(SPLIT(CLASS_MANGLE)(type)), Creatable).new(SPLIT(VARIADIC_SIZE_T)(CATD(__VA, ARGS__, _)), CATD(__VA, ARGS__, _))
DEFINE DEL(type, pinst) SPLIT(OOP_INTERFACE)(type, *pinst, Creatable).del(pinst)

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
 * @fn int del(void * self)
 * @brief delete an object created with new
 * @param[in] self - the object
 * @return indicator for success of the deletion (valid object)
 * 
 * @details functions for creating, instantiating and cleaning up objects on the heap. The init is 
 * also useful for non-heap application. This is meant to be an interface and never part of an 
 * instantiable object. If the object you are defining is an interface, OK to put in as an object 
 * member, but if it is instantiable, implement as interface.
 *  
 */
CLASS(Creatable,
    FUNCTION(NULL, void *, new, unsigned int, ...)
    FUNCTION(NULL, int, del, void *)
    EXTENDS(Initializable)
)

ENDIF // CREATABLE_H