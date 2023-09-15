// main.c
#include <stdio.h>
#include "classes.h"

int main() {    
    stack st;
    __INIT__(stack)(&st);
    OOP_GET(stack, st, n) = 10; // still necessary. Will overload init later
    OOP_GET(stack, st, push) = push;
    OOP_GET(stack, st, pop) = pop;

    for (unsigned int i = 0; i < 11; i++) {
        printf("result of push at %u: %d\n", i, OOP_GET(stack, st, push)(&st, 1.0 * i));
    }

    return 0;
}