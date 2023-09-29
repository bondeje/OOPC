#include <oopc.h>
IFNDEF CONTAINER_H
DEFINE CONTAINER_H

INCLUDE <stdbool.h>
INCLUDE <creatable.h>
INCLUDE_OOPC

CLASS(Container,
    FUNCTION(NULL, bool, contains, void *, void *)
    EXTENDS(Creatable)
)

ENDIF // CONTAINER_H