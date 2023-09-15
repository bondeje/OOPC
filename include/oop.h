#include "tuple_to_seq.h"
// probably or definitely shared
//
#define HASH_LIT #
#define CAT(A, B) CAT_(A, B)
#define CAT_(A, B) A##B
#define CATD(A, B, delim) CATD_(A, B, delim)
#define CATD_(A, B, delim) A##delim##B
#define EVAL(func, args) func(args)
#define EVAL2(func, arg1, args) func(arg1, arg2)
#define EVALVARG(func, ...) func(__VA_ARGS__)
#define EMPTY() 
#define LPAREN() (
#define RPAREN() )
#define ECHO(x) x
#define EXPAND(...) __VA_ARGS__
//#define ACCESSOR OOP_ACCESSOR

#ifndef NO_STDCLIB
    #define OOP_NO_MALLOC(name) (name *) malloc(sizeof(name))
    #define OOP_NO_FREE(name) free(name)
    #define INCLUDE_STDLIB INCLUDE <stdlib.h>
#else
    #define OOP_NO_MALLOC(name) NULL
    #define OOP_NO_FREE(name) do {} while (0)
    #define INCLUDE_STDLIB 
#endif

#ifndef NDEBUG
    #define INCLUDE_STDIO INCLUDE <stdio.h>
#else
    #define INCLUDE_STDIO 
#endif

// directives
#define INCLUDE HASH_LIT include
#define DEFINE HASH_LIT define
#define IF HASH LIT if
#define IFNDEF HASH_LIT ifndef 
#define IFDEF HASH_LIT ifdef
#define ENDIF HASH_LIT endif
#define ELSE HASH_LIT else

/* sequence actions */
#define SEQ_TERM(...) SEQ_TERM_(__VA_ARGS__)
#define SEQ_TERM_(...) __VA_ARGS__##_TERM

/* transform a sequence to a guide*/
#define SEQ_TO_GUIDE_A(...) __VA_ARGS__ RPAREN EMPTY()()SEQ_TO_GUIDE_B
#define SEQ_TO_GUIDE_B(...) __VA_ARGS__ RPAREN EMPTY()()SEQ_TO_GUIDE_A
#define SEQ_TO_GUIDE_A_TERM
#define SEQ_TO_GUIDE_B_TERM
#define SEQ_TO_GUIDE(seq) SEQ_TERM(SEQ_TO_GUIDE_A seq)

#define TYPE_NAME(name) name##__

#define MEMBER_2(type, name) (MEMBER_TYPE, (type name;, type, name, sizeof(type)))
#define MEMBER_3(type, name, array_size) (MEMBER_TYPE, (type name[array_size];, type, name, array_size * sizeof(type)))
#define MEMBER(...) CAT(MEMBER, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define CLASS_MEMBER_(decl, type, name, size, value) (decl, type, name, size, value)
#define CLASS_MEMBER_3(value, type, name) (CLASS_MEMBER_TYPE, CLASS_MEMBER_(type name;, type, name, sizeof(type), value))
#define CLASS_MEMBER_4(value, type, name, array_size) (CLASS_MEMBER_TYPE, CLASS_MEMBER_(type name[array_size];, type, name, array_size * sizeof(type), value))
#define CLASS_MEMBER(...) CAT(CLASS_MEMBER, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)


#define FUNCTION_POINTER(ret, name, ...) ret LPAREN() * name RPAREN() LPAREN() __VA_ARGS__ RPAREN()


#define FUNCTION_(decl, type, name, ftypedef) (decl, type, name, ftypedef)
#define FUNCTION(ret, name, ...) (FUNCTION_TYPE, FUNCTION_(FUNCTION_POINTER(ret, name, __VA_ARGS__);, CATD(CATD(ftype, name,_),__LINE__,_), name, typedef FUNCTION_POINTER(ret, CATD(CATD(ftype, name,_),__LINE__,_), __VA_ARGS__);))

#define CLASS_FUNCTION_(decl, type, name, ftypedef, value) (decl, type, name, ftypedef, value)
#define CLASS_FUNCTION(value, ret, name, ...) (CLASS_FUNCTION_TYPE, CLASS_FUNCTION_(FUNCTION_POINTER(ret, name, __VA_ARGS__);, CATD(CATD(ftype, name,_),__LINE__,_), name, typedef FUNCTION_POINTER(ret, CATD(CATD(ftype, name,_),__LINE__,_), __VA_ARGS__);, value))

#define CLASS_MANGLE(type) CAT(type, _CLASS)
#define PARENT_MANGLE(type) TYPE_NAME(type)
#define PARENT_(type, name) (type name;, type, name, sizeof(type))
#define PARENT(type) (PARENT_TYPE, PARENT_(type, PARENT_MANGLE(type)))

