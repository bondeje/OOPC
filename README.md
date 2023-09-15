# OOPC

This is largely a set of macros and meta data structures written in the C preprocessor to generate boiler plate code to facilitate the creation of a "class" system to fake object-oriented programming. Different from other implementations I have seen is that I entirely use C preprocessor and a very small OS-dependent script generate valid C header files. No additional tools. Additionally, OOPC has multiple inheritance and does so without any upcasting/downcasting or having to do tricky pointer offsets.

## how to use it

- build a class definition header file using the `oop.h` macros that has `INCLUDE_OOP` at the top
- pre-process the definition header file and store it in another header file. This is the file you will actually include in your `.c` files or other dependent header files.
- before using the header file you just built, pass it through a script to replace "OOP_NEWLINE" with a new line and OOP_TAB to your preferred number of spaces or tabs. You also can just define the macro `#define OOP_TAB` to remove them if you do not care.
- in your dependent files, simply include the header file just built

Example class definition:
```
// class_definitions.h
INCLUDE OOP

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

// arrays_stacks.c
#include "arrays_stacks.h"
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

// class_definitions.h pre-processed to file 'arrays_stacks.h'

// main.c
#include <stdio.h>
#include "arrays_stacks.h"

int main() {    
    stack st;
    __INIT__(stack)(&st);
    OOP_GET(stack, st, n) = 10; // still necessary. Will overload init later

    for (unsigned int i = 0; i < 11; i++) {
        printf("result of push at %u: %d\n", OOP_GET(stack, st, push)(&st, 1.0 * i));
    }

    return 0;
}

/* prints
0
0
0
0
0
0
0
0
0
0
1
```

Note that the way CLASS_FUNCTIONS have to be created later and assigned will be changed.

Full documentation is forthcoming, but for now, you can follow the diamond example in `/test/` which has class definitions in `defs.h` and an application of the diamond problem in `diamond.c`. The code defines 4 classes in the standard configuration To build on Windows with `make`, simply call `make -f make_diamond.mak` from the `/test/` directory and run. 

## dependencies

Currently it will only work with GCC and on Windows (tested with MINGW64 on MSYS2), but the only real requirements are

- gcc, clang, or any c compiler with C99-compliant preprocessor that ALSO expands re-entrant macros iteratively. The last part being non-standard, but is widely adopted. Note that tcc will expand, but probably does it recursively and so these headers can break
- A shell script that replaces "OOP_NEWLINE" and "OOP_TAB" with the appropriate newline characters and spaces/tabs. The latter is so that the resulting headers are not garbage to look at, but the replacement of "OOP_NEWLINE" is essential to functionality. Unfortunately, a separate pass is needed because C preprocessors do not have facilities to introduce newlines, which is required to have a preprocessor output have valid directives