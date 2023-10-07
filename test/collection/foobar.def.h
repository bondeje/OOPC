#include <oopc.h>

IFNDEF FOOBAR_H
DEFINE FOOBAR_H
#define OMIT_STRUCT_DECLS
#include <iteration.h>
#include <container.h>
#include <sized.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <iteration.h>
INCLUDE <container.h>
INCLUDE <sized.h>
IFNDEF OMIT_STRUCT_DECLS
INCLUDE <stddef.h>
ENDIF
INCLUDE_OOPC

// iteration.h
int FooBar_iter(void *, void *);
int FooBarIterator_iter(void *, void *);
int FooBarIterator_next(void *, void *);

// container.h
bool FooBar_contains(void *, void *);
// container.creatable.h
void * FooBar_new(unsigned int, ...);
int FooBar_del(void *);
// container.creatable.initializable.h
int FooBar_init(void *, unsigned int, ...);

// sized.h
size_t FooBar_len(void *);

static inline bool FooBar_is_empty(void * st_) {
    return FooBar_len(st_) == 0;
}

CLASS(FooBar,
    MEMBER(char *, str)
    IMPLEMENTS(Iterable, iter, FooBar_iter)
    IMPLEMENTS(Container, contains, FooBar_contains, is_empty, FooBar_is_empty)
    IMPLEMENTS(Sized, len, FooBar_len)
)

CLASS(FooBarIterator,
    MEMBER(FooBar *, fb)
    MEMBER(char *, pc)
    IMPLEMENTS(Iterator, next, FooBarIterator_next, iter, FooBarIterator_iter)
)

ENDIF
