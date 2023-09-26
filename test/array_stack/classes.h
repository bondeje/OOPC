 # include <oopc.h> 
 # include <stdlib.h> 
 # include <stdio.h>   
 # ifndef TYPEDEF_array 
     # define TYPEDEF_array 
     typedef struct array array; 
 # endif   
void array_init(array *);   
 # ifndef OOP_MEMBER_array 
     # define OOP_MEMBER_array( x ) x 
 # endif 
 # ifndef OOP_MEMBER_array_CLASS 
     # define OOP_MEMBER_array_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_n 
     # define OOP_MEMBER_n( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
     # define OOP_MEMBER_size( x ) x 
 # endif 
 # ifndef OOP_MEMBER_arr 
     # define OOP_MEMBER_arr( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_array 
 # define OOP_CLASS_G_HIER_array array) OOP_CLASS_G_HIER_array_CLASS OOP_CLASS_G_PARENT_array 
 # define OOP_CLASS_G_PARENT_array_CLASS 
 # define OOP_CLASS_G_HIER_array_CLASS array_CLASS) OOP_CLASS_G_PARENT_array_CLASS 
 # define OOP_MEMBERS_G_array MEMBER_TYPE, (array_CLASS * class__;, array_CLASS *, class__, OOP_NO_DEFAULT, sizeof(array_CLASS *)) ) MEMBER_TYPE, (unsigned int n;, unsigned int, n, OOP_NO_DEFAULT, sizeof(unsigned int)) ) MEMBER_TYPE, (unsigned int size;, unsigned int, size, OOP_NO_DEFAULT, sizeof(unsigned int)) ) MEMBER_TYPE, (double arr[10];, double, arr, OOP_NO_DEFAULT, 10 * sizeof(double)) ) 
 # define OOP_MEMBERS_G_array_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( array * );, ftype_init_12, init, (array_init), sizeof(void *), typedef void ( * ftype_init_12 ) ( array * );) ) 
 
 # ifndef TYPEDEF_array 
     # define TYPEDEF_array 
     typedef struct array array; 
 # endif 
 # ifndef TYPEDEF_array_CLASS 
     # define TYPEDEF_array_CLASS 
     typedef struct array_CLASS array_CLASS; 
 # endif 
 struct array_CLASS { 
     void * class__; 
     void ( * init ) ( array * ); 
 }; 
 struct array { 
     array_CLASS * class__; 
     unsigned int n; 
     unsigned int size; 
     double arr[10]; 
 
 }; 
 static array_CLASS array_CLASS__ = {.class__ = NULL, .init = array_init, }; 
   
 # ifndef TYPEDEF_stack 
     # define TYPEDEF_stack 
     typedef struct stack stack; 
 # endif   
void stack_init(stack *);   
int push(stack * st, double val);   
int pop(double * val, stack * st);   
 # ifndef OOP_MEMBER_stack 
     # define OOP_MEMBER_stack( x ) x 
 # endif 
 # ifndef OOP_MEMBER_stack_CLASS 
     # define OOP_MEMBER_stack_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_array__ 
     # define OOP_MEMBER_array__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_push 
     # define OOP_MEMBER_push( x ) x 
 # endif 
 # ifndef OOP_MEMBER_pop 
     # define OOP_MEMBER_pop( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_stack OOP_CLASS_G_HIER_array 
 # define OOP_CLASS_G_HIER_stack stack) OOP_CLASS_G_HIER_stack_CLASS OOP_CLASS_G_PARENT_stack 
 # define OOP_CLASS_G_PARENT_stack_CLASS 
 # define OOP_CLASS_G_HIER_stack_CLASS stack_CLASS) OOP_CLASS_G_PARENT_stack_CLASS 
 # define OOP_MEMBERS_G_stack MEMBER_TYPE, (stack_CLASS * class__;, stack_CLASS *, class__, OOP_NO_DEFAULT, sizeof(stack_CLASS *)) ) PARENT_TYPE, (array array__;, array, array__, (OOP_NO_DEFAULT), sizeof(array)) ) 
 # define OOP_MEMBERS_G_stack_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( stack * );, ftype_init_26, init, (stack_init), sizeof(void *), typedef void ( * ftype_init_26 ) ( stack * );) ) CLASS_FUNCTION_TYPE, (int ( * push ) ( stack *, double );, ftype_push_27, push, (push), sizeof(void *), typedef int ( * ftype_push_27 ) ( stack *, double );) ) CLASS_FUNCTION_TYPE, (int ( * pop ) ( double *, stack * );, ftype_pop_28, pop, (pop), sizeof(void *), typedef int ( * ftype_pop_28 ) ( double *, stack * );) ) 
 
 # ifndef TYPEDEF_stack 
     # define TYPEDEF_stack 
     typedef struct stack stack; 
 # endif 
 # ifndef TYPEDEF_stack_CLASS 
     # define TYPEDEF_stack_CLASS 
     typedef struct stack_CLASS stack_CLASS; 
 # endif 
 struct stack_CLASS { 
     void * class__; 
     void ( * init ) ( stack * ); 
     int ( * push ) ( stack *, double ); 
     int ( * pop ) ( double *, stack * ); 
 }; 
 struct stack { 
     stack_CLASS * class__; 
     array array__; 
 
 }; 
 static stack_CLASS stack_CLASS__ = {.class__ = NULL, .init = stack_init, .push = push, .pop = pop, }; 
   
