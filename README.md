# OOPC

OOPC (read: "oopsie") is a set of macro header files and meta data structures written in the C preprocessor to generate boiler plate code to facilitate the creation of a "type" system for object-oriented programming in the C language. Different from other implementations I have seen is that the only non-C standard component used is a simple script to add newlines. The outputs are standard C header files/code. No additional tools. Additionally, OOPC has multiple inheritance and distinct interfacing and does so without any upcasting/downcasting or having to do tricky pointer offsets.

## Potential and Applied Concepts

<details><summary> Callable objects </summary><blockquote>

The `callable.def.h` file creates a callable object struct and associated macros that allow a user to implement an interface for another struct to be "callable". "Callable" here means there is a one-to-one association of the object to a function. In Python, this simply looks like 
```
class ObjToCall:
    def __call__(self, ...):
        # implementation

# to use
A = ObjToCall()
result = A() # "calls" the object
```

Since in pure C, we cannot make a struct executable, we cannot make the syntax work this simply, but we can get kind of close. The analogous behavior in OOPC is
```
// ObjToCall.def.h
TYPEDEF(struct ObjToCall, ObjToCall)
return_type my_func(ObjToCall *, other args...); // the function I want to call when "calling" the instance of ObjToCall. Implementation in some .c file

// if my_func returns void and the "other args" is actually a variadic, done. Otherwise, have wrap the function with the MAKE_CALLABLE macro
// define the class if my_func did not require MAKE_CALLABLE() macro
CLASS(ObjToCall,
    /* class declarations */
    IMPLEMENTS(Callable, call, my_func)
)

// else if MAKE_CALLABLE() macro was required
MAKE_CALLABLE(ObjToCall, return_type, my_func, other arg types...)
CLASS(ObjToCall,
    /* class declarations */
    IMPLEMENTS(Callable, call, GET_CALLABLE(ObjToCall, my_func))
)

// to use
DECLARE(ObjToCall, obj);
CALL(ObjToCall, obj, arguments...);  // "calls" the object

```

</blockquote></details>

## Documentation

<details><summary> Documentation </summary><blockquote>

<b>Public Macro Overview</b>

Reading the table, some general behavior/definitions:
- macro arguments in `[]` are options 
- as a general rule in this framework, types include all pointer de-referencing, e.g. the `type` of a double pointer is `double *`
- `array size`s are number of elements, not bytes
- `name`s must be valid identifiers
- `value`s should be in parentheses to avoid any commas being interpreted as arguments
- members are the name parts of a `struct`. MEMBER in the macro names generally refer to objects with a slight distinction for function objects in FUNCTION.
- opaque data types can be made in this framework, but then `OOP_GET`, `OOP_INTERFACE`, and `OOP_SUPER` will only work in files that have visibility to the type definitions. To implement oqaque data types, wrapper functions must be made for these macros.

| Macro | Description | Relationship to Class | Relationship to Instances | Implementation Status |
|-------|-------------|-----------------------|---------------------------|-----------------------|
| `CLASS(type, description)` | defines a `type` by its class and instances | defines the class | defines the instances | Done |
| *`MEMBER(type, name[, value])` | declare an instance member | N/A | Each instance struct has a member of `type` with `name` and default `value` | default values not yet implemented |
| *`ARRAY_MEMBER(type, name[, value], array size)` | declare an instance member array | N/A | Each instance struct has an array of `array size` members of `type` with `name` and default `value` | default values not yet implemented |
| *,**`FUNCTION(value, return type, name, arg types...)` | declare an instance member function | N/A | Each instance struct has a member function with `name` that takes `arg types` inputs and `return type` | default values not yet implemented |
| *`CLASS_MEMBER(type, name[, value])` | declare a class member | The class struct has a member of `type` with `name` and default `value` | N/A | default values not yet implemented |
| *`ARRAY_CLASS_MEMBER(type, name[, value], array size)` | declare a class member array | The class struct has an array of `array size` members of `type` with `name` and default `value` | N/A  | default values not yet implemented |
| *,**`CLASS_FUNCTION(value, return type, name, arg types...)` | declare a class member function | The class struct has a member function with `name` that takes `arg types` inputs and `return type` | N/A | default values not yet implemented |
| *`EXTENDS(type)` | inherit from `type` | N/A | creates a "has a" sub-typing relationship in the hierarchy between the current type's instance and `type`*** | Done |
| *`IMPLEMENTS(type[, interface function name, implementation name...pairs])` | implement interface `type` | creates a "has a" sub-typing relationship in the hierarchy between the current type's class and `type`*** | N/A | Done |
| `OOP_SUPER(type, instance[, parent])` | resolve the `instance` as its `parent` based on the `type` definition | N/A | `type` was defined with `EXTENDS(parent)` | Done |
| `OOP_INTERFACE(type, instance[, interface])` | resolve the `instance` by its implementation of `interface` based on the `type` definition | `type` as defined with `IMPLEMENTS(interface[, pairs of interface functions and their implementations])` | Done |
| `OOP_GET(type, instance, attribute)` | resolve the `attribute` member of `instance` based on the `type` definition <br /> used for both "getting" and "setting" | N/A | class members are searched after instance members but the class hierarchy is searched before the instance hierarchy | Done |
| `OOP_INIT(type, inst)` | initialize an instance | N/A | initializes the instance by linking it to its class definition <br /> This should only be used directly when initializing supertype instances, i.e. when writing initialization functions for children | Done, but will expand to `do {} while (0)` in the future |
| `OOP_DECLARE(type, inst)` | declare an instance of `type` | N/A | declare and partially initialize an instance | Done, but will be unnecessary when OOP_INIT is "fixed" |
| `TYPEDEF(type, alias)` | protected `typedef type alias` to prevent conflicts with C typedef restrictions | N/A | N/A | Done |

