// general notes on data structures   
// macros beginning with T manipulate tuples   
// macros beginning with S manipulate sequence inputs   
// macros beginning with G manipulate guide inputs   
// directives   
// Generic meta-programming macros   
/* tuple access */   
/* VARIADICS */   
/* tuple conversion DOES NOT CURRENTLY WORK FOR 0 arguments. CURRENTLY, must pass at least one argument */   
/* miscellaneous */   
/* stringify */   
/* concatenations */   
// output with a delimiter between   
// output with a space between   
// concatenate with a comma space   
/* parenthesis manipulation and checking */   
// only works if x does not start with a set of '()'. Worse if x is a sequence of (...)x for any x, results in '1'   
/* recursion utilities */   
// check if this is actually used   
// check if this is actually used   
// check if this is actually used   
// OOP_NOT is definitely used   
/* comparisons */   
// for switch statement, turn tuple into seqence, processing each element   
// IF_CASE iterates through a sequence of condition/result pairs and returns the first true value from the subsequent tuple of arguments. mark an "else" case as (1)   
// e.g. S_IF((cond_0, result_0)(cond_1, result_1)(cond_2, result_2)...(1, else_result)) returns result_1 if cond_0 is 0 and cond_1 is 1   
/* STRUCTURE ALGORITHMS */   
/* sequence operations */   
// erase the rest of a seq. If already post-pended with (OOP_END) start call at S_ERASE_   
// the next two lines are original, they might resolve better   
//#define S_ERASE_0(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ERASE_ARGS), S_ERASE_NEXT)(1)   
//#define S_ERASE_1(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ERASE_ARGS), S_ERASE_NEXT)(0)   
// this should be pretty powerful...compound if statements. From a sequence cond_seq of pairs (cond, val), selects the first val where cond is true   
// the guide version is going to be even better   
// the next two lines are original, they might resolve better   
//#define S_IF_0(cond, result) T_INSPECT_1(OOP_IF(IS_OOP_END(cond))(PASS_ARGS, ERASE_ARGS)(,), OOP_IF(cond)(result S_ERASE_0, S_IF_1))   
//#define S_IF_1(cond, result) T_INSPECT_1(OOP_IF(IS_OOP_END(cond))(PASS_ARGS, ERASE_ARGS)(,), OOP_IF(cond)(result S_ERASE_0, S_IF_0))   
// transform sequence to guide data structure   
// the next two lines are original, they might resolve better   
//#define S_TO_G_0(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ), __VA_ARGS__ OBSTRUCT(RPAREN)() S_TO_G_1)   
//#define S_TO_G_1(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ), __VA_ARGS__ OBSTRUCT(RPAREN)() S_TO_G_0)   
// S_JOIN only combines the elements in the sequence, but it cannot put in delimiters. for that, use G_JOIN   
// erase of the remainder of a guide. Note that if guide iteration has already started, need to call PASS_ARGS(G_ERASE_ LPAREN() guide)   
// old probably delete   
//#define G_1ST_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , G_1ST_1 LPAREN())   
//#define G_1ST_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , G_1ST_0 LPAREN())   
// return only the first element of the guide.   
// this can probably be replaced by G_JOIN where the func returns a guide element   
// same as G_TO_G but func takes arguments   
// useful functions for G_TO_G   
// this can probably be replaced by a call to G_JOIN where the func returns a sequence element   
// can probably generalize this to all transformations by adding an "args" argument so that the function is called func(OOP_IF(IS_PAREN(args)))(PASS_ARGS args, PASS_ARGS(args)), __VA_ARGS__)   
// helper for reverse namespace sequence   
// reverse a sequence, but does much more   
// reversing a guide is just convert to sequence --> reverse --> convert back to guide   
// macros that should only be available for the conversion of class definitions to header files   
/* tuple access */   
/* VARIADICS */   
/* tuple conversion DOES NOT CURRENTLY WORK FOR 0 arguments. CURRENTLY, must pass at least one argument */   
/* name mangling */   
/* class data structure algorithms */   
//#define OOP_CLASS_G_HIERARCHY(name) name) CLASS_MANGLE(name)) CATD(OOP_CLASS_G_PARENT, CLASS_MANGLE(name), _) OOP_CLASS_G_PARENT_##name   
// special backtracking function   
/*   
#define G_BT_PASS_ACC(dummy, accessor) dummy, accessor   
#define G_BT_ADD(next_class, dummy, accessor, class, id, next) dummy, accessor) class, id)   
#define G_BT_0(next_class, dummy, accessor, class, id) OOP_IF(IS_OOP_END(dummy))(ERASE_ARGS, OOP_IF(IS_PARENT(Next_class, class))(G_BT_ADD, G_BT_NEXT))(next_class, dummy, accessor, class, id, 1)   
#define G_BT_1(next_class, dummy, accessor, class, id) OOP_IF(IS_OOP_END(dummy))(ERASE_ARGS, OOP_IF(IS_PARENT(Next_class, class))(G_BT_ADD, G_BT_NEXT))(next_class, dummy, accessor, class, id, 0)   
#define G_BT_NEXT(next_class, dummy, accessor, class, id, next) G_BT_##next(next_class, G_BT_PASS_ACC(   
#define G_BT_ G_BT_0   
#define G_BT(next_class, ns_g) G_BT_(next_class, G_BT_PASS_ACC LPAREN() ns_g OOP_END,,,)   
#define S_BT(namespace, next_class) G_BT(next_class, S_TO_G(namespace))   
*/   
// variadic is a set of name, value pairs associating function names from interface to their implementations (value)   
// recursive inspection of 1 element guide   
// prepend a member pointer to the class definition   
// NOTE: cannot use the G_TO_S functionality...for some reason, it is not working, so once a proper parent is found, continue through guide converting it to a sequence   
//#define OOP_G_BT_NS_FOUND(next_class, next, ...) OOP_BT_GET_CUR_CLASS(__VA_ARGS__), OOP_BG_GET_NAME(__VA_ARGS__))   
//#define OOP_G_BT_NS_(namespace, next_class)  PASS_ARGS(G_TO_S_ EMPTY() LPAREN(),  FARGEVAL(OOP_G_BT_NS__,  (next_class, S_TO_G(namespace) OOP_END)))   
//#define OOP_G_BT_NS(namespace, next_class) FARGEVAL(PASS_ARGS_, OOP_G_BT_NS_(namespace, next_class))   
// rework this one so that it iterates over namespace until OOP(IS_PARENT) is true   
// diagnostics in next line before G_SEARCH_#: namespace, class, next_class    
//#define OOP_GET(class, inst, member) OOP_IF(IS_IN_G(member, GET_MEMBER_NAMES(class)))( (inst).member ERASE_ARGS, not yet implemented ERASE_ARGS)(class, member)   
// 2-form does not really make sense   
// modify __INIT__ so that it calls a generic init algorithm that assigns the first element class__   
 # include <oopc.h> 
 # include <stdlib.h> 
 # include <stdio.h>   
 # ifndef OOP_MEMBER_I 
     # define OOP_MEMBER_I( x ) x 
 # endif 
 # ifndef OOP_MEMBER_I_CLASS 
     # define OOP_MEMBER_I_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_new 
     # define OOP_MEMBER_new( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_to_dbl 
     # define OOP_MEMBER_to_dbl( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_I 
 # define OOP_CLASS_G_HIER_I I) OOP_CLASS_G_HIER_I_CLASS OOP_CLASS_G_PARENT_I 
 # define OOP_CLASS_G_PARENT_I_CLASS 
 # define OOP_CLASS_G_HIER_I_CLASS I_CLASS) OOP_CLASS_G_PARENT_I_CLASS 
 # define OOP_MEMBERS_G_I MEMBER_TYPE, (I_CLASS * class__;, I_CLASS *, class__, OOP_NO_DEFAULT, sizeof(I_CLASS *)) ) FUNCTION_TYPE, (double ( * to_dbl ) ( void * );, ftype_to_dbl_6, to_dbl, (NULL), sizeof(void*), typedef double ( * ftype_to_dbl_6 ) ( void * );) ) 
 # define OOP_MEMBERS_G_I_CLASS CLASS_FUNCTION_TYPE, (I * ( * new ) ( );, ftype_new_5, new, (I__NEW__), sizeof(void *), typedef I * ( * ftype_new_5 ) ( );) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( I * );, ftype_init_5, init, (I__INIT__), sizeof(void *), typedef void ( * ftype_init_5 ) ( I * );) ) CLASS_FUNCTION_TYPE, (void ( * del ) ( I * );, ftype_del_5, del, (I__DEL__), sizeof(void *), typedef void ( * ftype_del_5 ) ( I * );) ) 
 
 typedef struct I I; 
 typedef struct I_CLASS I_CLASS; 
 struct I_CLASS { 
     I * ( * new ) ( ); 
     void ( * init ) ( I * ); 
     void ( * del ) ( I * ); 
 }; 
 struct I { 
     I_CLASS * class__; 
     double ( * to_dbl ) ( void * ); 
 
 }; 
 static I * I__NEW__(); 
 static void I__INIT__(I * inst); 
 static void I__DEL__(I * inst); 
 /*static CLASS_MANGLE(name) CLASS_INST(name) = {CAT(name,__NEW__), CAT(name,__INIT__), CAT(name,__DEL__)};*/ 
 static I_CLASS I_CLASS__ = {.new = I__NEW__, .init = I__INIT__, .del = I__DEL__, }; 
 static I * I__NEW__() { 
     I * inst = (I *) malloc(sizeof(I)); 
     if (!inst) {return NULL;}; 
     I_CLASS__.init(inst); 
     return inst; 
 } 
 static void I__INIT__(I * inst) { 
     *inst = (I) {0}; 
     inst->class__ = &I_CLASS__; 
 
 } 
 static void I__DEL__(I * inst) { 
     free(inst); 
 } 
   
 # ifndef OOP_MEMBER_A 
     # define OOP_MEMBER_A( x ) x 
 # endif 
 # ifndef OOP_MEMBER_A_CLASS 
     # define OOP_MEMBER_A_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_new 
     # define OOP_MEMBER_new( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_A0 
     # define OOP_MEMBER_A0( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_A 
 # define OOP_CLASS_G_HIER_A A) OOP_CLASS_G_HIER_A_CLASS OOP_CLASS_G_PARENT_A 
 # define OOP_CLASS_G_PARENT_A_CLASS 
 # define OOP_CLASS_G_HIER_A_CLASS A_CLASS) OOP_CLASS_G_PARENT_A_CLASS 
 # define OOP_MEMBERS_G_A MEMBER_TYPE, (A_CLASS * class__;, A_CLASS *, class__, OOP_NO_DEFAULT, sizeof(A_CLASS *)) ) MEMBER_TYPE, (int A0;, int, A0, OOP_NO_DEFAULT, sizeof(int)) ) 
 # define OOP_MEMBERS_G_A_CLASS CLASS_FUNCTION_TYPE, (A * ( * new ) ( );, ftype_new_9, new, (A__NEW__), sizeof(void *), typedef A * ( * ftype_new_9 ) ( );) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( A * );, ftype_init_9, init, (A__INIT__), sizeof(void *), typedef void ( * ftype_init_9 ) ( A * );) ) CLASS_FUNCTION_TYPE, (void ( * del ) ( A * );, ftype_del_9, del, (A__DEL__), sizeof(void *), typedef void ( * ftype_del_9 ) ( A * );) ) 
 
 typedef struct A A; 
 typedef struct A_CLASS A_CLASS; 
 struct A_CLASS { 
     A * ( * new ) ( ); 
     void ( * init ) ( A * ); 
     void ( * del ) ( A * ); 
 }; 
 struct A { 
     A_CLASS * class__; 
     int A0; 
 
 }; 
 static A * A__NEW__(); 
 static void A__INIT__(A * inst); 
 static void A__DEL__(A * inst); 
 /*static CLASS_MANGLE(name) CLASS_INST(name) = {CAT(name,__NEW__), CAT(name,__INIT__), CAT(name,__DEL__)};*/ 
 static A_CLASS A_CLASS__ = {.new = A__NEW__, .init = A__INIT__, .del = A__DEL__, }; 
 static A * A__NEW__() { 
     A * inst = (A *) malloc(sizeof(A)); 
     if (!inst) {return NULL;}; 
     A_CLASS__.init(inst); 
     return inst; 
 } 
 static void A__INIT__(A * inst) { 
     *inst = (A) {0}; 
     inst->class__ = &A_CLASS__; 
 
 } 
 static void A__DEL__(A * inst) { 
     free(inst); 
 } 
   
 # ifndef OOP_MEMBER_B 
     # define OOP_MEMBER_B( x ) x 
 # endif 
 # ifndef OOP_MEMBER_B_CLASS 
     # define OOP_MEMBER_B_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_new 
     # define OOP_MEMBER_new( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_A__ 
     # define OOP_MEMBER_A__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_n 
     # define OOP_MEMBER_n( x ) x 
 # endif 
 # ifndef OOP_MEMBER_B0 
     # define OOP_MEMBER_B0( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_B OOP_CLASS_G_HIER_A 
 # define OOP_CLASS_G_HIER_B B) OOP_CLASS_G_HIER_B_CLASS OOP_CLASS_G_PARENT_B 
 # define OOP_CLASS_G_PARENT_B_CLASS 
 # define OOP_CLASS_G_HIER_B_CLASS B_CLASS) OOP_CLASS_G_PARENT_B_CLASS 
 # define OOP_MEMBERS_G_B MEMBER_TYPE, (B_CLASS * class__;, B_CLASS *, class__, OOP_NO_DEFAULT, sizeof(B_CLASS *)) ) PARENT_TYPE, (A A__;, A, A__, (OOP_NO_DEFAULT), sizeof(A)) ) MEMBER_TYPE, (float B0;, float, B0, OOP_NO_DEFAULT, sizeof(float)) ) 
 # define OOP_MEMBERS_G_B_CLASS CLASS_FUNCTION_TYPE, (B * ( * new ) ( );, ftype_new_13, new, (B__NEW__), sizeof(void *), typedef B * ( * ftype_new_13 ) ( );) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( B * );, ftype_init_13, init, (B__INIT__), sizeof(void *), typedef void ( * ftype_init_13 ) ( B * );) ) CLASS_FUNCTION_TYPE, (void ( * del ) ( B * );, ftype_del_13, del, (B__DEL__), sizeof(void *), typedef void ( * ftype_del_13 ) ( B * );) ) CLASS_MEMBER_TYPE, (int n;, int, n, (0), sizeof(int)) ) 
 
 typedef struct B B; 
 typedef struct B_CLASS B_CLASS; 
 struct B_CLASS { 
     B * ( * new ) ( ); 
     void ( * init ) ( B * ); 
     void ( * del ) ( B * ); 
     int n; 
 }; 
 struct B { 
     B_CLASS * class__; 
     A A__; 
     float B0; 
 
 }; 
 static B * B__NEW__(); 
 static void B__INIT__(B * inst); 
 static void B__DEL__(B * inst); 
 /*static CLASS_MANGLE(name) CLASS_INST(name) = {CAT(name,__NEW__), CAT(name,__INIT__), CAT(name,__DEL__)};*/ 
 static B_CLASS B_CLASS__ = {.new = B__NEW__, .init = B__INIT__, .del = B__DEL__, .n = 0, }; 
 static B * B__NEW__() { 
     B * inst = (B *) malloc(sizeof(B)); 
     if (!inst) {return NULL;}; 
     B_CLASS__.init(inst); 
     return inst; 
 } 
 static void B__INIT__(B * inst) { 
     *inst = (B) {0}; 
     inst->class__ = &B_CLASS__; 
     A_CLASS__.init(&(inst-> A__)); 
 
 } 
 static void B__DEL__(B * inst) { 
     free(inst); 
 } 
   
 # ifndef OOP_MEMBER_C 
     # define OOP_MEMBER_C( x ) x 
 # endif 
 # ifndef OOP_MEMBER_C_CLASS 
     # define OOP_MEMBER_C_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_new 
     # define OOP_MEMBER_new( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_A__ 
     # define OOP_MEMBER_A__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_C0 
     # define OOP_MEMBER_C0( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_C OOP_CLASS_G_HIER_A 
 # define OOP_CLASS_G_HIER_C C) OOP_CLASS_G_HIER_C_CLASS OOP_CLASS_G_PARENT_C 
 # define OOP_CLASS_G_PARENT_C_CLASS 
 # define OOP_CLASS_G_HIER_C_CLASS C_CLASS) OOP_CLASS_G_PARENT_C_CLASS 
 # define OOP_MEMBERS_G_C MEMBER_TYPE, (C_CLASS * class__;, C_CLASS *, class__, OOP_NO_DEFAULT, sizeof(C_CLASS *)) ) PARENT_TYPE, (A A__;, A, A__, (OOP_NO_DEFAULT), sizeof(A)) ) MEMBER_TYPE, (double C0;, double, C0, OOP_NO_DEFAULT, sizeof(double)) ) 
 # define OOP_MEMBERS_G_C_CLASS CLASS_FUNCTION_TYPE, (C * ( * new ) ( );, ftype_new_19, new, (C__NEW__), sizeof(void *), typedef C * ( * ftype_new_19 ) ( );) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( C * );, ftype_init_19, init, (C__INIT__), sizeof(void *), typedef void ( * ftype_init_19 ) ( C * );) ) CLASS_FUNCTION_TYPE, (void ( * del ) ( C * );, ftype_del_19, del, (C__DEL__), sizeof(void *), typedef void ( * ftype_del_19 ) ( C * );) ) 
 
 typedef struct C C; 
 typedef struct C_CLASS C_CLASS; 
 struct C_CLASS { 
     C * ( * new ) ( ); 
     void ( * init ) ( C * ); 
     void ( * del ) ( C * ); 
 }; 
 struct C { 
     C_CLASS * class__; 
     A A__; 
     double C0; 
 
 }; 
 static C * C__NEW__(); 
 static void C__INIT__(C * inst); 
 static void C__DEL__(C * inst); 
 /*static CLASS_MANGLE(name) CLASS_INST(name) = {CAT(name,__NEW__), CAT(name,__INIT__), CAT(name,__DEL__)};*/ 
 static C_CLASS C_CLASS__ = {.new = C__NEW__, .init = C__INIT__, .del = C__DEL__, }; 
 static C * C__NEW__() { 
     C * inst = (C *) malloc(sizeof(C)); 
     if (!inst) {return NULL;}; 
     C_CLASS__.init(inst); 
     return inst; 
 } 
 static void C__INIT__(C * inst) { 
     *inst = (C) {0}; 
     inst->class__ = &C_CLASS__; 
     A_CLASS__.init(&(inst-> A__)); 
 
 } 
 static void C__DEL__(C * inst) { 
     free(inst); 
 } 
   
