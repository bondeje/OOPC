#include <oop.h>
#include <pptuples.h>

#define INCLUDE_OOPC INCLUDE <oopc.h> OOP_NEWLINE INCLUDE_STDLIB OOP_NEWLINE INCLUDE_STDIO

/* name mangling */
#define INST_MANGLE(name) CAT(name, __)
#define TYPE_NAME(name) CAT(name, __)
#define CLASS_MANGLE(type) CAT(type, _CLASS)
#define CLASS_INST(name) PASS_ARGS(TYPE_NAME EMPTY()(CLASS_MANGLE(name)))

#define TYPEDEF(name, id) IFNDEF CAT(TYPEDEF_, id) OOP_NEWLINE OOP_TAB DEFINE CAT(TYPEDEF_, id) OOP_NEWLINE OOP_TAB typedef name id; OOP_NEWLINE ENDIF

/* class data structure algorithms */
//#define OOP_CLASS_G_HIERARCHY(name) name) CLASS_MANGLE(name)) CATD(OOP_CLASS_G_PARENT, CLASS_MANGLE(name), _) OOP_CLASS_G_PARENT_##name
#define IS_PARENT(A, B) IS_IN_G(A, OOP_CLASS_G_HIER_##B)

#define OOP_MEMBER_MEMBER_TYPE(x) x
#define IS_MEMBER_TYPE(type, ...) EQUAL(MEMBER_TYPE, type)
#define MEMBER_(decl, type, name, value, size) (decl, type, name, value, size)
#define MEMBER_2(type, name) (MEMBER_TYPE, MEMBER_(type name;, type, name, OOP_NO_DEFAULT, sizeof(type)))
#define MEMBER_3(type, name, value) (MEMBER_TYPE, MEMBER_(type name;, type, name, (OOP_IF(IS_PAREN(value()))(OOP_NO_DEFAULT, value)), sizeof(type)))
#define MEMBER(...) CAT(MEMBER, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define ARRAY_MEMBER_3(type, name, array_size) (MEMBER_TYPE, MEMBER_(type name[array_size];, type, name, OOP_NO_DEFAULT, array_size * sizeof(type)))
#define ARRAY_MEMBER_4(type, name, value, array_size) (MEMBER_TYPE, MEMBER_(type name[array_size];, type, name, (OOP_IF(IS_PAREN(value()))(OOP_NO_DEFAULT, value)), array_size * sizeof(type)))
#define ARRAY_MEMBER(...) CAT(ARRAY_MEMBER, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define OOP_MEMBER_CLASS_MEMBER_TYPE(x) x
#define IS_CLASS_MEMBER_TYPE(type, ...) EQUAL(CLASS_MEMBER_TYPE, type)
#define CLASS_MEMBER_2(type, name) (CLASS_MEMBER_TYPE, MEMBER_(type name;, type, name, OOP_NO_DEFAULT, sizeof(type)))
#define CLASS_MEMBER_3(type, name, value) (CLASS_MEMBER_TYPE, MEMBER_(type name;, type, name, (OOP_IF(IS_PAREN(value()))(OOP_NO_DEFAULT, value)), sizeof(type)))
#define CLASS_MEMBER(...) CAT(CLASS_MEMBER, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define ARRAY_CLASS_MEMBER_3(type, name, array_size) (CLASS_MEMBER_TYPE, MEMBER_(type name;, type, name, OOP_NO_DEFAULT, array_size * sizeof(type)))
#define ARRAY_CLASS_MEMBER_4(type, name, value, array_size) (CLASS_MEMBER_TYPE, MEMBER_(type name[array_size];, type, name, (OOP_IF(IS_PAREN(value()))(OOP_NO_DEFAULT, value)), array_size * sizeof(type)))
#define ARRAY_CLASS_MEMBER(...) CAT(ARRAY_CLASS_MEMBER, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define FUNCTION_POINTER(ret, name, ...) ret LPAREN() * name RPAREN() LPAREN() __VA_ARGS__ RPAREN()

#define OOP_MEMBER_FUNCTION_TYPE(x) x
#define IS_FUNCTION_TYPE(type, ...) EQUAL(FUNCTION_TYPE, type)
#define FUNCTION_(decl, type, name, value, size, ftypedef) (decl, type, name, value, size, ftypedef)
#define FUNCTION(value, ret, name, ...) (FUNCTION_TYPE, FUNCTION_(FUNCTION_POINTER(ret, name, __VA_ARGS__);, CATD(CATD(ftype, name,_),__LINE__,_), name, (value), sizeof(void*), typedef FUNCTION_POINTER(ret, CATD(CATD(ftype, name,_),__LINE__,_), __VA_ARGS__);))

