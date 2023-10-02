#include <oopc.h>

IFNDEF FOOBAR_H
DEFINE FOOBAR_H
#define OMIT_STRUCT_DECLS
#include <reversible.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <reversible.h>
INCLUDE_OOPC

int FooBar_iter(void *, void *);
int FooBarIterator_iter(void *, void *);
void * FooBarIterator_next(void *);
int FooBarIterator_stop(void *);
int FooBar_reverse(void *);
int FooBar_reversed(void *, void *);

CLASS(FooBar,
    MEMBER(char *, str)
    MEMBER(int, reversed)
    IMPLEMENTS(Reversible, reverse, FooBar_reverse, reversed, FooBar_reversed, iter, FooBar_iter)
)

CLASS(FooBarIterator,
    MEMBER(FooBar *, fb)
    MEMBER(char *, pccur)
    MEMBER(char *, pcstop)
    MEMBER(enum iterator_status, stop)
    IMPLEMENTS(Iterator, next, FooBarIterator_next, stop, FooBarIterator_stop, iter, FooBarIterator_iter)
)

ENDIF
