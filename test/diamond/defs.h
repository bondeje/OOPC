#include <oop.h>

INCLUDE_OOP

CLASS(A,\
MEMBER(int, A0)\
)

CLASS(B,\
PARENT(A)\
CLASS_MEMBER(0, int, n)\
MEMBER(float, B0)\
)

CLASS(C,\
PARENT(A)\
MEMBER(double, C0)\
)

CLASS(D,\
PARENT(B)
PARENT(C)
MEMBER(size_t, D0)
)
