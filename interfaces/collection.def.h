#include <oopc.h>
IFNDEF COLLECTION_H
DEFINE COLLECTION_H

INCLUDE <sized.h>
INCLUDE <iteration.h>
INCLUDE <container.h>
INCLUDE_OOPC

CLASS(Collection, 
    EXTENDS(Iterable)
    EXTENDS(Container)
    EXTENDS(Sized)
)

ENDIF // COLLECTIONS_H