#define OOP_MEMBER_CLASS_FUNCTION_TYPE(x) x
#define IS_CLASS_FUNCTION_TYPE(type) EQUAL(CLASS_FUNCTION_TYPE, type)
#define CLASS_FUNCTION_(decl, type, name, value, size, ftypedef) (decl, type, name, value, size, ftypedef)
#define CLASS_FUNCTION(value, ret, name, ...) (CLASS_FUNCTION_TYPE, CLASS_FUNCTION_(FUNCTION_POINTER(ret, name, __VA_ARGS__);, CATD(CATD(ftype, name,_),__LINE__,_), name, (value), sizeof(void *), typedef FUNCTION_POINTER(ret, CATD(CATD(ftype, name,_),__LINE__,_), __VA_ARGS__);))

#define OOP_MEMBER_PARENT_TYPE(x) x
#define IS_PARENT_TYPE(type, ...) EQUAL(PARENT_TYPE, type)
#define PARENT_MANGLE(type) TYPE_NAME(type)
#define EXTENDS_(decl, type, name, value, size) (type name;, type, name, value, sizeof(type))
#define EXTENDS(type) (PARENT_TYPE, EXTENDS_(type name;, type, PARENT_MANGLE(type), (OOP_NO_DEFAULT), sizeof(type)))

#define PAIRED_T_TO_INIT_NAME_0(name) OOP_IF(IS_OOP_END(name)) ( ,.name = PAIRED_T_TO_INIT_VAL_0)
#define PAIRED_T_TO_INIT_NAME_1(name) OOP_IF(IS_OOP_END(name)) ( ,.name = PAIRED_T_TO_INIT_VAL_1)
#define PAIRED_T_TO_INIT_VAL_0(value) value, PAIRED_T_TO_INIT_NAME_1
#define PAIRED_T_TO_INIT_VAL_1(value) value, PAIRED_T_TO_INIT_NAME_0
#define PAIRED_T_TO_INIT_(seq) PAIRED_T_TO_INIT_NAME_0 seq(OOP_END)
#define PAIRED_T_TO_INIT(...) {PAIRED_T_TO_INIT_(T_TO_S(__VA_ARGS__))}

#define OOP_MEMBER_INTERFACE_TYPE(x) x
#define IS_INTERFACE_TYPE(type, ...) EQUAL(INTERFACE_TYPE, type)
#define INTERFACE_MANGLE(type) TYPE_NAME(type)
#define IMPLEMENTS_(decl, type, name, vals, size) (type name;, type, name, vals, size)
// variadic is a set of name, value pairs associating function names from interface to their implementations (value)
#define IMPLEMENTS(type, ...) (INTERFACE_TYPE, IMPLEMENTS_(type name;, type, INTERFACE_MANGLE(type), (PAIRED_T_TO_INIT(__VA_ARGS__)), sizeof(type)))

/* implement an interface in an interface. maybe do not need this */
//#define IMPLEMENT(type, ...) INTERFACE_MANGLE(type), {.class__ = CLASS_MANGLE(type) PAIRED_T_TO_INIT(__VA_ARGS__)}

#define IS_INST_MEMBER(type, ...) ANY(EQUAL(PARENT_TYPE, type), EQUAL(MEMBER_TYPE, type), EQUAL(FUNCTION_TYPE, type))
#define IS_CLASS_MEMBER(type, ...) ANY(EQUAL(INTERFACE_TYPE, type), EQUAL(CLASS_MEMBER_TYPE, type), EQUAL(CLASS_FUNCTION_TYPE, type))
#define IS_FUNCTION(type, ...) OOP_OR(EQUAL(FUNCTION_TYPE, type), EQUAL(CLASS_FUNCTION_TYPE, type))

#define GET_NAME(type, type_ds) T_INSPECT_2 type_ds
#define GET_DECL(type, type_ds) T_INSPECT_0 type_ds
#define GET_VALUE(type, type_ds) T_INSPECT_3 type_ds
#define GET_SIZE(type, type_ds) T_INSPECT_4 type_ds

