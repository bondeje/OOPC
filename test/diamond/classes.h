 # include <oopc.h> 
 # include <stdlib.h> 
 # include <stdio.h>   
 # include <stddef.h>   
 # ifndef OOP_MEMBER_I 
     # define OOP_MEMBER_I( x ) x 
 # endif 
 # ifndef OOP_MEMBER_I_CLASS 
     # define OOP_MEMBER_I_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
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
 # define OOP_MEMBERS_G_I MEMBER_TYPE, (I_CLASS * class__;, I_CLASS *, class__, OOP_NO_DEFAULT, sizeof(I_CLASS *)) ) FUNCTION_TYPE, (double ( * to_dbl ) ( void * );, ftype_to_dbl_8, to_dbl, (NULL), sizeof(void*), typedef double ( * ftype_to_dbl_8 ) ( void * );) ) 
 # define OOP_MEMBERS_G_I_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) 
 
 # ifndef TYPEDEF_I 
     # define TYPEDEF_I 
     typedef struct I I; 
 # endif 
 # ifndef TYPEDEF_I_CLASS 
     # define TYPEDEF_I_CLASS 
     typedef struct I_CLASS I_CLASS; 
 # endif 
 struct I_CLASS { 
     void * class__; 
 }; 
 struct I { 
     I_CLASS * class__; 
     double ( * to_dbl ) ( void * ); 
 
 }; 
 static I_CLASS I_CLASS__ = {.class__ = NULL, }; 
   
 # ifndef TYPEDEF_A 
     # define TYPEDEF_A 
     typedef struct A A; 
 # endif   
void A_init(A *);   
 # ifndef OOP_MEMBER_A 
     # define OOP_MEMBER_A( x ) x 
 # endif 
 # ifndef OOP_MEMBER_A_CLASS 
     # define OOP_MEMBER_A_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_A0 
     # define OOP_MEMBER_A0( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_A 
 # define OOP_CLASS_G_HIER_A A) OOP_CLASS_G_HIER_A_CLASS OOP_CLASS_G_PARENT_A 
 # define OOP_CLASS_G_PARENT_A_CLASS 
 # define OOP_CLASS_G_HIER_A_CLASS A_CLASS) OOP_CLASS_G_PARENT_A_CLASS 
 # define OOP_MEMBERS_G_A MEMBER_TYPE, (A_CLASS * class__;, A_CLASS *, class__, OOP_NO_DEFAULT, sizeof(A_CLASS *)) ) MEMBER_TYPE, (int A0;, int, A0, OOP_NO_DEFAULT, sizeof(int)) ) 
 # define OOP_MEMBERS_G_A_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( A * );, ftype_init_17, init, (A_init), sizeof(void *), typedef void ( * ftype_init_17 ) ( A * );) ) 
 
 # ifndef TYPEDEF_A 
     # define TYPEDEF_A 
     typedef struct A A; 
 # endif 
 # ifndef TYPEDEF_A_CLASS 
     # define TYPEDEF_A_CLASS 
     typedef struct A_CLASS A_CLASS; 
 # endif 
 struct A_CLASS { 
     void * class__; 
     void ( * init ) ( A * ); 
 }; 
 struct A { 
     A_CLASS * class__; 
     int A0; 
 
 }; 
 static A_CLASS A_CLASS__ = {.class__ = NULL, .init = A_init, }; 
   
 # ifndef TYPEDEF_B 
     # define TYPEDEF_B 
     typedef struct B B; 
 # endif   
void B_init(B *);   
 # ifndef OOP_MEMBER_B 
     # define OOP_MEMBER_B( x ) x 
 # endif 
 # ifndef OOP_MEMBER_B_CLASS 
     # define OOP_MEMBER_B_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
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
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_B OOP_CLASS_G_HIER_A 
 # define OOP_CLASS_G_HIER_B B) OOP_CLASS_G_HIER_B_CLASS OOP_CLASS_G_PARENT_B 
 # define OOP_CLASS_G_PARENT_B_CLASS 
 # define OOP_CLASS_G_HIER_B_CLASS B_CLASS) OOP_CLASS_G_PARENT_B_CLASS 
 # define OOP_MEMBERS_G_B MEMBER_TYPE, (B_CLASS * class__;, B_CLASS *, class__, OOP_NO_DEFAULT, sizeof(B_CLASS *)) ) PARENT_TYPE, (A A__;, A, A__, (OOP_NO_DEFAULT), sizeof(A)) ) MEMBER_TYPE, (float B0;, float, B0, OOP_NO_DEFAULT, sizeof(float)) ) 
 # define OOP_MEMBERS_G_B_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_MEMBER_TYPE, (int n;, int, n, (0), sizeof(int)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( B * );, ftype_init_28, init, (B_init), sizeof(void *), typedef void ( * ftype_init_28 ) ( B * );) ) 
 
 # ifndef TYPEDEF_B 
     # define TYPEDEF_B 
     typedef struct B B; 
 # endif 
 # ifndef TYPEDEF_B_CLASS 
     # define TYPEDEF_B_CLASS 
     typedef struct B_CLASS B_CLASS; 
 # endif 
 struct B_CLASS { 
     void * class__; 
     int n; 
     void ( * init ) ( B * ); 
 }; 
 struct B { 
     B_CLASS * class__; 
     A A__; 
     float B0; 
 
 }; 
 static B_CLASS B_CLASS__ = {.class__ = NULL, .n = 0, .init = B_init, }; 
   
 # ifndef TYPEDEF_C 
     # define TYPEDEF_C 
     typedef struct C C; 
 # endif   