#define G_FROM_SEL(sel, type, arg)

#define G_SEL_END , G_SEL_END_END, G_SEL_END_END
#define G_SEL_A(name, C, D) CHECK1(G_SEL_##C, G_SEL_NEXT)(name, C, D, B)
#define G_SEL_B(name, C, D) CHECK1(G_SEL_##C, G_SEL_NEXT)(name, C, D, A)
#define G_SEL_NEXT(name, C, D, next) name##C D G_SEL_##next(name, 
#define G_SEL_END_END(name, C, D, next) 
#define G_SEL(name, guide) G_SEL_A(name, guide END, END )

#define G_CAT1_END , G_CAT1_END_END
#define G_CAT1_A(delim, C) CHECK1(G_CAT1_##C, G_CAT1_NEXT)(delim, C, B)
#define G_CAT1_B(delim, C) CHECK1(G_CAT1_##C, G_CAT1_NEXT)(delim, C, A)
#define G_CAT1_NEXT(delim, C, next) delim C G_CAT1_##next(delim, 
#define G_CAT1_END_END(delim, C, next) 
#define G_CAT1(delim, guide) G_CAT1_A(delim, guide END)

#define G_TO_SEQ_END , G_TO_SEQ_END_END
#define G_TO_SEQ_A(C) CHECK1(G_TO_SEQ_##C, G_TO_SEQ_NEXT)(C, B)
#define G_TO_SEQ_B(C) CHECK1(G_TO_SEQ_##C, G_TO_SEQ_NEXT)(C, A)
#define G_TO_SEQ_NEXT(C, next) (C) G_TO_SEQ_##next(
#define G_TO_SEQ_END_END(C, next) 
#define G_TO_SEQ(guide) G_TO_SEQ_A(guide END)

/* prepend a name to the guide arguments list so that I can associate classes with members */
// TODO: need to rename prepend macro since it does more than that
#define G_POSTPEND_PREPEND_MACRO_END , G_POSTPEND_PREPEND_MACRO_END_END
#define G_POSTPEND_PREPEND_MACRO_A(name, C) CHECK1(G_POSTPEND_PREPEND_MACRO_##C, G_POSTPEND_PREPEND_MACRO_NEXT)(name, C, B)
#define G_POSTPEND_PREPEND_MACRO_B(name, C) CHECK1(G_POSTPEND_PREPEND_MACRO_##C, G_POSTPEND_PREPEND_MACRO_NEXT)(name, C, A)
#define G_POSTPEND_PREPEND_MACRO_NEXT(name, C, next) C) name##C G_POSTPEND_PREPEND_MACRO_##next(name, 
#define G_POSTPEND_PREPEND_MACRO_END_END(name, A, next)
#define G_POSTPEND_PREPEND_MACRO(name, guide) G_POSTPEND_PREPEND_MACRO_A(name, guide END )

#define SEL_ALL_DECL_PARENT_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_ALL_DECL_CLASS_FUNCTION_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_ALL_DECL_CLASS_MEMBER_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_ALL_DECL_FUNCTION_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_ALL_DECL_MEMBER_TYPE(...) TUPLE_AT_0(__VA_ARGS__))

#define SEL_CLASS_DECL_PARENT_TYPE(...)
#define SEL_CLASS_DECL_CLASS_FUNCTION_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_CLASS_DECL_CLASS_MEMBER_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_CLASS_DECL_FUNCTION_TYPE(...)
#define SEL_CLASS_DECL_MEMBER_TYPE(...)

#define SEL_CLASS_VALUE_PARENT_TYPE(...)
#define SEL_CLASS_VALUE_CLASS_FUNCTION_TYPE(...) TUPLE_AT_4(__VA_ARGS__))
#define SEL_CLASS_VALUE_CLASS_MEMBER_TYPE(...) TUPLE_AT_4(__VA_ARGS__))
#define SEL_CLASS_VALUE_FUNCTION_TYPE(...)
#define SEL_CLASS_VALUE_MEMBER_TYPE(...)

#define SEL_INST_DECL_PARENT_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_INST_DECL_CLASS_FUNCTION_TYPE(...)
#define SEL_INST_DECL_CLASS_MEMBER_TYPE(...)
#define SEL_INST_DECL_FUNCTION_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_INST_DECL_MEMBER_TYPE(...) TUPLE_AT_0(__VA_ARGS__))

#define SEL_PARENT_DECL_PARENT_TYPE(...) TUPLE_AT_0(__VA_ARGS__))
#define SEL_PARENT_DECL_CLASS_FUNCTION_TYPE(...) 
#define SEL_PARENT_DECL_CLASS_MEMBER_TYPE(...) 
#define SEL_PARENT_DECL_FUNCTION_TYPE(...) 
#define SEL_PARENT_DECL_MEMBER_TYPE(...) 