// recursive inspection of 1 element guide
#define MAKE_MEMBER_DEFS(members_g) G_JOIN_(MAKE_MEMBER_DEF, members_g OOP_END)
#define MAKE_MEMBER_DEF_(member) HASH_LIT ifndef CAT(OOP_MEMBER_, member) OOP_NEWLINE OOP_TAB HASH_LIT define CAT(OOP_MEMBER_, member)( x RPAREN() x OOP_NEWLINE HASH_LIT endif OOP_NEWLINE
#define MAKE_MEMBER_DEF(type, type_ds) MAKE_MEMBER_DEF_(SPLIT(GET_NAME)(type, type_ds))

#define GET_MEMBER_NAMES(name) G_TO_G(GET_NAME, OOP_MEMBERS_G_##name)

#define MAKE_CLASS_MEMBER_INIT(type, type_ds) PASS_ARGS_(.GET_NAME(type, type_ds) = PASS_ARGS GET_VALUE(type, type_ds)),
#define MAKE_CLASS_INIT_(class_member_g) G_JOIN_(MAKE_CLASS_MEMBER_INIT, class_member_g OOP_END)
#define MAKE_CLASS_INIT(name, seq) static CLASS_MANGLE(name) CLASS_INST(name) = {MAKE_CLASS_INIT_(G_FILTER(IS_CLASS_MEMBER, S_TO_G(seq)))} \

#define MAKE_DECLS(members_g) G_JOIN_(MAKE_DECL, members_g OOP_END)
#define MAKE_DECL(type, type_ds) OOP_TAB GET_DECL(type, type_ds) OOP_NEWLINE

#define BUILD_CLASS_G_HIER(parents_g) G_JOIN_(PREFIX_CLASS_G_HIER, parents_g OOP_END)
#define PREFIX_CLASS_G_HIER(type, type_ds) CATD(OOP_CLASS_G_HIER, T_INSPECT_1 type_ds, _)

#define OOP_INIT_REQS(name, inst, seq) OOP_TAB inst->class__ = &OOP_CLASS_INST(name); OOP_NEWLINE G_JOIN(PASS_ARGS, G_TO_G_A(MAKE_INIT, inst, G_FILTER(IS_PARENT_TYPE, S_TO_G(seq))))
#define OOP_CLASS_INST(name) PASS_ARGS(TYPE_NAME EMPTY()(CLASS_MANGLE(name)))
#define MAKE_INIT(inst, type, type_ds) OOP_TAB SPLIT(OOP_CLASS_INST)(T_INSPECT_1 type_ds).init(&(inst-> SPLIT(TYPE_NAME)(T_INSPECT_1 type_ds))); OOP_NEWLINE

#define CLASS_(name, seq)\
IFNDEF OOP_MEMBER_##name OOP_NEWLINE OOP_TAB DEFINE OOP_MEMBER_##name( x RPAREN() x OOP_NEWLINE ENDIF \
OOP_NEWLINE \
IFNDEF CATD(OOP_MEMBER, CLASS_MANGLE(name),_) OOP_NEWLINE OOP_TAB DEFINE CATD(OOP_MEMBER, CLASS_MANGLE(name),_)( x RPAREN() x OOP_NEWLINE ENDIF \
OOP_NEWLINE \
MAKE_MEMBER_DEFS(S_TO_G(seq))\
OOP_NEWLINE \
DEFINE OOP_CLASS_G_PARENT_##name BUILD_CLASS_G_HIER(G_FILTER(IS_PARENT_TYPE, S_TO_G(seq))) \
OOP_NEWLINE \
DEFINE OOP_CLASS_G_HIER_##name name) CAT(OOP_CLASS_G_HIER_, CLASS_MANGLE(name)) OOP_CLASS_G_PARENT_##name \
OOP_NEWLINE \
DEFINE CAT(OOP_CLASS_G_PARENT_, CLASS_MANGLE(name)) BUILD_CLASS_G_HIER(G_FILTER(IS_INTERFACE_TYPE, S_TO_G(seq))) \
OOP_NEWLINE \
DEFINE CAT(OOP_CLASS_G_HIER_, CLASS_MANGLE(name)) CLASS_MANGLE(name)) CAT(OOP_CLASS_G_PARENT_, CLASS_MANGLE(name)) \
OOP_NEWLINE \
DEFINE OOP_MEMBERS_G_##name G_FILTER(IS_INST_MEMBER, S_TO_G(seq)) \
OOP_NEWLINE \
DEFINE CAT(OOP_MEMBERS_G_, CLASS_MANGLE(name)) G_FILTER(IS_CLASS_MEMBER, S_TO_G(seq)) \
OOP_NEWLINE \
OOP_NEWLINE \
TYPEDEF(struct name, name) \
OOP_NEWLINE \
TYPEDEF(struct CLASS_MANGLE(name), CLASS_MANGLE(name)) \
OOP_NEWLINE \
struct CLASS_MANGLE(name) { \
OOP_NEWLINE \
    MAKE_DECLS(G_FILTER(IS_CLASS_MEMBER, S_TO_G(seq))) \
}; \
OOP_NEWLINE \
\
\
struct name {                                                           \
OOP_NEWLINE \
    MAKE_DECLS(G_FILTER(IS_INST_MEMBER, S_TO_G(seq))) \
OOP_NEWLINE \
}; \
OOP_NEWLINE \
\
\
MAKE_CLASS_INIT(name, seq); \
OOP_NEWLINE \

