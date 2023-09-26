 # include <oopc.h> 
 # include <stdlib.h> 
   
 # include <stdio.h>   
 # include <string.h>   
 # define MAX_BUFFER_LENGTH 1024   
 # ifndef TYPEDEF_buffer 
     # define TYPEDEF_buffer 
     typedef struct buffer buffer; 
 # endif   
void buffer_init(buffer * b, char * c_str);   
int buffer_print(buffer * b);   
int buffer_append(buffer * b, buffer * to_append);   
 # ifndef OOP_MEMBER_buffer 
     # define OOP_MEMBER_buffer( x ) x 
 # endif 
 # ifndef OOP_MEMBER_buffer_CLASS 
     # define OOP_MEMBER_buffer_CLASS( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_class__ 
     # define OOP_MEMBER_class__( x ) x 
 # endif 
 # ifndef OOP_MEMBER_size 
     # define OOP_MEMBER_size( x ) x 
 # endif 
 # ifndef OOP_MEMBER_buf 
     # define OOP_MEMBER_buf( x ) x 
 # endif 
 # ifndef OOP_MEMBER_init 
     # define OOP_MEMBER_init( x ) x 
 # endif 
 # ifndef OOP_MEMBER_print 
     # define OOP_MEMBER_print( x ) x 
 # endif 
 # ifndef OOP_MEMBER_append 
     # define OOP_MEMBER_append( x ) x 
 # endif 
 
 # define OOP_CLASS_G_PARENT_buffer 
 # define OOP_CLASS_G_HIER_buffer buffer) OOP_CLASS_G_HIER_buffer_CLASS OOP_CLASS_G_PARENT_buffer 
 # define OOP_CLASS_G_PARENT_buffer_CLASS 
 # define OOP_CLASS_G_HIER_buffer_CLASS buffer_CLASS) OOP_CLASS_G_PARENT_buffer_CLASS 
 # define OOP_MEMBERS_G_buffer MEMBER_TYPE, (buffer_CLASS * class__;, buffer_CLASS *, class__, OOP_NO_DEFAULT, sizeof(buffer_CLASS *)) ) MEMBER_TYPE, (int size;, int, size, OOP_NO_DEFAULT, sizeof(int)) ) MEMBER_TYPE, (char buf[MAX_BUFFER_LENGTH];, char, buf, OOP_NO_DEFAULT, MAX_BUFFER_LENGTH * sizeof(char)) ) 
 # define OOP_MEMBERS_G_buffer_CLASS CLASS_MEMBER_TYPE, (void * class__;, void *, class__, (NULL), sizeof(void *)) ) CLASS_FUNCTION_TYPE, (void ( * init ) ( buffer *, char * );, ftype_init_13, init, (buffer_init), sizeof(void *), typedef void ( * ftype_init_13 ) ( buffer *, char * );) ) CLASS_FUNCTION_TYPE, (int ( * print ) ( buffer * );, ftype_print_14, print, (buffer_print), sizeof(void *), typedef int ( * ftype_print_14 ) ( buffer * );) ) CLASS_FUNCTION_TYPE, (int ( * append ) ( buffer *, buffer * );, ftype_append_15, append, (buffer_append), sizeof(void *), typedef int ( * ftype_append_15 ) ( buffer *, buffer * );) ) 
 
 # ifndef TYPEDEF_buffer 
     # define TYPEDEF_buffer 
     typedef struct buffer buffer; 
 # endif 
 # ifndef TYPEDEF_buffer_CLASS 
     # define TYPEDEF_buffer_CLASS 
     typedef struct buffer_CLASS buffer_CLASS; 
 # endif 
 struct buffer_CLASS { 
     void * class__; 
     void ( * init ) ( buffer *, char * ); 
     int ( * print ) ( buffer * ); 
     int ( * append ) ( buffer *, buffer * ); 
 }; 
 struct buffer { 
     buffer_CLASS * class__; 
     int size; 
     char buf[MAX_BUFFER_LENGTH]; 
 
 }; 
 static buffer_CLASS buffer_CLASS__ = {.class__ = NULL, .init = buffer_init, .print = buffer_print, .append = buffer_append, }; 
   
