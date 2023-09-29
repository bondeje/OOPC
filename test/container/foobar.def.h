#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <container.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <container.h>
INCLUDE_OOPC

int FooBar_init(void *, unsigned int, ...);
void * FooBar_new(unsigned int, ...);
int FooBar_del(void *);
bool FooBar_contains(void *, void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Container, contains, FooBar_contains, new, FooBar_new, del, FooBar_del, init, FooBar_init)
)
