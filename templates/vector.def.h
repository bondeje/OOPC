#include <t_vector.def.h>
#define OMIT_STRUCT_DECLS
#define IMPORT_CLASS_DEFS_ONLY
//#include <array.h>
#include <sequence.h>
#include <creatable.h>
#include <initializable.h>
#undef OMIT_STRUCT_DECLS
#undef IMPORT_CLASS_DEFS_ONLY
IFNDEF TEMPLATE_VECTOR_H
DEFINE TEMPLATE_VECTOR_H
INCLUDE_OOPC
INCLUDE <array.h>

DEFINE Vector(el_type) Vector##el_type
//DEFINE VectorIterator(el_type) CAT(Array(el_type), Iterator)

/*
add new declarations of arrays here
*/
TYPEDEF(void *, pvoid)
TEMPLATE(Vector, pvoid)

ENDIF // TEMPLATE_VECTOR_H