/*
Below are extensions to the CLASS macro to provide default implementations for "new", "init", and 
"del" functions for each class. This is tabled while I think of a way that a user can "override" 
them with a macro inside a CLASS invocation. It is not a straightforward problem. The errors were
pretty hard to follow when trying a simple OOP_IF() macro to check if the member existed. Such a 
check ultimately must convert the sequence to a check, filter the guide, then check if these 
functions were provided by the user...IF_IN_G is not very stable to begin with, esp. within an 
OOP_IF invocation). Keeping them here in case I come back to it.
*/

/* 
\
\
OOP_NEWLINE \
OOP_NEWLINE \
static name * CAT(name,__NEW__)(); \
OOP_NEWLINE \
static void CAT(name,__INIT__)(name * inst); \
OOP_NEWLINE \
static void CAT(name,__DEL__)(name * inst); \

\
\
static name * CAT(name,__NEW__)() { \
OOP_NEWLINE \
OOP_TAB name * inst = OOP_MALLOC(name); \
OOP_NEWLINE \
OOP_TAB if (!inst) {return NULL;}; \
OOP_NEWLINE \
OOP_TAB CLASS_INST(name).init(inst); \
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
OOP_TAB OOP_FREE(inst); \
OOP_NEWLINE \
} \
OOP_NEWLINE \
*/

// prepend a member pointer to the class and instance object definition
#define CLASS(name, seq) \
CLASS_(\
    name, \
    MEMBER(CLASS_MANGLE(name) *, class__) \
    CLASS_MEMBER(void *, class__, NULL) \
    seq)

#define OOP_BT_GET_CUR_CLASS(...) T_INSPECT_0(__VA_ARGS__)
#define OOP_BG_GET_NAME(...) T_INSPECT_1(__VA_ARGS__)

#define OOP_HIER_S_TO_CALL(namespace) OOP_HIER_S_TO_CALL_(namespace)

// NOTE: cannot use the G_TO_S functionality...for some reason, it is not working, so once a proper parent is found, continue through guide converting it to a sequence
#define OOP_G_BT_NS_TO_S_0(...) OOP_IF(IS_OOP_END(OOP_BT_GET_CUR_CLASS(__VA_ARGS__)))(ERASE_ARGS_, OOP_G_BT_NS_TO_S_NEXT)(1, __VA_ARGS__)
#define OOP_G_BT_NS_TO_S_1(...) OOP_IF(IS_OOP_END(OOP_BT_GET_CUR_CLASS(__VA_ARGS__)))(ERASE_ARGS_, OOP_G_BT_NS_TO_S_NEXT)(0, __VA_ARGS__)
#define OOP_G_BT_NS_TO_S_NEXT(next, ...) (__VA_ARGS__) OOP_G_BT_NS_TO_S_##next(
#define OOP_G_BT_NS_FOUND(next_class, next, ...) (OOP_BT_GET_CUR_CLASS(__VA_ARGS__), OOP_BG_GET_NAME(__VA_ARGS__)) OOP_G_BT_NS_TO_S_0(
#define OOP_G_BT_NS_0(next_class, ...) OOP_IF(IS_OOP_END(OOP_BT_GET_CUR_CLASS(__VA_ARGS__)))(ERASE_ARGS, OOP_ELSE_IF(IS_PARENT EMPTY() (next_class, OOP_BT_GET_CUR_CLASS(__VA_ARGS__)))(OOP_G_BT_NS_FOUND, OOP_G_BT_NS_NEXT))(next_class, 1, __VA_ARGS__)
#define OOP_G_BT_NS_1(next_class, ...) OOP_IF(IS_OOP_END(OOP_BT_GET_CUR_CLASS(__VA_ARGS__)))(ERASE_ARGS, OOP_ELSE_IF(IS_PARENT EMPTY() (next_class, OOP_BT_GET_CUR_CLASS(__VA_ARGS__)))(OOP_G_BT_NS_FOUND, OOP_G_BT_NS_NEXT))(next_class, 0, __VA_ARGS__)
#define OOP_G_BT_NS_NEXT(next_class, next, ...) OOP_G_BT_NS_##next(next_class, 
#define OOP_G_BT_NS__ OOP_G_BT_NS_0
#define OOP_G_BT_NS_(next_class, guide) OOP_G_BT_NS__(next_class, guide OOP_END)
#define OOP_G_BT_NS(namespace, next_class) OOP_G_BT_NS_(next_class, S_TO_G(namespace))

