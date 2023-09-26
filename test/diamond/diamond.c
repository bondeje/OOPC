#include <stdio.h>
#include "classes.h"

typedef void (*voidfpvoid)();
typedef void (*OOP_INIT_FUNCPTYPE_D)(D *, int, float, double, size_t);

double size_t_to_dbl_x2p5(void * pD) {
    printf("in size_t_to_dbl_x2p5\n");
    return 2.5*((double) OOP_GET(D, *(D *)pD, D0)); 
}

void A_init(A *a) {
    return;
}

void B_init(B *b) {
    A * a = &OOP_SUPER(B, *b);
    OOP_INIT(A, *a);
    OOP_GET(A, *a, init)(a);
}

void C_init(C *c) {
    A * a = &OOP_SUPER(C, *c);
    OOP_INIT(A, *a);
    OOP_GET(A, *a, init)(a);
}

void D_init(D * d, int A0, float B0, double C0, size_t D0, int n) {
    B * b = &OOP_SUPER(D, *d, B);
    OOP_INIT(B, *b);
    OOP_GET(B, *b, init)(b);
    C * c = &OOP_SUPER(D, *d, C);
    OOP_INIT(C, *c);
    OOP_GET(C, *c, init)(c);

    //printf("D0: %zu\nC_0: %.2f\nB0: %.2f\nA0: %d\nn: %d\n", D0, C0, B0, A0, n);

    // actual initializations
    OOP_GET(D, *d, A0) = A0;
    OOP_GET(D, *d, B0) = B0;
    OOP_GET(D, *d, C0) = C0;
    OOP_GET(D, *d, D0) = D0;
    OOP_GET(D, *d, n) = n;
}

int main() {
    OOP_DECLARE(D, D_);
    //OOP_INIT(B, OOP_SUPER(D, D_, B));
    //OOP_INIT(C, OOP_SUPER(D, D_, C));
    printf("size of A: %zu\nsize of B: %zu\nsize of C: %zu\nsize of D: %zu\n", sizeof(A), sizeof(B), sizeof(C), sizeof(D));
    
    
    printf("D_.D0: %zu\nD_.C0: %.2f\nD_.B0: %.2f\nD_.A0: %d\n", OOP_GET(D, D_, D0), OOP_GET(D, D_, C0), OOP_GET(D, D_, B0), OOP_GET(D, D_, A0));    
    // crashes because D_.B__.class__ is not initialized until OOP_INIT(B, [instance of B belonging to D is initialized]) is called
    //printf("D_.n: %d\n", OOP_GET(D, D_, n));
    OOP_GET(D, D_, init)(&D_, 1, 3.0, 4.0, 5, 2);

    printf("D_.D0: %zu\nD_.C0: %.2f\nD_.B0: %.2f\nD_.A0: %d\n", OOP_GET(D, D_, D0), OOP_GET(D, D_, C0), OOP_GET(D, D_, B0), OOP_GET(D, D_, A0));    
    printf("D_.n: %d\n", OOP_GET(D, D_, n));

    printf("D_.to_dbl() = %.2f\n", OOP_INTERFACE(D, D_, I).to_dbl(&D_));

    return 0;
}