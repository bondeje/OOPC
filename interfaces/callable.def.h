#include <oopc.h>

// TODO: major todo. Modify the implementations of Callable_new and Callable_init to handle the fact that member obj is const

// guard against defs.h files that are looking to import the MAKE_CALLABLE functionality.
// TODO: need to block more of the file as MAKE_CALLABLE only should require the oopc.h header and the associated macros
#ifndef IMPORT_MAKE_CALLABLE_H

IFNDEF CALLABLE_H
DEFINE CALLABLE_H

INCLUDE_OOPC
INCLUDE <creatable.h>

/**
 * \typedef call function typedef
 */
typedef void (*call_t)(void *, ...);

DEFINE CALL(type, pinst, ...) SPLIT(OOP_INTERFACE)(type, *pinst, Callable).call(pinst, CATD(__VA, ARGS__, _))

DEFINE GET_CALLABLE(type, func) Callable_##type##_##func

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

INCLUDE <oopc.h>
INCLUDE <stdarg.h>

#ifndef OOP_MEMBER_void
    #define OOP_MEMBER_void(x) x
#endif

#define GET_CALLABLE(type, func) Callable_##type##_##func

#define TYPE_LIST_VA_LIST_TO_DECLS_0(va_list_, v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_VA_LIST_TO_DECLS_NEXT)(va_list_, v_name, type, 1)
#define TYPE_LIST_VA_LIST_TO_DECLS_1(va_list_, v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_VA_LIST_TO_DECLS_NEXT)(va_list_, v_name, type, 0)
#define TYPE_LIST_VA_LIST_TO_DECLS_NEXT(va_list_, v_name, type, next) type v_name = va_arg(va_list_, type); TYPE_LIST_VA_LIST_TO_DECLS_##next(va_list_, CAT(v_name,_),
#define TYPE_LIST_VA_LIST_TO_DECLS__ TYPE_LIST_VA_LIST_TO_DECLS_0
#define TYPE_LIST_VA_LIST_TO_DECLS_(va_list_, temp_, guide) TYPE_LIST_VA_LIST_TO_DECLS__(va_list_, temp_, guide OOP_END)
#define TYPE_LIST_VA_LIST_TO_DECLS(va_list_, ...) TYPE_LIST_VA_LIST_TO_DECLS_(va_list_, temp_, S_TO_G(T_TO_S(__VA_ARGS__)))

#define TYPE_LIST_TO_ARGS_0(v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_TO_ARGS_NEXT)(v_name, type, 1)
#define TYPE_LIST_TO_ARGS_1(v_name, type) OOP_IF(IS_OOP_END(type))(ERASE_ARGS, TYPE_LIST_TO_ARGS_NEXT)(v_name, type, 0)
#define TYPE_LIST_TO_ARGS_NEXT(v_name, type, next) , v_name TYPE_LIST_TO_ARGS_##next(CAT(v_name, _), 
#define TYPE_LIST_TO_ARGS__ TYPE_LIST_TO_ARGS_0
#define TYPE_LIST_TO_ARGS_(v_name, guide) TYPE_LIST_TO_ARGS__(v_name, guide OOP_END)
#define TYPE_LIST_TO_ARGS(...) TYPE_LIST_TO_ARGS_(temp_, S_TO_G(T_TO_S(__VA_ARGS__)))

/**
 * 
 * TODO: only make available for def.h files. This will simplify things a lot as I don't have to double-hide things. The macros will exist in callable.def.h directly. Need to include guard the other stuff those
 * 
 * declare prototypes and emit a macro to implement functions that take a pointer to \p type as their first argument into appropriate functions to make an instance of the \p type callable
 * 
 * "..." are the other arguments. Currently, 'func' MUST take type * as its first argument. the return argument
 */
#define MAKE_CALLABLE(type, ret, func, ...) \
void GET_CALLABLE(type, func)(void *, ...); OOP_NEWLINE \
OOP_IF(EQUAL(ret, void))( \
    void CAT(v, GET_CALLABLE(type, func))(type *, va_list); \
    , \
    void CAT(v, GET_CALLABLE(type, func))(type *, ret *, va_list); \
) OOP_NEWLINE \
CAT(DEF,INE) CAT(GET_CALLABLE(type, func), _IMPLEMENTATION)  \
void GET_CALLABLE(type, func)(void * t_, ...) { \
    va_list args; \
    va_start(args, t_); \
    CAT(v, GET_CALLABLE(type, func))((type *) t_, args); \
    va_end(args); \
} OOP_IF(EQUAL(ret, void))( \
    void CAT(v, GET_CALLABLE(type, func))(type * t_, va_list args) { \
        TYPE_LIST_VA_LIST_TO_DECLS(args, __VA_ARGS__) \
        func(t_ TYPE_LIST_TO_ARGS(__VA_ARGS__)) \
    } \
    , \
    void CAT(v, GET_CALLABLE(type, func))(type * t_, va_list args) { \
        ret * pret = va_arg(args, ret *); \
        TYPE_LIST_VA_LIST_TO_DECLS(args, __VA_ARGS__) \
        *pret = func(t_ TYPE_LIST_TO_ARGS(__VA_ARGS__)); \
    } \
)


#endif // IMPORT_MAKE_CALLABLE_H