double size_t_to_dbl_x2p5(void * pD);   
 # ifndef OOP_MEMBER_D 
     # define OOP_MEMBER_D( x ) x 
 # endif 
 # ifndef OOP_MEMBER_D_CLASS 
     # define OOP_MEMBER_D_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_new 
     # define OOP_MEMBER_new( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_del 
     # define OOP_MEMBER_del( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_B__ 
     # define OOP_MEMBER_B__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_C__ 
     # define OOP_MEMBER_C__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_I__ 
     # define OOP_MEMBER_I__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_D0 
     # define OOP_MEMBER_D0( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_D OOP_CLASS_G_HIER_B OOP_CLASS_G_HIER_C 
 # define OOP_CLASS_G_HIER_D D) OOP_CLASS_G_HIER_D_CLASS OOP_CLASS_G_PARENT_D 
 # define OOP_CLASS_G_PARENT_D_CLASS OOP_CLASS_G_HIER_I 
 # define OOP_CLASS_G_HIER_D_CLASS D_CLASS) OOP_CLASS_G_PARENT_D_CLASS 
 # define OOP_MEMBERS_G_D MEMBER_TYPE, (D_CLASS * class__;, D_CLASS *, class__, OOP_NO_DEFAULT, sizeof(D_CLASS *)) ) PARENT_TYPE, (B B__;, B, B__, (OOP_NO_DEFAULT), sizeof(B)) ) PARENT_TYPE, (C C__;, C, C__, (OOP_NO_DEFAULT), sizeof(C)) ) MEMBER_TYPE, (size_t D0;, size_t, D0, OOP_NO_DEFAULT, sizeof(size_t)) ) 
 # define OOP_MEMBERS_G_D_CLASS CLASS_FUNCTION_TYPE, (D * ( * new ) ( );, ftype_new_26, new, (D__NEW__), sizeof(void *), typedef D * ( * ftype_new_26 ) ( );) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( D * );, ftype_init_26, init, (D__INIT__), sizeof(void *), typedef void ( * ftype_init_26 ) ( D * );) ) CLASS_FUNCTION_TYPE, (void ( * del ) ( D * );, ftype_del_26, del, (D__DEL__), sizeof(void *), typedef void ( * ftype_del_26 ) ( D * );) ) INTERFACE_TYPE, (I I__;, I, I__, ({.to_dbl = size_t_to_dbl_x2p5, }), sizeof(I)) ) 
 
 typedef struct D D; 
 typedef struct D_CLASS D_CLASS; 
 struct D_CLASS { 
     D * ( * new ) ( ); 
     void ( * init ) ( D * ); 
     void ( * del ) ( D * ); 
     I I__; 
 }; 
 struct D { 
     D_CLASS * class__; 
     B B__; 
     C C__; 
     size_t D0; 
 
 }; 
 static D * D__NEW__(); 
 static void D__INIT__(D * inst); 
 static void D__DEL__(D * inst); 
 /*static CLASS_MANGLE(name) CLASS_INST(name) = {CAT(name,__NEW__), CAT(name,__INIT__), CAT(name,__DEL__)};*/ 
 static D_CLASS D_CLASS__ = {.new = D__NEW__, .init = D__INIT__, .del = D__DEL__, .I__ = {.to_dbl = size_t_to_dbl_x2p5, }, }; 
 static D * D__NEW__() { 
     D * inst = (D *) malloc(sizeof(D)); 
     if (!inst) {return NULL;}; 
     D_CLASS__.init(inst); 
     return inst; 
 } 
 static void D__INIT__(D * inst) { 
     *inst = (D) {0}; 
     inst->class__ = &D_CLASS__; 
     B_CLASS__.init(&(inst-> B__)); 
     C_CLASS__.init(&(inst-> C__)); 
 
 } 
 static void D__DEL__(D * inst) { 
     free(inst); 
 } 
   
