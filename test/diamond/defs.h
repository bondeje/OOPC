#include <oopc.h>

INCLUDE_OOP

CLASS(I,
    FUNCTION(NULL, double, to_dbl, void *)
)

CLASS(A,\
    MEMBER(int, A0)\
)

CLASS(B,\
    EXTENDS(A)\
    CLASS_MEMBER(int, n, 0)\
    MEMBER(float, B0)\
)

CLASS(C,\
    EXTENDS(A)\
    MEMBER(double, C0)\
)

double size_t_to_dbl_x2p5(void * pD);

CLASS(D,\
    EXTENDS(B)
    EXTENDS(C)
    IMPLEMENTS(I, to_dbl, size_t_to_dbl_x2p5)
    MEMBER(size_t, D0)
)