void C_init(C *);   
 # ifndef OOP_MEMBER_C 
     # define OOP_MEMBER_C( x ) x 
 # endif 
 # ifndef OOP_MEMBER_C_CLASS 
     # define OOP_MEMBER_C_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
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
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_C OOP_CLASS_G_HIER_A 
 # define OOP_CLASS_G_HIER_C C) OOP_CLASS_G_HIER_C_CLASS OOP_CLASS_G_PARENT_C 
 # define OOP_CLASS_G_PARENT_C_CLASS 
 # define OOP_CLASS_G_HIER_C_CLASS C_CLASS) OOP_CLASS_G_PARENT_C_CLASS 
 # define OOP_MEMBERS_G_C MEMBER_TYPE, (C_CLASS * class__;, C_CLASS *, class__, OOP_NO_DEFAULT, sizeof(C_CLASS *)) ) PARENT_TYPE, (A A__;, A, A__, (OOP_NO_DEFAULT), sizeof(A)) ) MEMBER_TYPE, (double C0;, double, C0, OOP_NO_DEFAULT, sizeof(double)) ) 
 # define OOP_MEMBERS_G_C_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( C * );, ftype_init_38, init, (C_init), sizeof(void *), typedef void ( * ftype_init_38 ) ( C * );) ) 
 
 # ifndef TYPEDEF_C 
     # define TYPEDEF_C 
     typedef struct C C; 
 # endif 
 # ifndef TYPEDEF_C_CLASS 
     # define TYPEDEF_C_CLASS 
     typedef struct C_CLASS C_CLASS; 
 # endif 
 struct C_CLASS { 
     void * class__; 
     void ( * init ) ( C * ); 
 }; 
 struct C { 
     C_CLASS * class__; 
     A A__; 
     double C0; 
 
 }; 
 static C_CLASS C_CLASS__ = {.class__ = NULL, .init = C_init, }; 
   
double size_t_to_dbl_x2p5(void * pD);   
 # ifndef TYPEDEF_D 
     # define TYPEDEF_D 
     typedef struct D D; 
 # endif   
void D_init(D *, int, float, double, size_t, int);   
 # ifndef OOP_MEMBER_D 
     # define OOP_MEMBER_D( x ) x 
 # endif 
 # ifndef OOP_MEMBER_D_CLASS 
     # define OOP_MEMBER_D_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
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
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_D0 
     # define OOP_MEMBER_D0( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_D OOP_CLASS_G_HIER_B OOP_CLASS_G_HIER_C 
 # define OOP_CLASS_G_HIER_D D) OOP_CLASS_G_HIER_D_CLASS OOP_CLASS_G_PARENT_D 
 # define OOP_CLASS_G_PARENT_D_CLASS OOP_CLASS_G_HIER_I 
 # define OOP_CLASS_G_HIER_D_CLASS D_CLASS) OOP_CLASS_G_PARENT_D_CLASS 
 # define OOP_MEMBERS_G_D MEMBER_TYPE, (D_CLASS * class__;, D_CLASS *, class__, OOP_NO_DEFAULT, sizeof(D_CLASS *)) ) PARENT_TYPE, (B B__;, B, B__, (OOP_NO_DEFAULT), sizeof(B)) ) PARENT_TYPE, (C C__;, C, C__, (OOP_NO_DEFAULT), sizeof(C)) ) MEMBER_TYPE, (size_t D0;, size_t, D0, OOP_NO_DEFAULT, sizeof(size_t)) ) 
 # define OOP_MEMBERS_G_D_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) INTERFACE_TYPE, (I I__;, I, I__, ({.to_dbl = size_t_to_dbl_x2p5, }), sizeof(I)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( D *, int, float, double, size_t, int );, ftype_init_51, init, (D_init), sizeof(void *), typedef void ( * ftype_init_51 ) ( D *, int, float, double, size_t, int );) ) 
 
 # ifndef TYPEDEF_D 
     # define TYPEDEF_D 
     typedef struct D D; 
 # endif 
 # ifndef TYPEDEF_D_CLASS 
     # define TYPEDEF_D_CLASS 
     typedef struct D_CLASS D_CLASS; 
 # endif 
 struct D_CLASS { 
     void * class__; 
     I I__; 
     void ( * init ) ( D *, int, float, double, size_t, int ); 
 }; 
 struct D { 
     D_CLASS * class__; 
     B B__; 
     C C__; 
     size_t D0; 
 
 }; 
 static D_CLASS D_CLASS__ = {.class__ = NULL, .I__ = {.to_dbl = size_t_to_dbl_x2p5, }, .init = D_init, }; 
   
