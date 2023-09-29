#include <oopc.h>
#define OMIT_STRUCT_DECLS
#include <i.h>
#undef OMIT_STRUCT_DECLS
INCLUDE <i.h>
INCLUDE_OOPC

INCLUDE <stddef.h>

//typedef struct A A;
TYPEDEF(struct A, A)
void A_init(A *);

CLASS(A,\
    MEMBER(int, A0)\
    CLASS_FUNCTION(A_init, void, init, A *)
)

//typedef struct B B;
TYPEDEF(struct B, B)
void B_init(B *);

CLASS(B,
    EXTENDS(A)
    CLASS_MEMBER(int, n, 0)
    MEMBER(float, B0)
    CLASS_FUNCTION(B_init, void, init, B *)
)

//typedef struct C C;
TYPEDEF(struct C, C)
void C_init(C *);

CLASS(C,
    EXTENDS(A)
    MEMBER(double, C0)
    CLASS_FUNCTION(C_init, void, init, C *)
)

double size_t_to_dbl_x2p5(void * pD);

//typedef struct D D;
TYPEDEF(struct D, D)
void D_init(D *, int, float, double, size_t, int);

CLASS(D,
    EXTENDS(B)
    EXTENDS(C)
    CLASS_FUNCTION(D_init, void, init, D *, int, float, double, size_t, int)
    IMPLEMENTS(I, to_dbl, size_t_to_dbl_x2p5)
    MEMBER(size_t, D0)
)
