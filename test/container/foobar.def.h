#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <container.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <container.h>
INCLUDE <stdbool.h>
INCLUDE_OOPC

bool FooBar_contains(void *, void *);
bool FooBar_is_empty(void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Container, contains, FooBar_contains, is_empty, FooBar_is_empty)
)
