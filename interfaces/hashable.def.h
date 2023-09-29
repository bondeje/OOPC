#include <oopc.h>
IFNDEF HASHABLE_H
DEFINE HASHABLE_H

INCLUDE_OOPC
INCLUDE <stdint.h>

// note that there should be a macro configuration to select the type that the implementation/target is capable of handling since uint64_t may not exist

// there should be a default HASH implementation that hashes on the pointer itself, but it is almost guaranteed to not be portable
CLASS(Hashable,
    FUNCTION(NULL, uint64_t, hash, void *)
)

ENDIF // HASHABLE_H
