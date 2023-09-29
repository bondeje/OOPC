#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <sized.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <sized.h>
INCLUDE_OOPC
  
size_t FooBar_len(void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Sized, len, FooBar_len)
)
