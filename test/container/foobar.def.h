#include <oopc.h>
#define IMPORT_CLASS_DEFS_ONLY
#include <container.h>
#undef IMPORT_CLASS_DEFS_ONLY
IFNDEF IMPORT_CLASS_DEFS_ONLY
INCLUDE <container.h>
INCLUDE <stdbool.h>
INCLUDE_OOPC
ENDIF

bool FooBar_contains(void *, void *);
bool FooBar_is_empty(void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Container, contains, FooBar_contains, is_empty, FooBar_is_empty)
)
