#include <oopc.h>
IFNDEF PRINTABLE_H
DEFINE PRINTABLE_H

INCLUDE <stddef.h>
INCLUDE_OOP

/**
 * @interface Printable printable.h
 * @brief interface for printable structs
 * 
 * @fn long c_str(void * self, char * buffer, size_t buffer_size)
 * @brief store printable c-string representation of \p self in \p buffer
 * @param[in] self - object to be stored in c-string
 * @param[out] buffer - the destination
 * @param[in] buffer_size - the size of the \p buffer provided
 * @return length of c-string (null-terminated, not included in count) representation of \p self. Negative if \p buffer is of insufficient size. 0 for invalid \p self. Specifically if \p buffer is NULL, returns -1 * (length of buffer required - 1)
 *  
 */
CLASS(Printable,
    FUNCTION(NULL, long, c_str, void *, char *, size_t)
)

ENDIF // PRINTABLE_H