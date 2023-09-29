#include <oopc.h>
IFNDEF INITIALIZABLE_H
DEFINE INITIALIZABLE_H

INCLUDE_OOPC

DEFINE INIT(type, pinst, ...) SPLIT(OOP_INTERFACE)(type, *pinst, Initializable).init(pinst, SPLIT(VARIADIC_SIZE_T)(CATD(__VA, ARGS__, _)), CATD(__VA, ARGS__, _))

/**
 * @interface Initializable initializable.h
 * @brief interface for initializable structs.
 * 
 * @fn int init(unsigned int n, ...)
 * @brief instantiate a new object
 * @param[in, out] self - the object
 * @param[in] n - the number of arguments passed in the variadic
 * @param[in, out] ... - variable number of arguments to instantiate an object
 * @return indicator for success of the initialization (sufficient parameters)
 *  
 */
CLASS(Initializable,
    FUNCTION(NULL, int, init, void *, unsigned int, ...)
)

ENDIF
