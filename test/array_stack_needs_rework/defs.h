// defs.h
#include <oopc.h>
INCLUDE_OOPC

// builds a struct 'array' with a double array of size 10, 'arr' with 10 stored in member 'n' and current size in size
TYPEDEF(struct array, array)
void array_init(array *);
CLASS(array, 
    MEMBER(unsigned int, n)
    MEMBER(unsigned int, size)
    ARRAY_MEMBER(double, arr, 10)
    CLASS_FUNCTION(array_init, void, init, array *)
)
//

TYPEDEF(struct stack, stack)

void stack_init(stack *);
// returns 0 if successful, 1 if stack is full
int push(stack * st, double val);
int pop(double * val, stack * st);

// builds a struct 'stack' that inherits from 'array' and additionally includes functions/methods push and pop. The first NULL values are used for initialization and can be modified at any time.
CLASS(stack,
    EXTENDS(array)
    CLASS_FUNCTION(stack_init, void, init, stack *)
    CLASS_FUNCTION(push, int, push, stack *, double)
    CLASS_FUNCTION(pop, int, pop, double *, stack *)
)
//