#include <oopc.h>

#ifndef IMPORT_DECLARE_CALLABLE
IFNDEF CALLABLE_H
DEFINE CALLABLE_H

INCLUDE_OOPC

/**
 * \typedef call function typedef
 */
IFNDEF OMIT_STRUCT_DECLS
IFNDEF IMPORT_CLASS_DEFS_ONLY
typedef int (*call_t)(void *, ...);
ENDIF
ENDIF

DEFINE CALL(type, pinst, ...) SPLIT(OOP_INTERFACE)(type, *pinst, Callable).call(pinst, CATD(__VA, ARGS__, _))

DEFINE GET_CALLABLE(type, func) Callable_##type##_##func
DEFINE IMPLEMENT_CALLABLE(type, func) SPLIT(CATD)(IMPLEMENT, SPLIT(GET_CALLABLE)(type, func), _)

/**
 * 
 * @interface Callable callable.h
 * @brief Callable object class.
 * @property call - the function to be called. See documentation for call function
 * @details Instances are creatable and the object struct is extendable. If extended, child class should also implement Creatable and override the new, init, and del functions
 * 
 * @fn void call(void * self, ...)
 * @brief call callable object
 * @param[in] self - object to be called
 * @param[in, out] ... - variable number of arguments to call function
 *  
 */
CLASS(Callable,
    MEMBER(call_t, call)   
)
ENDIF // CALLABLE_H

// IMPORT_MAKE_CALLABLE_H defined
#else
IFNDEF IMPORT_CLASS_DEFS_ONLY
INCLUDE <stdarg.h>
ENDIF

#define GET_CALLABLE(type, func) Callable_##type##_##func

#ifndef OOP_MEMBER_void
    #define OOP_MEMBER_void(x) x
#endif
#ifndef OOP_MEMBER_float
    #define OOP_MEMBER_float(x) x
#endif

// need the switch statement to work to handle all the default promotions. Only covers float right now

#define TYPE_LIST_VA_LIST_TO_DECLS_0(va_list_, v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_VA_LIST_TO_DECLS_NEXT)(va_list_, v_name, type, 1)
#define TYPE_LIST_VA_LIST_TO_DECLS_1(va_list_, v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_VA_LIST_TO_DECLS_NEXT)(va_list_, v_name, type, 0)
#define TYPE_LIST_VA_LIST_TO_DECLS_NEXT(va_list_, v_name, type, next) type v_name = va_arg(va_list_, OOP_IF(EQUAL(type, float))(double, type)); TYPE_LIST_VA_LIST_TO_DECLS_##next(va_list_, CAT(v_name,_),
#define TYPE_LIST_VA_LIST_TO_DECLS__ TYPE_LIST_VA_LIST_TO_DECLS_0
#define TYPE_LIST_VA_LIST_TO_DECLS_(va_list_, temp_, guide) TYPE_LIST_VA_LIST_TO_DECLS__(va_list_, temp_, guide OOP_END)
#define TYPE_LIST_VA_LIST_TO_DECLS(va_list_, ...) TYPE_LIST_VA_LIST_TO_DECLS_(va_list_, temp_, S_TO_G(ERASE_ARGS T_TO_S(__VA_ARGS__)))

#define TYPE_LIST_TO_ARGS_0(v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_TO_ARGS_NEXT)(v_name, type, 1)
#define TYPE_LIST_TO_ARGS_1(v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_TO_ARGS_NEXT)(v_name, type, 0)
#define TYPE_LIST_TO_ARGS_NEXT(v_name, type, next) , v_name TYPE_LIST_TO_ARGS_##next(CAT(v_name, _), 
#define TYPE_LIST_TO_ARGS__ TYPE_LIST_TO_ARGS_0
#define TYPE_LIST_TO_ARGS_(v_name, guide) TYPE_LIST_TO_ARGS__(v_name, guide OOP_END)
#define TYPE_LIST_TO_ARGS(...) TYPE_LIST_TO_ARGS_(temp_, S_TO_G(ERASE_ARGS T_TO_S(__VA_ARGS__)))

/**
 * 
 * TODO: only make available for def.h files. This will simplify things a lot as I don't have to double-hide things. The macros will exist in callable.def.h directly. Need to include guard the other stuff those
 * 
 * declare prototypes and emit a macro to implement functions that take a pointer to \p type as their first argument into appropriate functions to make an instance of the \p type callable
 * 
 * "..." are the other arguments. Currently, 'func' MUST take type * as its first argument.
 */
#define DECLARE_CALLABLE(type, ret, func, ...) \
IFNDEF IMPORT_CLASS_DEFS_ONLY \
OOP_NEWLINE \
int GET_CALLABLE(type, func)(void *, ...); OOP_NEWLINE \
OOP_IF(EQUAL(ret, void))( \
    int CAT(v, GET_CALLABLE(type, func))(type *, va_list); \
    , \
    int CAT(v, GET_CALLABLE(type, func))(type *, va_list); \
) OOP_NEWLINE \
ENDIF /* IMPORT_CLASS_DEFS_ONLY */ \
OOP_NEWLINE \
DEFINE CAT(IMPLEMENT_, GET_CALLABLE(type, func)) \
int SPLIT(GET_CALLABLE)(type, func)(void * t_, ...) { \
    va_list args; \
    va_start(args, t_); \
    int result = SPLIT(CAT)(v, SPLIT(GET_CALLABLE)(type, func))((type *) t_, args); \
    va_end(args); \
    return result; \
} \
OOP_IF(EQUAL(ret, void)) (\
int SPLIT(CAT)(v, SPLIT(GET_CALLABLE)(type, func))(type * t_, va_list args) { \
    if (!t_) { \
        return 1; \
    } \
    TYPE_LIST_VA_LIST_TO_DECLS(args, __VA_ARGS__) \
    func(t_ TYPE_LIST_TO_ARGS(__VA_ARGS__)); \
    return 0; \
} \
, \
int SPLIT(CAT)(v, SPLIT(GET_CALLABLE)(type, func))(type * t_, va_list args) { \
    if (!t_) { \
        return 1; \
    } \
    ret * pret = va_arg(args, ret *); \
    if (!pret) { \
        return 1; \
    } \
    TYPE_LIST_VA_LIST_TO_DECLS(args, __VA_ARGS__) \
    *pret = func(t_ TYPE_LIST_TO_ARGS(__VA_ARGS__)); \
    return 0; \
} \
)
/**/
#endif // IMPORT_DECLARE_CALLABLE
