#include <oop.h>

INCLUDE_OOP

CLASS(A,\
MEMBER(int, A0)\
)

CLASS(B,\
PARENT(A)\
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
/*
CLASS(D,\
PARENT(B)\
PARENT(C)\
CLASS_FUNCTION(NULL, void, init, double *, char)\
CLASS_MEMBER(0, size_t, n)\
CLASS_MEMBER("what", char, buf, 128)\
FUNCTION(double, process, A *, unsigned int)\
MEMBER(int, x)\
MEMBER(int, vertices, 4)\
)
*/