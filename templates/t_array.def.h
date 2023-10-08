#include <templates.h>

/**
 * NOTE: in templates, you normally cannot directly #include <oopc.h> since many <oopc.h> macros 
 * depend on what the inputs in the top-level macro are. If #include <oopc.h> is present, the 
 * macros must escape <oopc.h> macros
 */

#define Array(el_type) Array##el_type
#define ArrayIterator(el_type) Array##el_type##Iterator

#define TEMPLATE_Array(el_type) TEMPLATE_Array_(Array##el_type, el_type)
#define TEMPLATE_Array_(name, el_type) \
IFNDEF IMPORT_CLASS_DEFS_ONLY \
OOP_NEWLINE \
TYPEDEF(struct name, name) OOP_NEWLINE \
TYPEDEF(struct name##Iterator, name##Iterator) OOP_NEWLINE \
void name##_init_(name *, el_type *, size_t, unsigned int, size_t);  OOP_NEWLINE \
int name##_init(void *, unsigned int, ...); OOP_NEWLINE \
name * name##_new_(el_type *, size_t, unsigned int, size_t);  OOP_NEWLINE \
void * name##_new(unsigned int, ...);  OOP_NEWLINE \
int name##_del(void *);  OOP_NEWLINE \
int name##_get(OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, name) *, size_t, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, el_type) *);  OOP_NEWLINE \
bool name##_contains(OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, name) *, OOP_IF(EQUAL(el_type, void))(void *, el_type)); OOP_NEWLINE \
int name##_iter(void *, void *); OOP_NEWLINE \
int name##Iterator_iter(void *, void *); OOP_NEWLINE \
int name##Iterator_next(OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, name##Iterator) *, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, el_type) *); OOP_NEWLINE \
size_t name##_len(void *); OOP_NEWLINE \
bool name##_is_empty(void *); OOP_NEWLINE \
int name##_reverse(void *); OOP_NEWLINE \
int name##_reversed(void *, void *); OOP_NEWLINE \
ENDIF /* IMPORT_CLASS_DEFS_ONLY */ \
OOP_NEWLINE \
OOP_NEWLINE \
CLASS(name, \
    MEMBER(el_type *, arr) \
    MEMBER(size_t, size) \
    OOP_IF(EQUAL(el_type, void))(MEMBER(size_t, el_size), ) \
    MEMBER(unsigned int, reversed) \
    MEMBER(unsigned int, flags) \
    OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))( , CLASS_FUNCTION(name##_get, int, get, name *, size_t, el_type *)) \
    OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))( , CLASS_FUNCTION(name##_contains, bool, contains, name *, el_type)) \
    IMPLEMENTS(Creatable, new, name##_new, del, name##_del) \
    IMPLEMENTS(Initializable, init, name##_init) \
    IMPLEMENTS(Sequence, get, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(name##_get, NULL), iter, name##_iter, contains, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(name##_contains, NULL), is_empty, name##_is_empty, len, name##_len, reverse, name##_reverse, reversed, name##_reversed) \
) \
OOP_NEWLINE \
CLASS(name##Iterator, \
    MEMBER(name *, iable) \
    MEMBER(SliceIterator, isl) \
    OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))( , CLASS_FUNCTION(name##Iterator_next, int, next, name##Iterator *, el_type *)) \
    IMPLEMENTS(Iterator, iter, name##Iterator_iter, next, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(name##Iterator_next, NULL)) \
)

#define TEMPLATE_IMPLEMENTATION_Array(el_type) TEMPLATE_IMPLEMENTATION_Array_(Array##el_type, el_type)
#define TEMPLATE_IMPLEMENTATION_Array_(name, el_type) \
void name##_init_(name * iable, el_type * arr, size_t size, unsigned int flags, size_t el_size) { \
    iable->arr = arr; \
    iable->size = size; \
    iable->reversed = 0; \
    iable->flags = flags; \
    OOP_IF(EQUAL(el_type, void))(iable->el_size = el_size, ); \
} \
int name##_init(void * iable, unsigned int n, ...) { \
    if (n > 1) { \
        va_list args; \
        va_start(args, n); \
        el_type * arr = va_arg(args, el_type *); \
        size_t size = va_arg(args, size_t); \
        size_t el_size = OOP_IF(EQUAL(el_type, void))(0, sizeof(el_type)); \
        unsigned int flags = ARRAY_DEFAULT_FLAGS; \
        if (n > 2) { \
            flags = va_arg(args, unsigned int); \
        } \
        OOP_IF(EQUAL(el_type, void))(if (n > 3) {el_size = va_arg(args, size_t); }, ) \
        va_end(args); \
        name##_init_(iable, arr, size, flags, el_size); \
        return ARRAY_SUCCESS; \
    } \
    return ARRAY_FAILURE; \
} \
name * name##_new_(el_type * arr, size_t size, unsigned int flags, size_t el_size) { \
    name * st = (name *) malloc(sizeof(name)); \
    if (!st) { \
        return NULL; \
    } \
    if (!arr) { \
        el_type * arr = (el_type *) calloc(size, el_size ); \
        if (!arr) { \
            free(st); \
            return NULL; \
        } \
        flags |= ARRAY_MALLOC_ARRAY; \
    } else { \
        flags &= ~ARRAY_MALLOC_ARRAY; \
    } \
    OOP_INIT(name, *st); \
    name##_init_(st, arr, size, flags, el_size); \
    return st; \
} \
void * name##_new(unsigned int n, ...) { \
    if (n) { \
        va_list args; \
        va_start(args, n); \
        el_type * arr = NULL; \
        size_t size = 0; \
        size_t el_size = OOP_IF(EQUAL(el_type, void))(0, sizeof(el_type)); \
        unsigned int flags = ARRAY_DEFAULT_FLAGS; \
        if (n == 1) { \
            size = va_arg(args, size_t); \
            flags |= ARRAY_MALLOC_ARRAY; \
        } else { \
            arr = va_arg(args, el_type *); \
            size = va_arg(args, size_t); \
        } \
        if (n > 2) { \
            flags = va_arg(args, unsigned int); \
        } \
        OOP_IF(EQUAL(el_type, void))(if (n > 3) {el_size = va_arg(args, size_t); }, ) \
        va_end(args); \
        return (void *) name##_new_(arr, size, flags, el_size); \
    } \
    return NULL; \
} \
int name##_del(void * st_) { \
    if (st_) { \
        name * st = (name *) st_; \
        if (st->flags & ARRAY_MALLOC_ARRAY) { \
            free(st->arr); \
            st->arr = NULL; \
        } \
        free(st); \
        return ARRAY_SUCCESS; \
    } \
    return ARRAY_FAILURE; \
} \
int name##_get(OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, name) * st_, size_t index, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, el_type) * el) { \
    name * st = (name *) st_; \
    if (!st || index >= st->size) { \
        return ARRAY_FAILURE; \
    } \
    if (st->reversed) { \
        index = name##_len(st_) - index - 1; \
    } \
    OOP_IF(EQUAL(el_type, void))( \
        size_t imax = name##_len(st_); \
        /* this should probably be made a copy or use memcpy, but I string.h is not in freestanding headers */ \
        unsigned char * el_dest = (unsigned char *) el; \
        unsigned char * el_src = ((unsigned char *)st->arr) + st->el_size * index; \
        size_t i = 0; \
        while (i < imax) { \
            *el_src = *el_dest; \
            el_src++; el_dest++; i++; \
        } \
    , \
        *((el_type *)el) = st->arr[index]; \
    ) \
    return ARRAY_SUCCESS; \
} \
size_t name##_len(void * st_) { \
    return ((name *)st_)->size; \
} \
int name##_iter(void * st_, void * ist_) { \
    if (!st_ || !ist_) { \
        return ITERATOR_FAIL; \
    } \
    name##Iterator * ist = (name##Iterator *) ist_; \
    OOP_INIT(name##Iterator, *ist); \
    size_t size = name##_len(st_); \
    ist->isl = MAKE_SLICE_ITERATOR(0, size, 1, size); \
    ist->iable = st_; \
    return ITERATOR_GO; \
} \
int name##Iterator_iter(void * ist_src, void * ist_dest) { \
    return name##_iter(((name##Iterator *) ist_src)->iable, ist_dest); \
} \
int name##Iterator_next(OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, name##Iterator) * ist_, OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, el_type) * el) { \
    name##Iterator * ist = (name##Iterator *) ist_; \
    size_t index = 0; \
    if (SliceIterator_next(&ist->isl, &index)) { \
        return ITERATOR_STOP; \
    } \
    return (name##_get(ist->iable, index, el) ? ITERATOR_FAIL : ITERATOR_GO); \
} \
int name##_reversed(void * st_, void * ist_) { \
    if (!st_ || !ist_) { \
        return ITERATOR_FAIL; \
    } \
    name##Iterator * ist = (name##Iterator *) ist_; \
    OOP_INIT(name##Iterator, *ist); \
    size_t size = name##_len(st_); \
    ist->isl = MAKE_SLICE_ITERATOR(size-1, -1, -1, size); \
    ist->iable = st_; \
    return ITERATOR_GO; \
} \
int name##_reverse(void * st_) { \
    if (!st_) { \
        return ARRAY_FAILURE; \
    } \
    ((name *)st_)->reversed = !((name *)st_)->reversed; \
    return ARRAY_SUCCESS; \
} \
bool name##_contains(OOP_IF(OOP_OR(EQUAL(el_type, void), EQUAL(el_type, pvoid)))(void, name) * st_, OOP_IF(EQUAL(el_type, void))(void *, el_type) search_el) { \
    FOR_EACH(OOP_IF(EQUAL(el_type, void))(unsigned char *, el_type), el, name, ((name *) st_), name##Iterator) { \
    OOP_IF(EQUAL(el_type, void)) (\
        unsigned char * sel = (unsigned char *) search_el; \
        size_t i = 0; \
        size_t imax = ((name *) st_)->el_size; \
        while (i < imax) { \
            if (*el != *sel) { \
                break; \
            } \
            el++; sel++; \
            i++;\
        } \
        if (i == imax) { \
            return true; \
        }; \
        , \
        if (el == search_el) { \
            return true; \
        } \
        ) \
    }\
    return false; \
} \
bool name##_is_empty(void * st_) { \
    return !name##_len(st_); \
}
