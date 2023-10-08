#include <oopc.h>

IFNDEF FOOBAR_H
DEFINE FOOBAR_H
#define IMPORT_CLASS_DEFS_ONLY
#include <reversible.h>
#undef IMPORT_CLASS_DEFS_ONLY
IFNDEF IMPORT_CLASS_DEFS_ONLY
INCLUDE <reversible.h>
INCLUDE_OOPC

int FooBar_iter(void *, void *);
int FooBarIterator_iter(void *, void *);
int FooBarIterator_next(void *, void *);
int FooBar_reverse(void *);
int FooBar_reversed(void *, void *);

ENDIF /* IMPORT_CLASS_DEFS_ONLY */

CLASS(FooBar,
    MEMBER(char *, str)
    MEMBER(int, reversed)
    IMPLEMENTS(Reversible, reverse, FooBar_reverse, reversed, FooBar_reversed, iter, FooBar_iter)
)

CLASS(FooBarIterator,
    MEMBER(FooBar *, fb)
    MEMBER(char *, pccur)
    MEMBER(char *, pcstop)
    IMPLEMENTS(Iterator, next, FooBarIterator_next, iter, FooBarIterator_iter)
)

ENDIF
