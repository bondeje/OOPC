#define TEMPLATE(el_type) TEMPLATE_BASE(Array##el_type, el_type)
#define TEMPLATE_IMPLEMENATION(el_type) TEMPLATE_BASE_IMPLEMENTATION(Array##el_type, el_type)

// TODO: contains implementation only check identity (same pointer). To check value, must also have name have an optional member compare function

#define TEMPLATE_BASE(name, el_type) \
TYPEDEF(struct name, name) OOP_NEWLINE \
void name##_init_(name *, el_type *, size_t, size_t, unsigned int);  OOP_NEWLINE \
int name##_init(void *, unsigned int, ...); OOP_NEWLINE \
name * name##_new_(el_type *, size_t, size_t, unsigned int);  OOP_NEWLINE \
void * name##_new(unsigned int, ...);  OOP_NEWLINE \
int name##_del(void *);  OOP_NEWLINE \
void * name##_get(void *, size_t);  OOP_NEWLINE \
bool name##_contains(void *, void*); OOP_NEWLINE \
int name##_iter(void *, void *); OOP_NEWLINE \
int name##Iterator_iter(void *, void *); OOP_NEWLINE \
void * name##Iterator_next(void *); OOP_NEWLINE \
int name##Iterator_stop(void *); OOP_NEWLINE \
size_t name##_len(void *); OOP_NEWLINE \
int name##_reverse(void *); OOP_NEWLINE \
int name##_reversed(void *, void *); OOP_NEWLINE \
OOP_NEWLINE \
DEFINE name(type) name##type \
OOP_NEWLINE \
CLASS(name, \
    MEMBER(el_type *, arr) \
    MEMBER(size_t, cap) \
    MEMBER(size_t, size) \
    MEMBER(unsigned int, reversed) \
    MEMBER(unsigned int, flags) \
    IMPLEMENTS(Creatable, new, name##_new, del, name##_del) \
    IMPLEMENTS(Initializable, init, name##_init) \
    IMPLEMENTS(Sequence, get, name##_get, iter, name##_iter, contains, name##_contains, len, name##_len, reverse, name##_reverse, reversed, name##_reversed) \
) \
OOP_NEWLINE \
CLASS(name##Iterator, \
    MEMBER(name *, iable) \
    MEMBER(SliceIterator, isl) \
    IMPLEMENTS(Iterator, iter, name##Iterator_iter, next, name##Iterator_next, stop, name##Iterator_stop) \
) \

#define TEMPLATE_BASE_IMPLEMENTATION(name, el_type) \
void name##_init_(name * iable, el_type * arr, size_t cap, size_t size, unsigned int flags) { \
    iable->arr = arr; \
    iable->cap = cap; \
    iable->size = size; \
    iable->reversed = 0; \
    iable->flags = flags; \
} \
int name##_init(void * iable, unsigned int n, ...) { \
    if (n > 1) { \
        va_list args; \
        va_start(args, n); \
        el_type * arr = va_arg(args, el_type *); \
        size_t cap = va_arg(args, size_t); \
        size_t size = 0; \
        unsigned int flags = ARRAY_DEFAULT_FLAGS; \
        if (n > 2) { \
            size = va_arg(args, size_t); \
        } \
        if (n > 3) { \
            flags = va_arg(args, unsigned int); \
        } \
        va_end(args); \
        name##_init_(iable, arr, cap, size, flags); \
        return ARRAY_SUCCESS; \
    } \
    return ARRAY_FAILURE; \
} \
name * name##_new_(el_type * arr, size_t init_cap, size_t size, unsigned int flags) { \
    name * st = (name *) malloc(sizeof(name)); \
    if (!st) { \
        return NULL; \
    } \
    if (!arr) { \
        el_type * arr = (el_type *) malloc(sizeof(el_type) * init_cap); \
        if (!arr) { \
            free(st); \
            return NULL; \
        } \
        flags |= ARRAY_MALLOC_ARRAY; \
    } else { \
        flags &= ~ARRAY_MALLOC_ARRAY; \
    } \
    OOP_INIT(name, *st); \
    name##_init_(st, arr, init_cap, size, flags); \
    return st; \
} \
void * name##_new(unsigned int n, ...) { \
    if (n) { \
        va_list args; \
        va_start(args, n); \
        el_type * arr = NULL; \
        size_t init_cap = 0; \
        size_t size = 0; \
        unsigned int flags = ARRAY_DEFAULT_FLAGS; \
        if (n == 1) { \
            init_cap = va_arg(args, size_t); \
            flags |= ARRAY_MALLOC_ARRAY; \
        } else { \
            arr = va_arg(args, el_type *); \
            init_cap = va_arg(args, size_t); \
        } \
        if (n > 2) { \
            size = va_arg(args, size_t); \
        } \
        va_end(args); \
        name##_new_(arr, init_cap, size, flags); \
        return ARRAY_SUCCESS; \
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
void * name##_get(void * st_, size_t index) { \
    name * st = (name *) st_; \
    if (!st || index >= st->size) { \
        return NULL; \
    } \
    if (st->reversed) { \
        return st->arr[name##_len(st_) - index - 1]; \
    } \
    return st->arr[index]; \
} \
size_t name##_len(void * st_) { \
    return ((name *)st_)->size; \
} \
int name##_iter(void * st_, void * ist_) { \
    if (!st_ || !ist_) { \
        return 1; \
    } \
    name##Iterator * ist = (name##Iterator *) ist_; \
    OOP_INIT(name##Iterator, *ist); \
    size_t size = name##_len(st_); \
    ist->isl = MAKE_SLICE_ITERATOR(0, size, 1, size); \
    ist->iable = st_; \
    return 0; \
} \
int name##Iterator_iter(void * ist_src, void * ist_dest) { \
    return name##_iter(((name##Iterator *) ist_src)->iable, ist_dest); \
} \
void * name##Iterator_next(void * ist_) { \
    name##Iterator * ist = (name##Iterator *) ist_; \
    size_t * pindex = SliceIterator_next(&ist->isl); \
    if (!pindex) { \
        return NULL; \
    } \
    return name##_get(ist->iable, *pindex); \
} \
int name##Iterator_stop(void * ist_) { \
    return SliceIterator_stop(((name##Iterator *) ist_)->isl); \
} \
int name##_reversed(void * st_, void * ist_) { \
    if (!st_ || !ist_) { \
        return 1; \
    } \
    name##Iterator * ist = (name##Iterator *) ist_; \
    OOP_INIT(name##Iterator, *ist); \
    size_t size = name##_len(st_); \
    ist->isl = MAKE_SLICE_ITERATOR(size-1, -1, -1, size); \
    ist->iable = st_; \
    return 0; \
} \
int name##_reverse(void * st_) { \
    if (!st_) { \
        return 1; \
    } \
    ((name *)st_)->reversed = !((name *)st_)->reversed; \
    return 0; \
} \
/* TODO: for now, just checks pointer make it check contents as well */ \
bool name##_contains(void * st_, void * search_el) { \
    FOR_EACH(void, el, name, st_, name##Iterator) { \
        if (el == search_el) { \
            return true; \
        } \
    }\
    return false; \
}