#define G_SEARCH_EXIT(namespace, ...) namespace G_ERASE_(
#define G_SEARCH_0(namespace, member, class) OOP_IF(IS_IN_G(member, GET_MEMBER_NAMES(class)))(G_SEARCH_EXIT, G_SEARCH_NEXT_0)(namespace, member, class)
#define G_SEARCH_1(namespace, member, class) OOP_IF(IS_IN_G(member, GET_MEMBER_NAMES(class)))(G_SEARCH_EXIT, G_SEARCH_NEXT_1)(namespace, member, class)
// rework this one so that it iterates over namespace until OOP(IS_PARENT) is true
#define G_SEARCH_UPDATE_NAMESPACE_0(namespace, class, next_class) \
    OOP_IF(EQUAL(next_class, CLASS_MANGLE(class))) (\
        (next_class, class__)namespace \
    , \
        (next_class, TYPE_NAME(next_class))OOP_G_BT_NS(namespace, next_class) \
    )
// diagnostics in next line before G_SEARCH_#: namespace, class, next_class 
#define G_SEARCH_0_0(namespace, member, class, next_class) G_SEARCH_1(G_SEARCH_UPDATE_NAMESPACE_0(namespace, class, next_class), member, next_class)
#define G_SEARCH_1_0(namespace, member, class, next_class) G_SEARCH_0(G_SEARCH_UPDATE_NAMESPACE_0(namespace, class, next_class), member, next_class)
#define G_SEARCH_NEXT_0(namespace, member, class) G_SEARCH_0_0(namespace, member, class, 
#define G_SEARCH_NEXT_1(namespace, member, class) G_SEARCH_1_0(namespace, member, class, 
#define G_SEARCH_ G_SEARCH_0
#define G_SEARCH(namespace, member, hier) G_SEARCH_(namespace, member, hier OOP_END)
#define OOP_GET(class, inst, member) (inst) S_REV(G_SEARCH((class, ), member, OOP_CLASS_G_HIER_##class)) member


//#define OOP_GET(class, inst, member) OOP_IF(IS_IN_G(member, GET_MEMBER_NAMES(class)))( (inst).member ERASE_ARGS, not yet implemented ERASE_ARGS)(class, member)
#define OOP_SUPER_2(A, inst) (inst). TYPE_NAME(G_1ST(OOP_CLASS_G_PARENT_##A))
#define OOP_SUPER_3(A, inst, B) (inst). TYPE_NAME(B)
#define OOP_SUPER(...) T_INSPECT_3(__VA_ARGS__, OOP_SUPER_3, OOP_SUPER_2)(__VA_ARGS__)

// 2-form does not really make sense
#define OOP_INTERFACE_2(A, inst) (inst).class__->TYPE_NAME(G_1ST(CAT(OOP_CLASS_G_PARENT_, CLASS_MANGLE(A))))
#define OOP_INTERFACE_3(A, inst, B) OOP_GET(A, inst, TYPE_NAME(B))
#define OOP_INTERFACE(...) T_INSPECT_3(__VA_ARGS__, OOP_INTERFACE_3, OOP_INTERFACE_2)(__VA_ARGS__)

// modify __INIT__ so that it calls a generic init algorithm that assigns the first element class__
//#define INIT(name, inst) (inst).class__ = &OOP_CLASS_INST(name)
#define OOP_INIT(name, inst) inst = (name) {.class__ = &OOP_CLASS_INST(name)}
#define OOP_DECLARE(name, inst) name OOP_INIT(name, inst)
#define OOP_NEW(name, pinst) name * pinst = (name *) malloc(sizeof(name)); OOP_INIT(name, *pinst);
#define OOPC(func) OOP_##func EMPTY()