#define SEL_PARENT_NAME_PARENT_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_PARENT_NAME_CLASS_FUNCTION_TYPE(...) 
#define SEL_PARENT_NAME_CLASS_MEMBER_TYPE(...) 
#define SEL_PARENT_NAME_FUNCTION_TYPE(...) 
#define SEL_PARENT_NAME_MEMBER_TYPE(...) 

#define SEL_PARENT_TYPE_PARENT_TYPE(...) TUPLE_AT_1(__VA_ARGS__))
#define SEL_PARENT_TYPE_CLASS_FUNCTION_TYPE(...) 
#define SEL_PARENT_TYPE_CLASS_MEMBER_TYPE(...) 
#define SEL_PARENT_TYPE_FUNCTION_TYPE(...) 
#define SEL_PARENT_TYPE_MEMBER_TYPE(...) 

#define SEL_FUNCTION_TYPEDEF_PARENT_TYPE(...)
#define SEL_FUNCTION_TYPEDEF_CLASS_FUNCTION_TYPE(...) TUPLE_AT_1(__VA_ARGS__))
#define SEL_FUNCTION_TYPEDEF_CLASS_MEMBER_TYPE(...) 
#define SEL_FUNCTION_TYPEDEF_FUNCTION_TYPE(...) TUPLE_AT_1(__VA_ARGS__))
#define SEL_FUNCTION_TYPEDEF_MEMBER_TYPE(...) 

#define SEL_ALL_MEMBERS_PARENT_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_ALL_MEMBERS_CLASS_FUNCTION_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_ALL_MEMBERS_CLASS_MEMBER_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_ALL_MEMBERS_FUNCTION_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_ALL_MEMBERS_MEMBER_TYPE(...) TUPLE_AT_2(__VA_ARGS__))

#define SEL_INST_MEMBERS_PARENT_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_INST_MEMBERS_CLASS_FUNCTION_TYPE(...) 
#define SEL_INST_MEMBERS_CLASS_MEMBER_TYPE(...) 
#define SEL_INST_MEMBERS_FUNCTION_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_INST_MEMBERS_MEMBER_TYPE(...) TUPLE_AT_2(__VA_ARGS__))

#define SEL_CLASS_MEMBERS_PARENT_TYPE(...)
#define SEL_CLASS_MEMBERS_CLASS_FUNCTION_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_CLASS_MEMBERS_CLASS_MEMBER_TYPE(...) TUPLE_AT_2(__VA_ARGS__))
#define SEL_CLASS_MEMBERS_FUNCTION_TYPE(...)
#define SEL_CLASS_MEMBERS_MEMBER_TYPE(...)

//HASH_LIT define OOP_CLASS_G_##name name \
//OOP_NEWLINE \

#define INCLUDE_OOP HASH_LIT include <public_macros.h> OOP_NEWLINE  INCLUDE_STDLIB OOP_NEWLINE INCLUDE_STDIO

// recursive inspection of 1 element guide
#define G_MAKE_MEMBER_DEFS_END , G_MAKE_MEMBER_DEFS_END_END
#define G_MAKE_MEMBER_DEFS_A(C) CHECK1(G_MAKE_MEMBER_DEFS_##C, G_MAKE_MEMBER_DEFS_NEXT)(C, B)
#define G_MAKE_MEMBER_DEFS_B(C) CHECK1(G_MAKE_MEMBER_DEFS_##C, G_MAKE_MEMBER_DEFS_NEXT)(C, A)
#define G_MAKE_MEMBER_DEFS_NEXT(C, next) HASH_LIT ifndef OOP_MEMBER_##C  OOP_NEWLINE HASH_LIT define OOP_MEMBER_##C( x RPAREN() x OOP_NEWLINE HASH_LIT endif OOP_NEWLINE G_MAKE_MEMBER_DEFS_##next(
#define G_MAKE_MEMBER_DEFS_END_END(A, next)
#define G_MAKE_MEMBER_DEFS(members) G_MAKE_MEMBER_DEFS_A(members END)

/* make initialization statement */
#define G_CHAIN_INIT_STMTS_END , G_CHAIN_INIT_STMTS_END_END
#define G_CHAIN_INIT_STMTS_A(inst, C) CHECK1(G_CHAIN_INIT_STMTS_##C, G_CHAIN_INIT_STMTS_NEXT)(inst, C, B)
#define G_CHAIN_INIT_STMTS_B(inst, C) CHECK1(G_CHAIN_INIT_STMTS_##C, G_CHAIN_INIT_STMTS_NEXT)(inst, C, A)
#define G_CHAIN_INIT_STMTS_NEXT(inst, C, next) OOP_TAB OOP_CLASS_INST(C).init(&(inst-> TYPE_NAME(C))); OOP_NEWLINE G_CHAIN_INIT_STMTS_##next(inst, 
#define G_CHAIN_INIT_STMTS_END_END(inst, A, next)
#define G_CHAIN_INIT_STMTS(inst, guide) G_CHAIN_INIT_STMTS_A(inst, guide END )

