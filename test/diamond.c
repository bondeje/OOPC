#include <stdio.h>
#include "classes.h"

typedef void (*voidfpvoid)();
typedef void (*OOP_INIT_FUNCPTYPE_D)(D *, int, float, double, size_t);

void D_init(D * d, int A0, float B0, double C0, size_t D0) {
    d->class__ = &D_CLASS__; // TODO: if allowing an INIT in the class declaration, 

    printf("D0: %zu\nC_0: %.2f\nB0: %.2f\nA0: %d\n", D0, C0, B0, A0);

    // actual initializations
    OOP_GET(D, *d, A0) = A0;
    OOP_GET(D, *d, B0) = B0;
    OOP_GET(D, *d, C0) = C0;
    OOP_GET(D, *d, D0) = D0;
}

int main() {
    D D_;
    __INIT__(D)(&D_);
    //D_CLASS__.init = (voidfpvoid) D_init;
    //((OOP_INIT_FUNCPTYPE_D) __INIT__(D))(&D_, 1, 3.0, 4.0, 5);

    OOP_GET(D, D_, A0) = 1;
    OOP_GET(D, D_, B0) = 3.0;
    OOP_GET(D, D_, C0) = 4.0;
    OOP_GET(D, D_, D0) = 5;

    printf("D_.D0: %zu\nD_.C0: %.2f\nD_.B0: %.2f\nD_.A0: %d\n", OOP_GET(D, D_, D0), OOP_GET(D, D_, C0), OOP_GET(D, D_, B0), OOP_GET(D, D_, A0));    

    return 0;
}