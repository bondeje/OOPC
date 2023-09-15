// defs.h
#include <oop.h>
INCLUDE_OOP

// builds a struct 'array' with a double array of size 10, 'arr' with 10 stored in member 'n' and current size in size
CLASS(array, 
    MEMBER(unsigned int, n)
    MEMBER(unsigned int, size)
    MEMBER(double, arr, 10)
)

typedef struct stack stack;

// returns 0 if successful, 1 if stack is full
int push(stack * st, double val);
int pop(double * val, stack * st);

// builds a struct 'stack' that inherits from 'array' and additionally includes functions/methods push and pop. The first NULL values are used for initialization and can be modified at any time.
CLASS(stack,
    PARENT(array)
    CLASS_FUNCTION(push, int, push, stack *, double)
    CLASS_FUNCTION(pop, int, pop, double *, stack *)
)