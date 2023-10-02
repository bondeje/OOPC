#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <container.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <container.h>
INCLUDE_OOPC

bool FooBar_contains(void *, void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Container, contains, FooBar_contains)
)
