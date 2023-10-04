#include <oopc.h>
#define IMPORT_DECLARE_CALLABLE
#define OMIT_STRUCT_DECLS
#include <callable.def.h>
#include <callable.h>
#undef OMIT_STRUCT_DECLS

INCLUDE <callable.h>
INCLUDE_OOPC

IFNDEF FOOBAR_H
DEFINE FOOBAR_H

TYPEDEF(struct foobar, foobar)
void test_no_return(foobar *, int, float);
DECLARE_CALLABLE(foobar, void, test_no_return, foobar *, int, float)

CLASS(foobar,
    MEMBER(int, a)
    IMPLEMENTS(Callable, call, GET_CALLABLE(foobar, test_no_return))
)

TYPEDEF(struct foobar_return, foobar_return)
double test_return(foobar_return *, int, float);
DECLARE_CALLABLE(foobar_return, double, test_return, foobar_return *, int, float)

CLASS(foobar_return,
    MEMBER(int, b)
    IMPLEMENTS(Callable, call, GET_CALLABLE(foobar_return, test_return))
)
ENDIF // FOOBAR_H

