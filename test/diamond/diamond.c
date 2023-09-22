#include <stdio.h>
#include "classes.h"

typedef void (*voidfpvoid)();
typedef void (*OOP_INIT_FUNCPTYPE_D)(D *, int, float, double, size_t);

double size_t_to_dbl_x2p5(void * pD) {
    printf("in size_t_to_dbl_x2p5\n");
    return 2.5*((double) OOP_GET(D, *(D *)pD, D0)); 
}

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
    printf("D_.D0: %zu\nD_.C0: %.2f\nD_.B0: %.2f\nD_.A0: %d\n", OOP_GET(D, D_, D0), OOP_GET(D, D_, C0), OOP_GET(D, D_, B0), OOP_GET(D, D_, A0));    
    printf("D_.B__.class__->n: %d\n", OOP_GET(D, D_, n));
    
    OOP_GET(D, D_, A0) = 1;
    OOP_GET(D, D_, B0) = 3.0;
    OOP_GET(D, D_, C0) = 4.0;
    OOP_GET(D, D_, D0) = 5;
    OOP_GET(D, D_, n) = 2;

    printf("D_.D0: %zu\nD_.C0: %.2f\nD_.B0: %.2f\nD_.A0: %d\n", OOP_GET(D, D_, D0), OOP_GET(D, D_, C0), OOP_GET(D, D_, B0), OOP_GET(D, D_, A0));    
    printf("D_.B__.class__->n: %d\n", OOP_GET(D, D_, n));

    printf("D_.class__.I__.to_dbl() = %.2f\n", OOP_INTERFACE(D, D_, I).to_dbl(&D_));

    return 0;
}