#include <oopc.h>
#define IMPORT_CLASS_DEFS_ONLY
#include <initializable.h>
#undef IMPORT_CLASS_DEFS_ONLY
IFNDEF IMPORT_CLASS_DEFS_ONLY
INCLUDE <initializable.h>
INCLUDE_OOPC

int FooBar_init(void *, unsigned int, ...);
ENDIF /* IMPORT_CLASS_DEFS_ONLY */

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Initializable, init, FooBar_init)
)
