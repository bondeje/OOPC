/* VARIADICS */   
/* tuple access */   
/* tuple conversion DOES NOT CURRENTLY WORK FOR 0 arguments. CURRENTLY, must pass at least one argument */   
// probably or definitely shared   
//   
//#define ACCESSOR OOP_ACCESSOR   
// directives   
/* sequence actions */   
/* transform a sequence to a guide*/   
/* prepend a name to the guide arguments list so that I can associate classes with members */   
// TODO: need to rename prepend macro since it does more than that   
//HASH_LIT define OOP_CLASS_G_##name name //
    
// recursive inspection of 1 element guide   
/* make initialization statement */   
// prepend a member pointer to the class definition   
 # include <public_macros.h> 
 # include <stdlib.h> 
 # include <stdio.h>   
 # ifndef OOP_MEMBER_A 
 # define OOP_MEMBER_A( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 # define OOP_MEMBER_size( x ) x 
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
 # define OOP_MEMBERS_T_A (class__) (A0) , (size) (new) (init) (del) 
 typedef struct A A; 
 typedef struct A_CLASS A_CLASS; 
 struct A_CLASS {
 
     size_t size; 
     A * ( * new ) ( ); 
     void ( * init ) ( ); 
     void ( * del ) ( A * ); 
 }; 
 struct A { 
 
     A_CLASS * class__; 
     int A0; 
 }; 
 static A * A__NEW__(); 
 static void A__INIT__(A * inst); 
 static void A__DEL__(A * inst); A_CLASS A_CLASS__ = {sizeof(A), A__NEW__, A__INIT__, A__DEL__}; 
 
 A A_INIT = {&A_CLASS__, 0};
 static A * A__NEW__() { 
     A * inst = (A *) malloc(sizeof(A)); 
     if (!inst) {return NULL;}; 
     A_CLASS__.init(inst); 
     return inst; 
 } 
 static void A__INIT__(A * inst) { 
     *inst = (A) {0}; 
     inst->class__ = &A_CLASS__; 
 ; 
 } 
 static void A__DEL__(A * inst) { 
     free(inst); 
 } 
   
 # ifndef OOP_MEMBER_B 
 # define OOP_MEMBER_B( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 # define OOP_MEMBER_size( x ) x 
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
 # ifndef OOP_MEMBER_B0 
 # define OOP_MEMBER_B0( x ) x 
 # endif 
 # define OOP_CLASS_G_PARENT_B A) OOP_CLASS_G_PARENT_A 
 # define OOP_MEMBERS_T_B (class__) (A__) (B0) , (size) (new) (init) (del) 
 typedef struct B B; 
 typedef struct B_CLASS B_CLASS; 
 struct B_CLASS {
 
     size_t size; 
     B * ( * new ) ( ); 
     void ( * init ) ( ); 
     void ( * del ) ( B * ); 
 }; 
 struct B { 
 
     B_CLASS * class__; 
     A A__; 
     float B0; 
 }; 
 static B * B__NEW__(); 
 static void B__INIT__(B * inst); 
 static void B__DEL__(B * inst); B_CLASS B_CLASS__ = {sizeof(B), B__NEW__, B__INIT__, B__DEL__}; 
 
 B B_INIT = {&B_CLASS__, 0};
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
 ; 
 } 
 static void B__DEL__(B * inst) { 
     free(inst); 
 } 
   
 # ifndef OOP_MEMBER_C 
 # define OOP_MEMBER_C( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 # define OOP_MEMBER_size( x ) x 
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
 # define OOP_CLASS_G_PARENT_C A) OOP_CLASS_G_PARENT_A 
 # define OOP_MEMBERS_T_C (class__) (A__) (C0) , (size) (new) (init) (del) 
 typedef struct C C; 
 typedef struct C_CLASS C_CLASS; 
 struct C_CLASS {
 
     size_t size; 
     C * ( * new ) ( ); 
     void ( * init ) ( ); 
     void ( * del ) ( C * ); 
 }; 
 struct C { 
 
     C_CLASS * class__; 
     A A__; 
     double C0; 
 }; 
 static C * C__NEW__(); 
 static void C__INIT__(C * inst); 
 static void C__DEL__(C * inst); C_CLASS C_CLASS__ = {sizeof(C), C__NEW__, C__INIT__, C__DEL__}; 
 
 C C_INIT = {&C_CLASS__, 0};
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
 ; 
 } 
 static void C__DEL__(C * inst) { 
     free(inst); 
 } 
   
 # ifndef OOP_MEMBER_D 
 # define OOP_MEMBER_D( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
 # define OOP_MEMBER_size( x ) x 
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
 # ifndef OOP_MEMBER_D0 
 # define OOP_MEMBER_D0( x ) x 
 # endif 
 # define OOP_CLASS_G_PARENT_D B) OOP_CLASS_G_PARENT_B C) OOP_CLASS_G_PARENT_C 
 # define OOP_MEMBERS_T_D (class__) (B__) (C__) (D0) , (size) (new) (init) (del) 
 typedef struct D D; 
 typedef struct D_CLASS D_CLASS; 
 struct D_CLASS {
 
     size_t size; 
     D * ( * new ) ( ); 
     void ( * init ) ( ); 
     void ( * del ) ( D * ); 
 }; 
 struct D { 
 
     D_CLASS * class__; 
     B B__; 
     C C__; 
     size_t D0; 
 }; 
 static D * D__NEW__(); 
 static void D__INIT__(D * inst); 
 static void D__DEL__(D * inst); D_CLASS D_CLASS__ = {sizeof(D), D__NEW__, D__INIT__, D__DEL__}; 
 
 D D_INIT = {&D_CLASS__, 0};
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
 ; 
 } 
 static void D__DEL__(D * inst) { 
     free(inst); 
 } 
   
/*   
CLASS(D,PARENT(B)PARENT(C)CLASS_FUNCTION(NULL, void, init, double *, char)CLASS_MEMBER(0, size_t, n)CLASS_MEMBER("what", char, buf, 128)FUNCTION(double, process, A *, unsigned int)MEMBER(int, x)MEMBER(int, vertices, 4))   
MBER(int, vertices, 4)\   
)   
*/   
