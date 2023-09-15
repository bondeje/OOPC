// arrays_stacks.c
#include "classes.h"
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