*Only used within `description of `CLASS` macro

**FUNCTIONs are treated as and can be declared as MEMBERs (as they are members of `struct`s!). FUNCTION is merely a convenience to also wrap boiler plate code for establishing types based on the function specification. To have a MEMBER that is a function object, the appropriate typedef needs to be manually set beforehand. Doing so probably results in more type-safe use of function members.

***See "Is-a vs. Has-a, Extends vs Implements, Sub-class vs Interface" (in progress)

</blockquote></details>

### How to use OOPC

- build a class definition header file using the `oopc.h` header macros in the table above that has `INCLUDE_OOPC` at the top
- pre-process the definition header file and store it in another header file. This is the file you will actually include in your `.c` files or other dependent header files.
    - examples use gcc with flags `-E -P`
- before using the header file you just built, pass it through a script to replace "OOP_NEWLINE" with a new line and OOP_TAB to your preferred number of spaces or tabs. You also can just define the macro `#define OOP_TAB` to remove them if you do not care.
- in your dependent files, simply include the header file just built
    - compile with whatever C compiler you want. The resulting headers from base OOPC only requires a C99 compliant compiler

#### Example class definition:

Build a struct to represent a `char` buffer with max width 1024 including the `\0` terminator.
```
// defs.h converted to buffer.h
#include <oopc.h>
INCLUDE_OOP
INCLUDE <stdio.h>
INCLUDE <string.h>
DEFINE MAX_BUFFER_LENGTH 1024
TYPEDEF(struct buffer, buffer)
void buffer_init(buffer * b, char * c_str);
int buffer_print(buffer * b);
int buffer_append(buffer * b, buffer * to_append);
CLASS(buffer, 
    MEMBER(int, size)
    ARRAY_MEMBER(char, buf, MAX_BUFFER_LENGTH)
    CLASS_FUNCTION(buffer_init, void, init, buffer *, char *)
    CLASS_FUNCTION(buffer_print, int, print, buffer *)
    CLASS_FUNCTION(buffer_append, int, append, buffer *, buffer *)
)

// buffer.c
#include "buffer.h"
void buffer_init(buffer * b, char * c_str) {
    char * buf = OOP_GET(buffer, *b, buf);
    if (c_str) {
        OOP_GET(buffer, *b, size) = strlen(c_str);
        while (*c_str != '\0') {
            *buf = *c_str;
            c_str++;
            buf++;
        }
    } else {
        OOP_GET(buffer, *b, size) = 0;
    }
    *buf = '\0';
    
}

int buffer_print(buffer * b) {
    return printf((const char *) OOP_GET(buffer, *b, buf));
}

int buffer_append(buffer * b, buffer * to_append) {
    if (MAX_BUFFER_LENGTH <= OOP_GET(buffer, *b, size) + OOP_GET(buffer, *to_append, size)) {
        return 0; // no characters written to b
    }
    char * b1 = OOP_GET(buffer, *b, buf) + OOP_GET(buffer, *b, size); // point to end of buffer
    char * b2 = OOP_GET(buffer, *to_append, buf);
    while (*b2 != '\0') {
        *b1 = *b2;
        b2++;
        b1++;
    }
    *b1 = '\0';
    OOP_GET(buffer, *b, size) += OOP_GET(buffer, *to_append, size);
    return OOP_GET(buffer, *to_append, size);
}

// main.c
#include "buffer.h"

#include "buffer.h"

int main(int argc, char ** args) {
    if (argc > 2) {
        OOP_DECLARE(buffer, b1);
        OOP_GET(buffer, b1, init)(&b1, args[1]);
        OOP_DECLARE(buffer, b2);
        OOP_GET(buffer, b2, init)(&b2, args[2]);

        if (OOP_GET(buffer, b1, append)(&b1, &b2)) {
            printf("successfully concatenated two buffers:\n");
            OOP_GET(buffer, b1, print)(&b1);
        } else {
            printf("insufficient buffer space to concatenate two buffers:\n");
            OOP_GET(buffer, b1, print)(&b1);
            printf("\n");
            OOP_GET(buffer, b2, print)(&b2);
        }
        printf("\n");
    }
    return 0;
}


```

Full documentation is forthcoming, but for now, you can follow the diamond example in `/test/` which has class definitions in `defs.h` and an application of the diamond problem in `diamond.c`. The code defines 4 classes in the standard configuration To build on Windows with `make`, simply call `make -f make_diamond.mak` from the `/test/` directory and run. 

## dependencies

Currently it will only work with GCC and on Windows (tested with MINGW64 on MSYS2), but the only real requirements are

- gcc, clang, or any c compiler with C99-compliant preprocessor that ALSO expands re-entrant macros iteratively. The last part being non-standard, but is widely adopted. Note that tcc will expand, but probably does it recursively and so these headers can break
- A shell script that replaces "OOP_NEWLINE" and "OOP_TAB" with the appropriate newline characters and spaces/tabs. The latter is so that the resulting headers are not garbage to look at, but the replacement of "OOP_NEWLINE" is essential to functionality. Unfortunately, a separate pass is needed because C preprocessors do not have facilities to introduce newlines, which is required to have a preprocessor output have valid directives