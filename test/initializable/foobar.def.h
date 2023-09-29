#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <initializable.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <initializable.h>
INCLUDE_OOPC

int FooBar_init(void *, unsigned int, ...);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Initializable, init, FooBar_init)
)
