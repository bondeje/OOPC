// arrays_stacks.c
#include <stdio.h>
#include "classes.h"

void array_init(array * ar) {
    ar->n = 10;
    ar->size = 0;
    for (unsigned int i = 0; i < ar->n; i++) {
        ar->arr[i] = 0.0;
    }
}

void stack_init(stack * st) {
    array * ar = &OOP_SUPER(stack, *st, array);
    OOP_INIT(array, *ar);
    OOP_GET(array, *ar, init)(ar);
}

// returns 0 if successful, 1 if stack is full
int push(stack * st, double val) {
    if (OOP_GET(stack, *st, size) < OOP_GET(stack, *st, n)) {
        OOP_GET(stack, *st, arr)[OOP_GET(stack, *st, size)++] = val;
        
        return 0;
    }
    return 1;
}

// return 0 if successful, 1 if stack is empty
int pop(double * out, stack * st) {
    if (OOP_GET(stack, *st, size)) {
        *out = OOP_GET(stack, *st, arr)[--OOP_GET(stack, *st, size)];
        return 0;
    }
    return 1;
}