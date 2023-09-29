// main.c
#include <stdio.h>
#include <math.h>
#include "classes.h"

int main() {    
    OOP_DECLARE(stack, st);
    OOP_GET(stack, st, init)(&st);

    for (unsigned int i = 0; i < 11; i++) {
        printf("result of push at %u: %d\n", i, OOP_GET(stack, st, push)(&st, 1.0 * i));
    }
    
    for (unsigned int i = 0; i < 11; i++) {
        double d = NAN;
        unsigned int result = OOP_GET(stack, st, pop)(&d, &st);
        printf("result of pop at %u: %d (%f)\n", i, result, d);
    }

    return 0;
}