#include <t_array.def.h>
#define OMIT_STRUCT_DECLS
#include <initializable.h>
#include <creatable.h>
#include <iteration.h>
#include <sequence.h>
#undef OMIT_STRUCT_DECLS
IFNDEF TEMPLATE_ARRAY_H
DEFINE TEMPLATE_ARRAY_H
INCLUDE_OOPC
INCLUDE <stddef.h>
INCLUDE <stdarg.h>
INCLUDE <stdlib.h>
INCLUDE <stdbool.h>
INCLUDE <creatable.h>
INCLUDE <initializable.h>
INCLUDE <sequence.h>
INCLUDE <slice.h>

DEFINE ARRAY_DEFAULT_FLAGS 0x00
DEFINE ARRAY_MALLOC_ARRAY 0x01

DEFINE ARRAY_SUCCESS 0
DEFINE ARRAY_FAILURE 1

/*
add new declarations of arrays here
*/
TEMPLATE_BASE(Array, void *)

ENDIF // TEMPLATE_ARRAY_H