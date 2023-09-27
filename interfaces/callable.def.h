#include <oopc.h>

// guard against defs.h files that are looking to import the MAKE_CALLABLE functionality.
// TODO: need to block more of the file as MAKE_CALLABLE only should require the oopc.h header and the associated macros
IFNDEF INCLUDES_CALLABLE
INCLUDE_OOPC
INCLUDE <creatable.h>
ELSE
INCLUDE <oopc.h>
ENDIF

/**
 * 
 * @fn void * Callable_new(unsigned int n, ...)
 * @brief create a new Callable object on the heap
 * @param[in] n - the number of arguments passed in the variadic
 * @param[in, out] ... - variable number of arguments to instantiate Callable object
 * @return a new Callable object on the heap
 *   
 */
void * Callable_new(unsigned int n, ...);

/**
 * 
 * @fn void Callable_init(unsigned int n, ...)
 * @brief instantiate a new Callable object
 * @param[in, out] self - the Callable object
 * @param[in] n - the number of arguments passed in the variadic
 * @param[in, out] ... - variable number of arguments to instantiate Callable object
 *  
 */
void Callable_init(void * self, unsigned int n, ...);

/**
 * 
 * @fn void Callable_del(void * self)
 * @brief delete a Callable object created with Callable_new
 * @param[in] self - the Callable object
 *  
 */
void Callable_del(void * self);

/**
 * \typedef call function typedef
 */
typedef void (*call_t)(void *, ...);

IFNDEF OOP_MEMBER_void
    DEFINE OOP_MEMBER_void(x) x
ENDIF

DEFINE GET_CALLABLE(type, func) Callable_##type##_##func

DEFINE TYPE_LIST_VA_LIST_TO_DECLS_0(va_list_, v_name, type) SPLIT(OOP_IF)(SPLIT(IS_OOP_END)(type))(ERASE_ARGS, TYPE_LIST_VA_LIST_TO_DECLS_NEXT)(va_list_, v_name, type, 1)
DEFINE TYPE_LIST_VA_LIST_TO_DECLS_1(va_list_, v_name, type) SPLIT(OOP_IF)(SPLIT(IS_OOP_END)(type))(ERASE_ARGS, TYPE_LIST_VA_LIST_TO_DECLS_NEXT)(va_list_, v_name, type, 0)
DEFINE TYPE_LIST_VA_LIST_TO_DECLS_NEXT(va_list_, v_name, type, next) type v_name = va_arg(va_list_, type); TYPE_LIST_VA_LIST_TO_DECLS_##next(va_list_, SPLIT(CAT)(v_name,_),
DEFINE TYPE_LIST_VA_LIST_TO_DECLS__ TYPE_LIST_VA_LIST_TO_DECLS_0
DEFINE TYPE_LIST_VA_LIST_TO_DECLS_(va_list_, temp_, guide) TYPE_LIST_VA_LIST_TO_DECLS__(va_list_, temp_, guide OOP_END)
/**
 * TODO: a macro to turn a list of types into a sequence of declarations grabbing the values from a va_list and then inserting them into a call
 * TYPE_LIST_VA_LIST_TO_ARGS(va_list, types...)
 */
DEFINE TYPE_LIST_VA_LIST_TO_DECLS(va_list_, ...) TYPE_LIST_VA_LIST_TO_DECLS_(va_list_, temp_, SPLIT(S_TO_G)(SPLIT(T_TO_S)(__VA_ARGS__)))

DEFINE TYPE_LIST_TO_ARGS_0(v_name, type) SPLIT(OOP_IF)(SPLIT(IS_OOP_END)(type))(ERASE_ARGS, TYPE_LIST_TO_ARGS_NEXT)(v_name, type, 1)
DEFINE TYPE_LIST_TO_ARGS_1(v_name, type) SPLIT(OOP_IF)(SPLIT(IS_OOP_END)(type))(ERASE_ARGS, TYPE_LIST_TO_ARGS_NEXT)(v_name, type, 0)
DEFINE TYPE_LIST_TO_ARGS_NEXT(v_name, type, next) , v_name TYPE_LIST_TO_ARGS_##next(SPLIT(CAT)(v_name, _), 
DEFINE TYPE_LIST_TO_ARGS__ TYPE_LIST_TO_ARGS_0
DEFINE TYPE_LIST_TO_ARGS_(v_name, guide) TYPE_LIST_TO_ARGS__(v_name, guide OOP_END)
DEFINE TYPE_LIST_TO_ARGS(...) TYPE_LIST_TO_ARGS_(temp_, SPLIT(S_TO_G)(SPLIT(T_TO_S)(CATD(__VA, ARGS__, _))))

DEFINE CALL(pcallable, ...) pcallable->call(pcallable->obj, CATD(__VA, ARGS__, _))

#define SPACE SPLIT(CATD)(OOP, NEWLINE,_)

/**
 * 
 * TODO: only make available for def.h files. This will simplify things a lot as I don't have to double-hide things. The macros will exist in callable.def.h directly. Need to include guard the other stuff those
 * 
 * declare prototypes and emit a macro to implement functions that take a pointer to \p type as their first argument into appropriate functions to make an instance of the \p type callable
 * 
 * "..." are the other arguments. Currently, 'func' MUST take type * as its first argument. the return argument
 */
DEFINE MAKE_CALLABLE(type, ret, func, ...) SPACE \
void GET_CALLABLE(type, func)(void *, ...); SPACE \
SPLIT(OOP_IF)(SPLIT(EQUAL)(ret, void))( SPACE \
    void SPLIT(CAT)(v, SPLIT(GET_CALLABLE)(type, func))(type, func)(type *, va_list); SPACE \
    , \
    void SPLIT(CAT)(v, SPLIT(GET_CALLABLE)(type, func))(type *, ret *, va_list); SPACE \
) SPACE \
SPLIT(CAT)(DEF,INE) SPLIT(CAT)(SPLIT(GET_CALLABLE)(type, func), _IMPLEMENTATION)  \
void GET_CALLABLE(type, func)(void * t_, ...) { \
    va_list args; \
    va_start(args, t_); \
    SPLIT(SPLIT)(CAT)(v, SPLIT(SPLIT)(GET_CALLABLE)(type, func))((type *) t_, args); \
    va_end(args); \
} SPLIT(OOP_IF)(SPLIT(EQUAL)(ret, void))( \
    void SPLIT(SPLIT)(CAT)(v, SPLIT(GET_CALLABLE(type, func)))(type * t_, va_list args) { \
        SPLIT(SPLIT(TYPE_LIST_VA_LIST_TO_DECLS))(args, CATD(__VA, ARGS__, _)) \
        func(t_ SPLIT(SPLIT(TYPE_LIST_TO_ARGS))(CATD(__VA, ARGS__, _))) \
    } \
    , \
    void SPLIT(SPLIT)(CAT)(v, SPLIT(GET_CALLABLE(type, func)))(type * t_, va_list args) { \
        ret * pret = va_arg(args, ret *); \
        SPLIT(SPLIT(TYPE_LIST_VA_LIST_TO_DECLS))(args, CATD(__VA, ARGS__, _)) \
        *pret = func(t_ SPLIT(SPLIT(TYPE_LIST_TO_ARGS))(CATD(__VA, ARGS__, _))); \
    } \
)

/**
 * 
 * @interface Callable callable.h
 * @brief Callable object class.
 * @property obj - the object to be called
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
    MEMBER(void *, obj)
    MEMBER(call_t, call)
    IMPLEMENTS(Creatable, new, Callable_new, init, Callable_init, del, Callable_del)
    
)