#define OOP_INIT_REQS(name, inst, seq) OOP_TAB inst->class__ = &OOP_CLASS_INST(name); OOP_NEWLINE G_CHAIN_INIT_STMTS(inst, G_SEL(SEL_PARENT_TYPE_, SEQ_TO_GUIDE(seq)));
#define OOP_CLASS_INST(name) EXPAND(TYPE_NAME EMPTY()(CLASS_MANGLE(name)))

#define CLASS_(name, seq)                  \
HASH_LIT ifndef OOP_MEMBER_##name OOP_NEWLINE HASH_LIT define OOP_MEMBER_##name( x RPAREN() x OOP_NEWLINE HASH_LIT endif \
OOP_NEWLINE \
G_MAKE_MEMBER_DEFS(G_SEL(SEL_ALL_MEMBERS_, SEQ_TO_GUIDE(seq)))\
HASH_LIT define OOP_CLASS_G_PARENT_##name G_POSTPEND_PREPEND_MACRO(OOP_CLASS_G_PARENT_, G_SEL(SEL_PARENT_TYPE_, SEQ_TO_GUIDE(seq))) \
OOP_NEWLINE \
HASH_LIT define OOP_MEMBERS_T_##name G_TO_SEQ(G_SEL(SEL_INST_MEMBERS_, SEQ_TO_GUIDE(seq))), G_TO_SEQ(G_SEL(SEL_CLASS_MEMBERS_, SEQ_TO_GUIDE(seq))) \
OOP_NEWLINE \
typedef struct name name;                                               \
OOP_NEWLINE \
typedef struct CLASS_MANGLE(name) CLASS_MANGLE(name); \
OOP_NEWLINE \
struct CLASS_MANGLE(name) {\
OOP_NEWLINE \
    G_CAT1(OOP_NEWLINE OOP_TAB, G_SEL(SEL_CLASS_DECL_, SEQ_TO_GUIDE(seq))) \
OOP_NEWLINE \
}; \
OOP_NEWLINE \
\
\
struct name {                                                           \
OOP_NEWLINE \
    G_CAT1(OOP_NEWLINE OOP_TAB, G_SEL(SEL_INST_DECL_, SEQ_TO_GUIDE(seq))) \
OOP_NEWLINE \
}; \
OOP_NEWLINE \
\
\
static name * CAT(name,__NEW__)(); \
OOP_NEWLINE \
static void CAT(name,__INIT__)(name * inst); \
OOP_NEWLINE \
static void CAT(name,__DEL__)(name * inst); \
\
\
CLASS_MANGLE(name) OOP_CLASS_INST(name) = {sizeof(name), CAT(name,__NEW__), CAT(name,__INIT__), CAT(name,__DEL__)}; \
OOP_NEWLINE \
OOP_NEWLINE \
name name##_INIT = {&OOP_CLASS_INST(name), 0};\
OOP_NEWLINE \
\
\
static name * CAT(name,__NEW__)() { \
OOP_NEWLINE \
OOP_TAB name * inst = OOP_NO_MALLOC(name); \
OOP_NEWLINE \
OOP_TAB if (!inst) {return NULL;}; \
OOP_NEWLINE \
OOP_TAB OOP_CLASS_INST(name).init(inst); \
OOP_NEWLINE \
OOP_TAB return inst; \
OOP_NEWLINE \
} \
OOP_NEWLINE \
\
\
static void CAT(name,__INIT__)(name * inst) { \
OOP_NEWLINE \
OOP_TAB *inst = (name) {0}; \
OOP_NEWLINE \
OOP_INIT_REQS(name, inst, seq) \
OOP_NEWLINE \
} \
OOP_NEWLINE \
\
\
static void CAT(name,__DEL__)(name * inst) { \
OOP_NEWLINE \
OOP_TAB OOP_NO_FREE(inst); \
OOP_NEWLINE \
} \
OOP_NEWLINE \

// prepend a member pointer to the class definition
#define CLASS(name, seq) \
CLASS_(\
    name, \
    CLASS_MEMBER(sizeof(name), size_t, size) \
    CLASS_FUNCTION(NULL, name *, new, ) \
    CLASS_FUNCTION(NULL, void, init, ) \
    CLASS_FUNCTION(NULL, void, del, name *) \
    MEMBER(CLASS_MANGLE(name) *, class__) \
    seq)
