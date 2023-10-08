#include <oopc.h>
#define IMPORT_DECLARE_CALLABLE
#include <callable.def.h>
#define IMPORT_CLASS_DEFS_ONLY
#include <callable.h>
#undef IMPORT_CLASS_DEFS_ONLY

IFNDEF FOOBAR_H
DEFINE FOOBAR_H

IFNDEF IMPORT_CLASS_DEFS_ONLY

INCLUDE <callable.h>
INCLUDE_OOPC

TYPEDEF(struct foobar, foobar)
void test_no_return(foobar *, int, float);

TYPEDEF(struct foobar_return, foobar_return)
double test_return(foobar_return *, int, float);

ENDIF /* IMPORT_CLASS_DEFS_ONLY */

DECLARE_CALLABLE(foobar, void, test_no_return, foobar *, int, float)
CLASS(foobar,
    MEMBER(int, a)
    IMPLEMENTS(Callable, call, GET_CALLABLE(foobar, test_no_return))
)

DECLARE_CALLABLE(foobar_return, double, test_return, foobar_return *, int, float)
CLASS(foobar_return,
    MEMBER(int, b)
    IMPLEMENTS(Callable, call, GET_CALLABLE(foobar_return, test_return))
)

ENDIF // FOOBAR_H

