#include <t_array.def.h>

/**
 * NOTE: in templates, you normally cannot directly #include <oopc.h> since many <oopc.h> macros 
 * depend on what the inputs in the top-level macro are. If #include <oopc.h> is present, the 
 * macros must escape <oopc.h> macros
 */

#define TEMPLATE_Vector(el_type) TEMPLATE_Vector_(Vector##el_type, el_type)

#define TEMPLATE_Vector_(name, el_type) \
IFNDEF IMPORT_CLASS_DEFS_ONLY \
OOP_NEWLINE \
TYPEDEF(struct name, name) OOP_NEWLINE \
TYPEDEF(struct name##Iterator, name##Iterator) OOP_NEWLINE \
size_t name##_capacity(void * vector); \
int name##_push(void * vector, void * el); \
int name##_insert(void * vector, size_t loc, void * in); \
int name##_extend(void * vector_dest, void * vector_src); \
int name##_peek(void * vector, void * out); \
int name##_pop(void * vector, void * out); \
int name##_remove(void * vector, size_t loc, void * out); \
int name##_resize(void * vector, size_t new_cap); \
int name##_next(void * vector, void * out); \
void name##_init_(name * vector);  OOP_NEWLINE \
int name##_init(void * vector, unsigned int n, ...); OOP_NEWLINE \
name * name##_new_(void * vector);  OOP_NEWLINE \
void * name##_new(unsigned int, ...);  OOP_NEWLINE \
int name##_del(void * vector);  OOP_NEWLINE \
ENDIF /* IMPORT_CLASS_DEFS_ONLY */ \
OOP_NEWLINE \
CLASS(name, \
    MEMBER(size_t, cap) \
    MEMBER(size_t, resize_factor) \
    EXTENDS(Array(el_type)) \
    IMPLEMENTS(MutableSequence, push, name##_push, insert, name##_insert, extend, name##_extend, peek, name##_peek, pop, name##_pop, remove, name##_remove, capacity, name##_capacity, resize, name##_resize) \
    IMPLEMENTS(Creatable, new, name##_new, del, name##_del) \
    IMPLEMENTS(Initializable, init, name##_init) \
)
