#include <oopc.h>
#define IMPORT_CLASS_DEFS_ONLY
#include <creatable.h>
#include <initializable.h>
#undef IMPORT_CLASS_DEFS_ONLY

IFNDEF IMPORT_CLASS_DEFS_ONLY
INCLUDE <creatable.h>
INCLUDE <initializable.h>
INCLUDE_OOPC

int FooBar_init(void *, unsigned int, ...);
void * FooBar_new(unsigned int, ...);
int FooBar_del(void *);

ENDIF /* IMPORT_CLASS_DEFS_ONLY */

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Creatable, new, FooBar_new, del, FooBar_del)
    IMPLEMENTS(Initializable, init, FooBar_init)
)
