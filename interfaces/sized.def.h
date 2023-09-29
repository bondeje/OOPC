#include <oopc.h>
IFNDEF SIZED_H
DEFINE SIZED_H

IFNDEF OMIT_STRUCT_DECLS
INCLUDE <stddef.h>
ENDIF
INCLUDE_OOPC

DEFINE LEN(type, pinst) SPLIT(OOP_INTERFACE)(type, *pinst, Sized).len(pinst)

CLASS(Sized,
    FUNCTION(NULL, size_t, len, void *)
)

ENDIF // SIZED_H
