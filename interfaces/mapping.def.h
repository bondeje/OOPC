#include <oopc.h>
IFNDEF MAPPING_H
DEFINE MAPPING_H

INCLUDE <collection.h>
INCLUDE <comparable.h>

CLASS(MappingItem,
    MEMBER(const void *, key)
    MEMBER(void *, value)
)

CLASS(Mapping,
    FUNCTION()
    EXTENDS(Collection)
    EXTENDS(Comparable)
)

ENDIF // MAPPING_H
