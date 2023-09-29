#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <creatable.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <creatable.h>
INCLUDE_OOPC

int FooBar_init(void *, unsigned int, ...);
void * FooBar_new(unsigned int, ...);
int FooBar_del(void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Creatable, new, FooBar_new, del, FooBar_del, init, FooBar_init)
)
