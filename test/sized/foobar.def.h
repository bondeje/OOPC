#include <oopc.h>
#define IMPORT_CLASS_DEFS_ONLY
#include <sized.h>
#undef IMPORT_CLASS_DEFS_ONLY
INCLUDE <sized.h>
INCLUDE_OOPC
  
IFNDEF IMPORT_CLASS_DEFS_ONLY
size_t FooBar_len(void *);
ENDIF /* IMPORT_CLASS_DEFS_ONLY */

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Sized, len, FooBar_len)
)
