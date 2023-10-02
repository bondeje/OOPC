# OOPC

OOPC (read: "oopsie") is a framework consisting of a set of macro header files and meta data structures written in the C preprocessor. Combined, they generate boiler plate code facilitating the creation of a "type" system for object-oriented programming in the C language. Different from other implementations of OOP in C I have seen is that the only non-C standard components used are macro iterations (widely implemented in C compilers) and a simple script to insert newlines. The outputs are standard C (C99+) header files/code. No external tooling. 

OOPC has multiple inheritance and interfaces for polymorphism, which is implemented without any upcasting/downcasting or having to do tricky pointer offsets. Type safety is provided up until the point most of the interfaces are implemented by a user as polymorphism ultimately needs some generic objects. For full type safety, the macros can be wrapped to form primitive templates, but as of now, construction of templates may be tedious and error-prone.

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
DECLARE(ObjToCall, obj)
/* init obj code however you wish */
CALL(ObjToCall, obj, arguments...);  // "calls" the object

```

</blockquote></details>

<details><summary> Templating </summary><blockquote>

Templates are a big part of C++ and it is natural to want flexibility and configurability while maintaining type safety. Since macros can parameterize other macros, OOPC can also do templating although it can be unwieldy and require use of a lot of internal macros.

A simple example is if you wanted to create interfaces for general array types. These would be structs that look something like

```
struct array_int {
    size_t capacity;    // number of elements allocated for arr
    size_t size;        // number of elements current written to arr
    int * arr;          // array of integers
}
```

or 

```
struct array_double {
    size_t capacity;    // number of elements allocated for arr
    size_t size;        // number of elements current written to arr
    double * arr;       // array of integers
}
```

For type safety, we would want access to both, but we might also have functions that we might want to accept multiple array types, e.g. comparing two elements or getting their respective sizes. How to handle this? We can use interfaces to implement shared functionality or inheritance to give each typed array access to shared members or in probably in this case, both. Class extension or inheritance works well for the parts of these structs that are common, namely the members `capacity` and `size`. When we need to pass the objects into functions that accept either, however, the superclass doesn't know anything about the contents of the subclass and should not be responsible for maintaining any (type) safety or invariants. The key to the latter points then is to implement a shared interface. This interface can be passed along with a generic object to provide specificity and a context for an operation that is shared among the objects, but different. Templating can help use define these interfaces and subclasses.

So how do we create class templates to accommodate all our potential arrays? Well, first look at how we would construct each of these structs individually in OOPC.

```
// compare elements of an int array of size n at indices i and j
int array_int_compare(array_int * iarr, size_t i, size_t j);
size_t array_int_size(array_int * iarr);
CLASS(array_int,
    MEMBER(size_t, capacity)
    MEMBER(size_t, size)
    MEMBER(int *, arr)
    CLASS_FUNCTION(array_int_compare, int, compare, array_int *, size_t, size_t)
    CLASS_FUNCTION(array_int_size, size_t, size, array_int *)
)

int array_double_compare(array_double * darr, size_t i, size_t j);
size_t array_double_size(array_double * darr);
CLASS(array_double,
    MEMBER(size_t, capacity)
    MEMBER(size_t, size)
    MEMBER(double *, arr)
    CLASS_FUNCTION(array_double_compare, int, compare, array_double *, size_t, size_t)
    CLASS_FUNCTION(array_double_size, size_t, size, array_double *)
)
```

When members are shared, that generally means the base class should contain those members. When class members are shared, that generally means the interface should contain those members. And since we are templating away the type of the elements in the array, the type of the `arr` members needs to be templated, but where to put it? There are actually a few ways to do this in OOPC, but we'll go with the one that has a little more type safety (generics in C will always have some amount of type "un"-safety unless we are allowed to have C11 or never with `_Generic` selection). There is also a very efficient way to define the interface and class at the same time, but we will be a little more explicit here (and use fewer internal macros).

To indicate templating, we will use `##template_parameter` to indicate that template_parameter will be something our template has to handle. Our base class will look like

```
// declare base class
CLASS(array,
    MEMBER(size_t, capacity)
    MEMBER(size_t, size)
)
// declare template using generic objects for heterogenous types
CLASS(array_intf, 
    FUNCTION(NULL, int, compare, void *, size_t, size_t)
    FUNCTION(NULL, size_t, size, void *)
)
```

and we have to have declarations/definitions for each of the interface functions

Then our template will look like the following

```
#define TEMPLATE_ARRAY(type) \
TYPEDEF(struct array_##type, array_##type) \
int array_##type##_compare(void * arr, size_t i, size_t j); \
size_t array_##type##_size(void * arr); \
CLASS(array_##type, \
    EXTENDS(array) \
    MEMBER(type *, arr) \
    IMPLEMENTS(array_intf, compare, array_##type##_compare, size, array_##type##_size) \
)
```

Once we have .c files with the implementations of each interface function, we are almost completely done. The declarations for `array`, `array_intf`, and the `TEMPLATE_ARRAY(type)` macro would go into a `array.def.h` header file that would get converted to array.h for the base class. In either the same file or separate files for each type (for the later, they would also have to be `*.def.h` files that include `array.def.h`) all that one needs to do to declare a new array type is to call the `TEMPLATE_ARRAY()` macro:

```
TEMPLATE_ARRAY(int)
TEMPLATE_ARRAY(double)
TEMPLATE_ARRAY(long)
```

A few notes:
- The way we templated the types with macro concatenation means the types themselves must be valid identifiers, which would restrict us to non-pointer types and built-in types that are single words. This can be worked-around with a simple typedef to unify multi-word types (ex. long long -> llong) and pointers (double * -> pdouble).
- Since we are already putting `TEMPLATE_ARRAY()` in a .def.h file, which gets pre-processed 2x, we can actually have `TEMPLATE_ARRAY()` emit macros that include the templated implementations of the interface functions! This reduces the implementation of each array type to as little as a single (albet borderline unreadable) line...but that's some macro trickery that won't be expounded on here.

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

## High-level TODOs

- Implement default initializations for interfaces and classes. Right now, you can set "values" for functions in interfaces and classes when you declare them, but there is still no connection when they are implemented or inherited to receive those functions if none are explicitly overriden.
- Inheritance graph searches proceed in depth-first left-right order for multiple inheritance. This produces problems--at least perceived but I would describe as un-intended--especially in the [Diamond problem](https://peps.python.org/pep-0253/). The plan is to first implement an explicit inheritance graph navigation to OOP_GET so that explicit routes or guidance can be taken to retrieve a member. When I figure out how to implement [C3 linearization](https://en.wikipedia.org/wiki/C3_linearization), that will supersede the depth-first left-right methodology. As long as the diamond problem is avoided or explicit paths are given when using OOP_GET, this will not break behavior. Thankfully, I have not decided to go the Python path where everything is an object and everything inherits from object, which guarantees the issues in the PEP-253 Diamond problem. 
- replace the scripts with a separate programe. This would make the order of operations a little complicated as a separate binary would need to be built to build the actual project, but would eliminate OS-dependent scripts and maybe even allow for use with non-hosted environments, though I already know `string.h` missing will be an issue.
- Interfaces currently require extensive use of `void *` to stand in for arbitrary objects. It is possible with the current implementation to template interfaces and specify the types in these cases (and fully make this OOP methodology type-safe), but a standard method for referring to those template instances with a common interface name (otherwise they would be pretty bad interfaces) is missing and needs development.