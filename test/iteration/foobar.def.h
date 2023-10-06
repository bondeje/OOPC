#include <oopc.h>

IFNDEF FOOBAR_H
DEFINE FOOBAR_H
#define OMIT_STRUCT_DECLS
#include <iteration.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <iteration.h>
INCLUDE_OOPC

int FooBar_iter(void *, void *);
int FooBarIterator_iter(void *, void *);
int FooBarIterator_next(void *, void *);
int FooBarIterator_stop(void *);

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Iterable, iter, FooBar_iter)
)

CLASS(FooBarIterator,
    MEMBER(FooBar *, fb)
    MEMBER(char *, pc)
    MEMBER(enum iterator_status, stop_)
    IMPLEMENTS(Iterator, next, FooBarIterator_next, stop, FooBarIterator_stop, iter, FooBarIterator_iter)
)

ENDIF
