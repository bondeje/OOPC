#define TEMPLATE_Array(name, el_type, el_size) \
void name##_init_(void *, void *, size_t, size_t, unsigned int);  OOP_NEWLINE \
void name##_init(void *, unsigned int, ...); OOP_NEWLINE \
void * name##_new_(size_t);  OOP_NEWLINE \
void * name##_new(unsigned int, ...);  OOP_NEWLINE \
void name##_del(void *);  OOP_NEWLINE \
int name##_get(void *, void *, size_t);  OOP_NEWLINE \
bool name##_contains(void *, void*); OOP_NEWLINE \
int name##_iter(void *, void *); OOP_NEWLINE \
int name##Iterator_iter(void *, void *); OOP_NEWLINE \
void * name##Iterator_next(void *); OOP_NEWLINE \
int name##Iterator_stop(void *); OOP_NEWLINE \
size_t name##_len(void *); OOP_NEWLINE \
int name##_reverse(void *); OOP_NEWLINE \
int name##_reversed(void *, void *); OOP_NEWLINE \
OOP_NEWLINE \
CLASS(name, \
    EXTENDS(Sequence)  \
    IMPLEMENTS(Sequence, init, name##_init, new, name##_new, del, name##_del, get, name##_get, snprintf, name##_snprintf, c_str, name##_c_str) \
) \
DEFINE name##_IMPLEMENTATION \
void name##_init(void * st_, void * arr, size_t cap, size_t size, unsigned int flags) { \
    name * st = (name *) st_; \
    Sequence * seq = &OOPC(SUPER)(name, *st, Sequence); \
    OOPC(INIT)(Sequence, *seq); \
    OOPC(GET)(name, *st, arr) = arr; \
    OOPC(GET)(name, *st, cap) = cap; \
    OOPC(GET)(name, *st, size) = size; \
    OOPC(GET)(name, *st, flags) = flags; \
} \
void * name##_new(size_t init_cap) { \
    name * st = (name *) malloc(sizeof(name)); \
    if (!st) { \
        return NULL; \
    } \
    el_type * arr = (el_type *) malloc(sizeof(el_type) * init_cap); \
    if (!arr) { \
        free(st); \
        return NULL; \
    } \
    for (size_t i = 0; i < init_cap; i++) { \
        arr[i] = (el_type) 0; \
    } \
    OOPC(GET)(name, *st, init)(st, arr, init_cap, 0, SEQUENCE_MALLOC_ARRAY); \
    return (void *)st; \
} \
void name##_del(void * st_) { \
    name * st = (name *) st_; \
    if (st) { \
        if (OOPC(GET)(name, *st, flags) & SEQUENCE_MALLOC_ARRAY) { \
            free(OOPC(GET)(name, *st, arr)); \
            OOPC(GET)(name, *st, arr) = NULL; \
        } \
        free(st); \
    } \
} \
int name##_get(void * st_, void * el, size_t index) { \
    name * st = (name *) st_; \
    if (!st || index >= OOPC(GET)(name, *st, size)) { \
        return SEQUENCE_FAILURE; \
    } \
    el_type * a = (el_type *) OOPC(GET)(name, *st, arr); \
    memcpy(el, &a[index], sizeof(el_type)); \
    return SEQUENCE_SUCCESS; \
} \
char * name##_c_str(void * st, char * buf, size_t bufn) { \
    name * st_ = (name *) st; \
    if (!buf || bufn < 2 || bufn < OOPC(GET)(name, *st_, snprintf)(st, buf, bufn, NULL, "")) { \
        return NULL; \
    } \
    return buf; \
} \
int name##_snprintf(void * st, char * buf, size_t bufn, const char * delim, const char * term) { \
    const char * term_ = (term ? term : "\n"); \
    const char * delim_ = (delim ? delim : " "); \
    int overflow = 0; \
    int ct = 0; \
    size_t i = 0; \
    int delta = name##_snprintf_(st, i, buf, bufn, ""); \
    while (delta >= 0) { \
        buf += delta; \
        bufn -= delta; \
        i += 1; \
        delta = name##_snprintf_(st, i, buf, bufn, " "); \
    } \
    delta = snprintf(buf, bufn, "%s", term_); \
    if (delta < bufn - 1) { \
        buf += delta; \
        bufn -= delta; \
    } \
    if (bufn > 0) { \
        *buf = '\0'; \
    } \
    return ct; \
}

#include <oopc.h>
IFNDEF TEMPLATE_ARRAY_H
DEFINE TEMPLATE_ARRAY_H
INCLUDE_OOPC
INCLUDE <stddef.h>
INCLUDE <stdlib.h>
INCLUDE <string.h>
INCLUDE <sequence.h>

DEFINE DEFAULT_SEQUENCE_FLAGS 0x00
DEFINE SEQUENCE_MALLOC_ARRAY 0x01

DEFINE SEQUENCE_SUCCESS 0
DEFINE SEQUENCE_FAILURE 1

/*
add new declarations of arrays here
*/

ENDIF // TEMPLATE_ARRAY_H