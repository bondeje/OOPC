#include <oopc.h>

IFNDEF FOOBAR_H
DEFINE FOOBAR_H
#define IMPORT_CLASS_DEFS_ONLY
#include <iteration.h>
#undef IMPORT_CLASS_DEFS_ONLY
IFNDEF IMPORT_CLASS_DEFS_ONLY
INCLUDE <iteration.h>
INCLUDE_OOPC

int FooBar_iter(void *, void *);
int FooBarIterator_iter(void *, void *);
int FooBarIterator_next(void *, void *);
ENDIF /* IMPORT_CLASS_DEFS_ONLY */

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Iterable, iter, FooBar_iter)
)

CLASS(FooBarIterator,
    MEMBER(FooBar *, fb)
    MEMBER(char *, pc)
    IMPLEMENTS(Iterator, next, FooBarIterator_next, iter, FooBarIterator_iter)
)

ENDIF
